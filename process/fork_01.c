/* a simple experiment to check fork() ordering */

// pid_t wait(int *stat)


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define swap

int main(int argc, char **argv)
{
    int n, id = fork();


    if (id == 0) {     // child will start in 0
        n = 1;
    } else {
        n = 6;         // parent will start in 10
#ifndef swap
        wait(NULL);
#endif
    }


    for (int i = n; i < n + 5; i++) {
        printf("%d ", i);
        fflush(stdout);
    }

    return 0;
}
