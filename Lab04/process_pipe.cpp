
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pipefds[2];
    char buf[30];
    pid_t pid;

    if(pipe(pipefds)==-1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    memset(buf, 0,30);
    pid=fork();


    if(pid>0)
    {
        printf("Parent write to the pipe\n");
        close(pipefds[0]);
        write(pipefds[1],"Run As One", 11);
        close(pipefds[1]);
        wait(NULL);
    } else{
        close(pipefds[1]);
        while (read(pipefds[0],buf,1)==1)
            printf ("I read  %s\n",buf);
        close(pipefds[0]);
        printf("Received the message ");
        exit(EXIT_SUCCESS);
    }
    return 0;
}