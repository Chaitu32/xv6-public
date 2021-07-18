#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc,char* argv[]){
    int pid = fork();
    if(pid<0){
        exit(); 
    }
    if(pid==0){
        sleep(2);
        for(int j=0;j<5;j++){
            printf(1,"This is child with pid %d\n",getpid());
            int x=0;
            for (int i = 0; i < 100000000; i++)
            {
                x=((x+2)*x)/1000; //cpu time
            }
            sleep(10);
        }
        printf(1,"This is child with pid %d getting exit.\n",getpid());
    }
    else{
        int w,r;
        printf(1,"parent with pid %d waiting for child with pid %d\n",getpid(),pid);
        waitx(&w,&r);
        printf(1,"test completed %d %d\n",w,r);
    }
    exit();
}