#include <stdlib.h>

#include <sorting.h>

const int SENTINEL = 9999999;

void merge(int arr[], int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;

	// TODO: Get rid of these dynamic allocations
	int *left = malloc((n1 + 1) * sizeof(int));
	int *right = malloc((n2 + 1) * sizeof(int));

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
		} else {
			arr[k] = right[j];
			j++;
		}
	}

	free(left);
	free(right);
}

void merge_sort_(int arr[], int p, int r)
{
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort_(arr, p, q);
		merge_sort_(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}

void merge_sort(int arr[], int n)
{
	merge_sort_(arr, 0, n - 1);
}
