#include <stdlib.h>
#include <sorting.h>

void counting_sort(int arr[], int first, int last, int k)
{
	int *count = calloc(k, sizeof(int));
	int *sorted = malloc(((size_t)last - first) * sizeof(int));

	for (int i = first; i < last; i++)
		count[arr[i]]++;
	for (int i = 1; i < k; i++)
		count[i] += count[i - 1];
	for (int i = last - 1; i >= first; i--) {
		sorted[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}
	for (int i = first; i < last; i++)
		arr[i] = sorted[i - first];

	free(count);
	free(sorted);
}
