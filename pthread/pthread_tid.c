/* An simple example of pthread */


#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include <sys/syscall.h>

#define gettid() syscall(__NR_gettid)

static void *worker(void *param)
{    
    printf("thread pid: %d, tid: %d, pthread_self: %lu\n", getpid(), gettid(), pthread_self());
    return NULL;
}

int main()
{
    pthread_t thread_1;
    int ret;

    printf("main_thread pid: %d, main_tid: %d, main_pthread_self: %lu\n", getpid(), gettid(), pthread_self());

    ret = pthread_create(&thread_1, NULL, worker, NULL);
    if (ret == -1) {
        perror("can't create new thread");
        return -1;
    }

    if(pthread_join(thread_1, NULL) != 0) {
        perror("call pthread_join function fail");
        return -1;
    }

    return 0;
}
