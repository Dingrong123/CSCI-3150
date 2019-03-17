#include<stdio.h>
#include<unistd.h>
#include<errno.h>
int main(int argc, char *argv[])
{
    char *env[]={"LS_COLORS=fi=00;100;00",NULL};
    char *arg[]={"ls","-l","--color",NULL};
    printf ("My PID is %d\n",getpid());
    printf("Using *execl* to ecec");
    //execlp("ls","ls","-1",NULL);
    //execle("/bin/ls","ls","-l","--color",NULL,env);
    //execv("/bin/ls",arg);
    //execve("/bin/ls",arg,env);
    //execle("/home/rongding/.CLion2018.1/config/scratches/scraout",NULL);
    execl("bin/lls","lls",NULL);
    printf("excel rturned! errno is [%d]\n",errno);
    perror("The error is:");

    printf("program terminated\n");
    return 0;
}
