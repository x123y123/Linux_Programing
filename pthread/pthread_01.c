#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define test_parallel 

void *work_1(int n)
{

#ifdef test_parallel
    sleep(3);
#endif

    n++;
    printf("work_1 cnt: %d , time: %d\n", n, time(NULL));
}

void *work_2(int n)
{
    n++;
    printf("work_2 cnt: %d , time: %d\n", n, time(NULL));
}

int main(int argc, char **argv)
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, work_1, 0);
    pthread_create(&t2, NULL, work_2, 0);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
