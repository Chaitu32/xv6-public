#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc,char* argv[]){
    if(argc!=1){
        printf(1,"Invaild args: No extra args required\n");
        exit();
    }
    cpu_ps();
    exit();
}