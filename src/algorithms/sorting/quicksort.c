#include <sorting.h>

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int partition(int arr[], int p, int r)
{
	int x = arr[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (arr[j] <= x) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[r]);
	return i + 1;
}

void quicksort_(int arr[], int p, int r)
{
	if (p < r) {
		int q = partition(arr, p, r);
		quicksort_(arr, p, q - 1);
		quicksort_(arr, q + 1, r);
	}
}

void quicksort(int arr[], int first, int last)
{
	quicksort_(arr, first, last - 1);
}
