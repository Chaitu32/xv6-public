#include "types.h"
#include "user.h"

int number_of_processes = 10;

int main(int argc, char *argv[])
{
  int stime = uptime();
  int j;
  for (j = 0; j < number_of_processes; j++)
  {
    int pid = fork();
    if (pid < 0)
    {
      printf(1, "Fork failed\n");
      continue;
    }
    if (pid == 0)
    {
      volatile int i;
      for (volatile int k = 0; k < number_of_processes; k++)
      {
        if (k <= j)
        {
          sleep(200); //io time
        }
        else
        {
          int x=0;
          for (i = 0; i < 100000000; i++)
          {
            x=x*2+(x*x)%7*7; //cpu time
          }
        }
      }
      printf(1, "Process: %d Finished\n", getpid());
      exit();
    }
    else{
      printf(1, "Process: %d Started\n", pid);
      set_priority(100-(20+j),pid); // will only matter for PBS, comment it out if not implemented yet (better priorty for more IO intensive jobs)
    }
  }
  int w_totime=0,last_rtime=0;
  for (j = 0; j < number_of_processes+5; j++)
  {
    int wtime,rtime;
    waitx(&wtime,&rtime);
    w_totime+=wtime;
    last_rtime = rtime;
  }
  int etime = uptime();
  printf(1,"Total wait time by waitx %d\n",w_totime+last_rtime);
  printf(1,"Total time by uptime difference %d\n",etime-stime);
  exit();
}
