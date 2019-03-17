
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<signal.h>
/*  kill()
int main(int argc, char *argv[])
{
    printf("My PID: %d\n",getpid());
    sleep(5);
kill(getpid(),SIGSEGV);
    return 0;
}*/


void handler(int signal)
{
    printf("Signal %d Received. Kill me if you can\n", signal);
}
int main( int argc, char *argv[])
{
    //signal(SIGINT,handler);
    signal(SIGINT,handler);
    printf("Put into while 1 loop...\n");
    while(1){}

    printf("OK!\n");
    return 0;
}

