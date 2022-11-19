#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int done = 0;

void *w2()
{
    pthread_mutex_lock(&mutex);
    printf("hello ");
    done++;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
}

void *w1()
{
    pthread_cond_wait(&cond, &mutex);
    printf("word!\n");
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, w1, NULL);
    pthread_create(&t2, NULL, w2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
