#include <iostream>
#include <cstdio>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

FILE* out;

void print_file_descriptors()
{
	FILE* fp = fopen("random_file", "w");
	if (fp == NULL)
		return;
	int fd = fileno(fp);
	fprintf(out, "%d ", fd);
	if (fd < 100)
		print_file_descriptors();
	fclose(fp);
}

int main() {

	dup2(1, 101);
	out = fdopen(101, "w");
	close(1);
	close(2);
	print_file_descriptors();
	fprintf(out, "\n");
	return 0;
}
