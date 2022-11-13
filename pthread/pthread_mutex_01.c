/* an example about race condition in thread */
/* two workers want to use same computer ,it will cause race condition*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int cmp_use_times = 0;
pthread_mutex_t lock;

void *cmp_use()                             // correct ans will be 400000000, but if not lock it will go wrong
{
    for (int i = 0; i < 200000000; i++) {
        pthread_mutex_lock(&lock);          // lock
        cmp_use_times++;                    // if one of workers use computer, it will cnt
        pthread_mutex_unlock(&lock);        // unlock
    }
}

int main(int argc ,char **argv)
{
    pthread_t worker_1, worker_2;
    pthread_mutex_init(&lock, NULL);    // init mutex lock
                                        
    if (pthread_create(&worker_1, NULL, cmp_use, NULL) != 0)   // normally, pthread_create will return 0
        perror("worker_1 create fail\n");
    

    if (pthread_create(&worker_2, NULL, cmp_use, NULL) != 0) 
        perror("worker_2 create fail\n");
    

    if (pthread_join(worker_1, NULL) != 0)
        perror("worker_1 join fail\n");
    
    if (pthread_join(worker_2, NULL) != 0)
        perror("worker_2 join fail\n");
    
    printf("cmp_use_times: %d\n", cmp_use_times);
    pthread_mutex_destroy(&lock);       // destroy mutex lock

    return 0;
}
