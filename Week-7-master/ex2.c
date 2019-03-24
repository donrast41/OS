#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int main() {

	int n;

	printf("Enter number ");
	scanf("%d",&n);

	int *arr = malloc(sizeof(int));

	for (int i=1; i<=n;i++) {
		realloc(arr, (i)*sizeof(int));
		arr[i-1] = i;
		printf("%d  ", arr[i-1]);
	}

	free(arr);
}
