#include <stdio.h>
#include <malloc.h>

int main() {
	int *arr1 = malloc(10*sizeof(int));
	int *arr2 = custom_realloc(arr1, sizeof(int)*10, sizeof(int)*20);
}

void *my_realloc(void *ptr, size_t startingLen, size_t endingLen){
	if (endingLen == 0) {
    	free(ptr);
    	return NULL;
	}
    else if (!ptr) {
    	return malloc(newLength);
	}
    else if (endingLen <= startingLen) {
    	return ptr;
	}
    else {
		int *startPtr = malloc(endingLen);
    	memcpy(startPtr, ptr, startingLen);
    	free(ptr);
    	return startPtr;
	}
}


