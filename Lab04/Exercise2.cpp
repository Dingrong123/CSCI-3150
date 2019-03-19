
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char*argv[])
{
    int pipefds[2];
    char buf1[30];
    char buf2[30];
    pid_t pid;

    if(pipe(pipefds)==-1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    memset(buf1, 0,30);
    memset(buf2,0,30);



        write(pipefds[1],argv[1],sizeof(argv[1])+1 );
        read(pipefds[0],buf1,sizeof(argv[1])+1);
        write(pipefds[1],argv[2],sizeof(argv[2])+1 );
        read(pipefds[0],buf2,sizeof(argv[2])+1);
        close(pipefds[1]);
        printf("%s\n",buf1);
        printf("%s\n",buf2);
        execlp("ls",buf1,buf2,NULL);
        close(pipefds[0]);

    return 0;
}