#include <stdlib.h>
#include <sorting.h>

const int SENTINEL = 9999999;

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
		} else {
			arr[k] = right[j];
			j++;
		}
	}
}

void merge_sort_(int arr[], int left[], int right[], int p, int r)
{
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort_(arr, left, right, p, q);
		merge_sort_(arr, left, right, q + 1, r);
		merge(arr, left, right, p, q, r);
	}
}

void merge_sort(int arr[], int n)
{
	int* left = malloc((n / 2 + 1) * sizeof(int));
	int* right = malloc((n / 2 + 1) * sizeof(int));
	merge_sort_(arr, left, right, 0, n - 1);
	free(left);
	free(right);
}