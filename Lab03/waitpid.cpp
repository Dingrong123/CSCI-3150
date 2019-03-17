#include <stdio.h>
#include<ctime>
#include<iostream>
/* Wait/wait.c */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pid;
    int status;
    if(!(pid=fork()))
    {
        printf("My PID is %d\n", getpid());
        exit(0);
    }

    waitpid(pid, &status,WUNTRACED);
    if(WIFEXITED(status))
    {
        printf("Exit Noramlly\n");
        printf("Exit status: %d\n", WEXITSTATUS(status));
    }
    else {
        printf("Exit Not Normal\n");
    }
    return 0;
}