#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

struct args
{
    char *sen;
    int num;
};

void* print(void * input)
{
    printf("His name is %s\n", ((struct args *)input)->sen);
    printf("His score is %d\n",((struct args *)input)->num);
}

int main()
{
    pthread_t tid1;
    args *value=(struct args *)malloc(sizeof(args));
    char sent[]="Kobe";
    value->sen=sent;
    value->num=81;
    pthread_create(&tid1,NULL,print,(void*)value);
    pthread_join(tid1,NULL);

    return 0;
};