#include <stdio.h>

#define PRINT printf("%d\n", i++);
#define PRINT2 PRINT PRINT
#define PRINT4 PRINT2 PRINT2
#define PRINT8 PRINT4 PRINT4
#define PRINT16 PRINT8 PRINT8
#define PRINT32 PRINT16 PRINT16
#define PRINT64 PRINT32 PRINT32

int main() {
    int i = 1;
    PRINT64
    PRINT32
    PRINT4
    return 0;
}

