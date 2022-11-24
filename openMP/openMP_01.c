/* A simple code to learn how to implement parallel programming by openMP */


#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

//function note
/*
    int omp_get_thread_num();     get thread id
    int omp_get_max_threads();    get the numbers of thread

    #pragma omp parallel shared(shar_Var1) private(priv_Var1, priv_Var2)
    
    #pragma omp barrier         
*/

int main(int argc, char **argv)
{
    int thread_id;

    #pragma omp parallel
    {
        thread_id = omp_get_thread_num();
        
        for (int i = 0; i < omp_get_max_threads(); i++) {
            if (i == omp_get_thread_num())                              // a condition that requires the loop to be on the proper iteration to print its thread number
                printf("hello world from %d\n", omp_get_thread_num());
            
            #pragma omp barrier                                         // wait for other threads
        }
    }
    return 0;
}
