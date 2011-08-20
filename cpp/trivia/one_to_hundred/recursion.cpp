#include <stdio.h>
#include <stdlib.h>

void recurse(int n) {
    if(n == 101) {
        exit(0);
    }

    printf("%d\n", n);
    recurse(n+1);
}

int main() {
    recurse(1);
    return 0;
}

