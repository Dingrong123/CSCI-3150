#include <pthread.h>
#include <stdio.h>
#include<stdlib.h>

#define NITERS 10000
void *count(void *param);
int sum=0;
int main(int argc, char *argv[]) {
    int i;
    pthread_t t1,t2;

    pthread_attr_t attr;

    pthread_attr_init(&attr);

    pthread_attr_setscope(&attr, PTHREAD_SCOPE_PROCESS);


    pthread_create(&t1, &attr,count,NULL);
    pthread_create(&t2,&attr,count,NULL);


    pthread_join(t1, NULL);
    pthread_join(t2,NULL);
    printf("Total:%d\n",sum);
    exit(0);
}
void *count(void *param)
{
    for(int i=0;i<NITERS;++i)
        ++sum;

    pthread_exit(0);

}