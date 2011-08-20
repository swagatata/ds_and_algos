#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int i = 0;
void sig_alarm_handler(int signal) {
    ++i;
    printf("%d\n", i);
    if(i < 100)
        alarm(1);
    else
        exit(0);
}

int main() {
    signal(SIGALRM, sig_alarm_handler);
    alarm(1);
    int x;
    scanf(" %d",&x);
    return 0;
}
