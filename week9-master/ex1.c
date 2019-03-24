#include <stdio.h>
#include <stdlib.h>

int pth[10];
int agt[10];
typedef int bool;
int main()
{
	FILE* file_path = fopen("lab.txt", "r");
	int i;
	for (i = 0; i < 10; i++)
		pth[i] = -1;
	i = 0;
	int time = 0, miss_count = 0, j;

	while (fscanf(file_path, "%d", &j) == 1) {
		bool flt = 1;
		int old = 0;

		for (i = 0; i < 10; i++) {
			if (pth[i] == j) {
				agt[i] = (1 << (31 - 1)) & (agt[i] >> 1);
				flt = 0;
			} else {
				agt[i] = agt[i] >> 1;
			}
			if (agt[i] < agt[old] || pth[i] == -1)
				old = i;
		}

		++time;
		if (!flt) continue;
		++miss_count;
		agt[old] = 1 << (31 - 1);
		pth[old] = j;
	}
    printf("Ratio of hits to miss is = %.3f\n", (double)(time-miss_count)/(miss_count));

	printf("Number of frames = %d\t Total Number = %d\t Number of Hits = %d\t Number of misses => %d\n", 10, time, time - miss_count, miss_count);
	return 0;
}
