/* A simple code to test pthread_barrier_wait() happen */
/*
    int pthread_barrier_init(pthread_barrier_t *restric, const pthread_barrierattr_t *restrict attr, unsigned count);
    int pthread_barrier_wait(pthread_barrier_t *barrier);
    int pthread_barrier_destroy(pthread_barrier_t *barrier);
*/


#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

pthread_barrier_t barrier;


static void *worker_1(void *param)
{

    printf("worker_1 : start at %ld\n", time(NULL));
    
    sleep(5);
    printf("worker_1 arrive barrier at %ld\n", time(NULL));
    pthread_barrier_wait(&barrier);
    
    printf("worker_1 : end at %ld\n", time(NULL));
}

static void *worker_2(void *param)
{
    printf("worker_2 : start at %ld\n", time(NULL));
    
    sleep(10);
    printf("worker_2 arrive barrier at %ld\n", time(NULL));
    pthread_barrier_wait(&barrier);
    
    printf("worker_2 : end at %ld\n", time(NULL));
}


int main(int argc, char **argv)
{
    pthread_t thread_1, thread_2;
    pthread_barrier_init(&barrier, NULL, 3);                                    // 3 -> pthread_self(), thread_1, thread_2
    printf("pthread_barrier_init done at %ld\n", time(NULL));                                             
                                             
    pthread_create(&thread_1, NULL, &worker_1, NULL);
    pthread_create(&thread_2, NULL, &worker_2, NULL);
   
    printf("wait for other thread in front of barrier at %ld\n", time(NULL));
    pthread_barrier_wait(&barrier);
    pthread_barrier_destroy(&barrier);

    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);

    return 0;
}
