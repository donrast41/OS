#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <sys/resource.h>

void run_for_ten();

int main() {
	run_for_ten();
	return 0;
}

void run_for_ten() {
	struct rusage mem_usage;
	int i;
	for (i = 0; i < 10; i++) {
		void *ptr = malloc(1024 * 1024 * 10);
		memset(ptr, 0, 1024 * 1024 * 10);
		getrusage(RUSAGE_SELF, &mem_usage);
		printf("usage = %ld\n", mem_usage.ru_maxrss);
		sleep(1);
	}
}
