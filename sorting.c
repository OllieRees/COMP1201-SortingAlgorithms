#include "sorting.h"

void printArray(int arr[], int size) {
	int i;
	for(i = 0; i < size; i++) {
		printf("%d : %d\n ", i, arr[i]);
	}
	printf("\n");
}

/** Two loops so O(n^2) */
int* selectionSort(int unsorted[], int size) {
	int remaining = size;
	int * arr_ptr = unsorted;
	int i, j, noDone;
	noDone = 0; //number of mins. found
	
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
		int temp = unsorted[i-1];
		unsorted[i-1] = unsorted[i];
		unsorted[i] = temp;
	}
	
	//sort the second to ith card
	for(i = 2; i < size; i++) {
		int j = i;
		while(unsorted[j] < unsorted[j - 1]) {
			int temp = unsorted[j-1];
			unsorted[j-1] = unsorted[j];
			unsorted[j] = temp;
			j--;
		}
	}
	return ptr;
}

int* bubbleSort(int unsorted[], int size) {
	int* ptr = unsorted;
	int i, j;
	
	for(i = 0; i < size; i++) {
		int cardsLeft = size - i;
		//do one pass
		for(j = 1; j < cardsLeft; j++) {
			if(unsorted[j] < unsorted[j-1]) {
				int temp = unsorted[j-1];
				unsorted[j-1] = unsorted[j];
				unsorted[j] = temp;
			}
		}
	printArray(unsorted, size);
	}
	return ptr;	
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
		ptr = bubbleSort(arr, argc);
		int i;
		for(i = 0; i < argc; i++) { 
			printf("%d\n", ptr[i]);
		}
	}
}	
