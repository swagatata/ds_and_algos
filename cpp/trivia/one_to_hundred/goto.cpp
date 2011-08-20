#include <stdio.h>

int main(void) {
    int i = 1;

    // Cheat by using a goto loop

repeat:
    printf("%d\n", i++);
    if(i <= 100)
        goto repeat;

    return 0;
}
