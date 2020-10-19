#include <stdlib.h>
#include <limits.h>
#include <CS101/sorting.h>

const int SENTINEL = INT_MAX;

void merge(int arr[], int left[], int right[], int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;

	for (int i = 0; i < n1; i++)
		left[i] = arr[p + i];
	for (int i = 0; i < n2; i++)
		right[i] = arr[q + i + 1];

	left[n1] = SENTINEL;
	right[n2] = SENTINEL;

	int i = 0;
	int j = 0;

	for (int k = p; k <= r; k++) {
		if (left[i] <= right[j]) {
			arr[k] = left[i];
			i++;
		}
		else {
			arr[k] = right[j];
			j++;
		}
	}
}

void _merge_sort(int arr[], int left[], int right[], int p, int r)
{
	if (p < r) {
		int q = (p + r) / 2;
		_merge_sort(arr, left, right, p, q);
		_merge_sort(arr, left, right, q + 1, r);
		merge(arr, left, right, p, q, r);
	}
}

void CS101_merge_sort(int *first, int *last)
{
	int length = last - first;
	int *left = malloc(length * sizeof(int));
	int *right = malloc(length * sizeof(int));
	_merge_sort(first, left, right, 0, length - 1);
	free(left);
	free(right);
}
