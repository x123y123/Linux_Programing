/* thread_task set specific cpu  */

// $ lscpu  => check numbers of cpu 
// pthread_setaffinity_np(pthread_t, size_t cpusetsize, cpu_set_t *cpuset);
// pthread_getaffinity_np(pthread_t, size_t cpusetsize, cpu_set_t *cpuset);


#include <stdio.h>
#include <pthread.h>
#include <sched.h>

int main()
{
    int cpu_id = 0;
    
    cpu_set_t mask;
    
    CPU_ZERO(&mask);

    CPU_SET(cpu_id, &mask);

    printf("pthread_setaffinity_np cpu: %d\n", cpu_id);
    
    pthread_t t_main = pthread_self();
    pthread_setaffinity_np(t_main, sizeof(cpuset), &cpuset);

    //printf("check cpu = %d\n", pthread_getaffinity_np(t_main, sizeof(cpuset), &mask));
    printf("check cpu = %d\n", sched_getcpu());

    return 0;
}
