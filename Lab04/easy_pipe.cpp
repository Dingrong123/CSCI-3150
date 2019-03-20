
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main()
{
    int pipefds[2];
    char buf[30];

    if (pipe(pipefds)==-1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    printf("writing to file descriptor #%d\n" , pipefds[1]);
    write(pipefds[1], "Kobe", 5);

    printf("reading from file descriptor #%d\n" , pipefds[0]);
    read(pipefds[0], buf,5);
    printf("read\"%s\"\n", buf);
    return 0;
}