/* using kill() keep sending a signal in 10s to another pid named "signal" */

// int kill(pid_t pid, int sig);       ----- #include <signal.h>

//EPERM     Operated permission denied ----- #include <errno.h>
//ESRCH     param pid does not exist in process list
//EINVAL    specified signal is invalid

#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <time.h>


int main(int argc, char *argv[])
{
    char buf[10];
    time_t endwait;
    time_t stop_time = 10;
    endwait = time(NULL) + stop_time;

    FILE *cmd = popen("pidof signal","r");
    fgets(buf, 10, cmd);
    pid_t pid_signal = strtoul(line, NULL, 10);


    while (time(NULL) < endwait) {
        kill(pid_signal, SIGUSR1);

        if (errno == EPERM) 
            printf("permission denied!\n");
        else if (errno == ESRCH) 
            printf("process does not exist!\n");
        else if (errno == EINVAL) 
            printf("specified signal is invalid!\n");
        else 
            printf("kill act!\n");
    }
    pclose(cmd);

    return 0;
}
