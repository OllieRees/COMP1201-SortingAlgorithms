#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/* Prints the contents of an array */
void printArray(int arr[], int size);

/* Sorts arr using selection sort */
int* selectionSort(int unsorted[], int size);

/* Sorts arr using insertion sort */
int* insertionSort(int unsorted[], int size);

/* Sorts unsorted using bubble sort */
int* bubbleSort(int unsorted[], int size);

/* Sorts unsorted using shell sort */
int* shellSort(int unsorted[], int size);

/* Divides the array in half with each iteration; sorts out the numbers in the merge. Divide and Conquer algorithm */
int* mergeSort(int unsorted[], int size);

/* Similar to mergesort, as it divides the array (use static function?) */
int* quickSort(int unsorted[], int size);

/* Sorts arr using radix sort */
int*  radixsort(int unsorted[], int size);

/* Decides what sorting method is called via the string provided in the cmd. line. */
void callSortingMethod(char * sortingName, int arr[], int size, bool printSorted);

