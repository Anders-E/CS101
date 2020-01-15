#include <stdlib.h>
#include <sorting.h>

void counting_sort(int arr[], int n, int k)
{
	int *count = calloc(k, sizeof(int));
	int *sorted = malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
		count[arr[i]]++;
	for (int i = 1; i < k; i++)
		count[i] += count[i - 1];
	for (int i = n - 1; i >= 0; i--) {
		sorted[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}
	for (int i = 0; i < n; i++)
		arr[i] = sorted[i];

	free(count);
	free(sorted);
}
