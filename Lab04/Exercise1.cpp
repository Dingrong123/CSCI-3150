
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pipefds[2],pipefds2[2];
    char bufp[30],bufc[30];
    pid_t pid;
    if(pipe(pipefds)==-1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    if(pipe(pipefds2)==-1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }


    pid=fork();
   alarm(10);

    if(pid>0)
    {
        while(true) {
            sleep(rand()%2+1);
            printf("Parent write to the child\n");
            write(pipefds[1], "Run As One\n", 12);
            read(pipefds2[0], bufp, 15);
            printf("Parent read from the child\n");
            printf("%s", bufp);
        }
    }
    else {


        while (true) {
            sleep(rand()%2+1);
            read(pipefds[0], bufc, 15);
            printf("Child receive from the parrent\n");
            printf("%s", bufc);
            write(pipefds2[1], "go Gavaliers\n", 13);
            printf("Child write to the parrent\n");
        }
    }
    return 0;
}