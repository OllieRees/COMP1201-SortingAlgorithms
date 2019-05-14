#include "sorting.h"

/** Two loops so O(n^2) */
int* selectionSort(int unsorted[], int size) {
	int remaining = size;
	int * arr_ptr = unsorted;
	int i, j, noDone;
	noDone = 0;
	
	for(i = 0; i < size; i++) {
		int min = unsorted[i];
		int min_i = i;
	
		//get min
		for(j = noDone; j < remaining; j++) {
			if(min > unsorted[j]) {
				min = unsorted[j];
				min_i = j;
			}
		}
		
		noDone++;
		int temp = unsorted[i];
		unsorted[i] = min;
		unsorted[min_i] = temp;
	}
	return arr_ptr;
}

/* Two loops so O(n^2): the array is sorted from highest to lowest */
int* insertionSort(int unsorted[], int size) {
	int* ptr = unsorted;
	int i;
	//sort the first two
	if(unsorted[1] < unsorted[0]) {
		int temp = unsorted[1];
		unsorted[1] = unsorted[0];
		unsorted[0] = temp;
	}
	
	//sort the second to ith card
	for(i = 2; i < size; i++) {
		int j = i;
		while(unsorted[j] < unsorted[j - 1]) {
			int temp = unsorted[j];
			unsorted[j] = unsorted[j - 1];
			unsorted[j - 1] = temp;
			j--;
		}
	}
	return ptr;
}

/* Finish implementation */
int* radixSort(int[] unsorted, int base, int size) {
	int* ptr = unsorted;
	int exp;

	//get max
	int max = unsorted[0];
	int i;
	for(i = 0; i < size; i++) {
		if(unsorted[i] > max)
			max = unsorted[i]
	}
	
	//cycle from least sig digit to most sig digit
	while(exp = 0; 0 < max/pow(10, exp); exp++) {
		int digits[size];
		for(i = 0; i < size; i++) {
			digits[i] = unsorted[i]/pow(10, exp);
		}
		for(i = 0; i < size; i++) {
			insertionSort(digits);
		}	
	}
}

int main(int argc, char * argv[]) {
	if(argc > 1) {
		int n = argc - 1;
		int arr[argc];
		while(n > 0) {
			arr[n] = atoi(argv[n]);
			n--;
		}
		int* ptr = malloc(argc * sizeof(int));
		ptr = insertionSort(arr, argc);
		int i;
		for(i = 0; i < argc; i++) { 
			printf("%d\n", ptr[i]);
		}
	}
}	
