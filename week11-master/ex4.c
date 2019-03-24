#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>


int main() {

	int src = open("ex1.txt", O_RDONLY);
	size_t file_size = lseek(src, 0, SEEK_END);
    char *f1 = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, src, 0);

    int dest = open("ex1.memcpy.txt", O_RDWR | O_CREAT, 0666);
	ftruncate(dest, file_size);
    char *f2 = mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, dest, 0);

	memcpy(f2, f1, file_size);
    munmap(f1, file_size);
	munmap(f2, file_size);

	close(src);
    close(dest);
	return 0;
}
