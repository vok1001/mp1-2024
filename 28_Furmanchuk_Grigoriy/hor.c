#include "stdio.h"
#include "stdlib.h"
#include <stdbool.h>
#include <time.h>

void swap(int arr[], int pos1, int pos2) {
	int temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

int partition(int arr[], int low, int high, int pivot, int * it) {
	int i = low;
	int j = low;
	while (i <= high) {
		if (arr[i] > pivot) {
			i++;
		}
		else {
			swap(arr, i, j);
			i++;
			j++;
		}
		*it++;
	}
	return j - 1;
}

void quickSort(int arr[], int low, int high) {
	int it=0;
	if (low < high) {
		int pivot = arr[high];
		int pos = partition(arr, low, high, pivot, &it);

		quickSort(arr, low, pos - 1);
		quickSort(arr, pos + 1, high);
	}
	

}

int main()
{
	clock_t start, finish;
	double time;
	int arr[] = { 9, 8, 7, 6 };
	start = clock();
	quickSort(arr, 0, 3);
	finish = clock();
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("time %.8f\n", time);

	for (int i = 0; i < 4; i++) {
		printf("%d ", arr[i]);
	}
	
}