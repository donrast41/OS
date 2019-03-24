#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

	char buff[5];
    if (setvbuf(stdout, buff, _IOLBF, sizeof(buff))) {
		perror("Buff Error");
		return (EXIT_FAILURE);
	}

	printf("H");
	sleep(1);
	printf("e");
	sleep(1);
	printf("l");
	sleep(1);
	printf("l");
	sleep(1);
	printf("o");
	sleep(1);
	return 0;
}
