#include <pthread.h>
#include <stdio.h>
#include<stdlib.h>

#define NUM_THREADS 5
void *runner(void *param);

int main(int argc, char *argv[]) {
    int i;
    pthread_t tid[NUM_THREADS];
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    pthread_attr_setscope(&attr, PTHREAD_SCOPE_PROCESS);

    for (i = 1; i <= NUM_THREADS; ++i)
        pthread_create(&tid[i-1], &attr, runner, &i);

    for (i = 10; i < NUM_THREADS+10; ++i)
        pthread_join(tid[i-10], NULL);
}
void *runner(void *param)
{
    int num=*(int *)param;
    printf("I am the thread %d\n",num);

    pthread_exit(0);

}