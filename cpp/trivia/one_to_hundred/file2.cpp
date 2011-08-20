#include <stdlib.h>
#include <stdio.h>

int main() {
    FILE* fd = fopen("data.txt", "r");
    if(fd < 0) {
        perror("File open");
        exit(1);
    }

    char buf[10000];
    size_t n = fread(buf, sizeof(char), 10000, fd);
    fwrite(buf, sizeof(char), n, stdout);
    fflush(stdout);
    fclose(fd);
    return 0;
}

