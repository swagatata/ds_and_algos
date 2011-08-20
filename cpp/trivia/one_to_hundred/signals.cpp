#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int mypid;

void signal_handler(int signal, siginfo_t* siginfo, void* extra) {
    assert(signal == SIGUSR1);

    printf("%d\n", siginfo->si_int);
    sigval_t signal_value;
    memcpy(&signal_value, &siginfo->si_value, sizeof(signal_value));
    ++signal_value.sival_int;
    if(signal_value.sival_int <= 100)
        sigqueue(mypid, SIGUSR1, signal_value);
    else
        exit(0);

}

int main() {
    mypid = getpid();

    struct sigaction sa;
    bzero(&sa, sizeof(sa));
    sa.sa_sigaction = signal_handler;
    sa.sa_flags = SA_SIGINFO | SA_NODEFER | SA_RESTART;

    sigaction(SIGUSR1, &sa, NULL);

    sigval_t signal_value;
    signal_value.sival_int = 1;
    sigqueue(mypid, SIGUSR1, signal_value);
    sleep(1000);
    return 0;
}

