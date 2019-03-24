#include <stdio.h>
#include <sys/resource.h>
#include <string.h>
#include <malloc.h>

void run_for_ten();

int main() {
	run_for_ten();
	return 0;
}

void run_for_ten() {
	int i;
	for (i = 0; i < 10; i++) {
		void *ptr = malloc(1024 * 1024 * 10);
		memset(ptr, 0, 1024 * 1024 * 10);
		sleep(1);
		free(ptr);
	}
}
