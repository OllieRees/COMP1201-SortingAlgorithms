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
	int* arr_ptr = unsorted;
	int counter = 0;
	int remaining = size;
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
		counter++;
		}
		
		noDone++;
		int temp = unsorted[i];
		unsorted[i] = min;
		unsorted[min_i] = temp;
	}
	printf("Size : %d\t|\tIterations %d\t|\n", size, counter);
	return arr_ptr;
}

/* Two loops so O(n^2): the array is initially sorted from highest to lowest */
int* insertionSort(int unsorted[], int size) {
	int* ptr = unsorted;
	int counter = 0;
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
		counter++;
		}
	}
	printf("|Size : %d\t|\tIterations : %d\t|\n", size, counter);
	return ptr;
}

/* O(n^2) as there's a nested for-loop: the first pass takes n-1 iterations, the second n-2, etc. */
/* It's in-place (no array created in the method), and stable (7_l, 3, 7_r, 4 becomes 3, 4, 7_l, 7_r) */
int* bubbleSort(int unsorted[], int size) {
	int* ptr = unsorted;
	int counter = 0;
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
		counter++;
		}
	printArray(unsorted, size);
	}
	printf("|Size : %d\t|\tIterations : %d\t|\n", size, counter);
	return ptr;	
}

int* shellSort(int unsorted[], int size) {
	int* ptr = unsorted;	
	int counter = 0;
	int interval; 

	//change interval gap (reduce it)
	for(interval = size/2; interval > 0; interval /= 2) {		
		//cycle through every sublist
		int i;
		for(i = interval; i < size; i++) {
			int j = 0;
			//compare the various elements in the sublist. Sublist.size > 2.
			for(j = i; j >= interval; j-=interval) {
				if(unsorted[j-interval] > unsorted[j]) {
					int temp = unsorted[j];
					unsorted[j] = unsorted[j-interval];
					unsorted[j-interval] = temp;
				}
			counter++;
			}
		}
	}
	printf("|Size : %d\t|\tIterations : %d\t|\n", size, counter);
	return ptr;
}

void callSortingMethod(char * sortingName, int arr[], int size, bool printSorted) {
	int* ptr = malloc(size * sizeof(int));
	if(sortingName == "insertion")
		ptr = insertionSort(arr, size);
	if(sortingName == "selection")
		ptr = selectionSort(arr, size);
	if(sortingName == "bubble")
		ptr = bubbleSort(arr, size);
	if(sortingName == "shell")
		ptr = shellSort(arr, size);
	if(printSorted)
		printArray(ptr, size);
}
	
int main(int argc, char * argv[]) {
	char * sortingName = argv[1]; //1st argument is sorting method

	/* Sort a list of numbers */
	if(argc > 2) {
		int n = argc - 1;
		int arr[argc];
		while(n > 0) {
			arr[n] = atoi(argv[n]);
			n--;
		}
		int* ptr = malloc(argc * sizeof(int));
		callSortingMethod(sortingName, arr, argc - 2, true);
	}
	
	/* No arguments : tests the complexity of the program */
	int i;
	for(i = 1000; i < 1000000000; i += 1000) {
		int arr[i];
		int j;
		for(j = 0; j < i; j++)
			arr[j] = i - j; 
		
		callSortingMethod(sortingName, arr, i, false);
	}
}	
