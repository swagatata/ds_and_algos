#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Open the data file
    int fd = open("data.txt", O_RDONLY);
    if(fd < 0) {
        perror("File open");
        exit(1);
    }

    // Get the size of the file
    struct stat stat_data;
    fstat(fd, &stat_data);
    off_t file_size = stat_data.st_size;

    // Memory map the file
    void* baseaddr = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if(baseaddr < 0) {
        perror("Memory mapping");
        exit(2);
    }

    // Copy the memory mapped region to stdout
    fwrite((char*)baseaddr, sizeof(char), file_size, stdout);
    fflush(stdout);

    // Unmap the memory mapped region
    munmap(baseaddr, file_size);

    // Close the file
    close(fd);
    return 0;
}
