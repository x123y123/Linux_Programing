/* recieve signal "SIGUSR1" or "SIGUSR2",maybe from kill() */

#include <stdio.h>
#include <signal.h>
#include <errno.h>

// void(*signal(int sig, void (*func)(int)))(int)
// => *signal(int sig, void (*func)(int))

static void sig_usr(int sig_no)
{
    if (sig_no == SIGUSR1)
        printf("SIGUSR1 act!\n");
    else if (sig_no == SIGUSR2)
        printf("SIGUSR2 act!\n");
}

int main()
{
    while (1) {
        if (signal(SIGUSR1, sig_usr) == SIG_ERR)
            printf("can't catch SIGUSR1\n");
        else if (signal(SIGUSR2, sig_usr) == SIG_ERR)
            printf("can't catch SIGUSR2\n");
    }

    return 0;
}
