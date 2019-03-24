#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <memory.h>
#include <unistd.h>
#include <fcntl.h>
#include <bits/fcntl-linux.h>
#include <sys/stat.h>

int main() {
    int fl = open("ex1.txt", O_RDWR);
    if(fl < 0) {
        printf("File Error.");
        return (EXIT_FAILURE);
    }
    struct stat st = {};

    if (fstat(fl ,&st)) {
        perror("FSTAT error");
        return (EXIT_FAILURE);
    }

    off_t size_t = st.st_size;
    ftruncate(fl, 18);

    char* addr = mmap(NULL, size_t, PROT_READ|PROT_WRITE, MAP_SHARED,fl, 0);

    if (addr == MAP_FAILED){
        printf("Memory map Error\n");
    }

    char* new = "This is a nice day";
    for(int i = 0; i < strlen(new); i++){
        addr[i] = new[i];
    }

    return (EXIT_SUCCESS);
}
