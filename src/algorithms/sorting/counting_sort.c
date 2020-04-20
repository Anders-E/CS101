#include <stdlib.h>
#include <CS101/sorting.h>

void counting_sort(int *first, int *last, int k)
{
	int *count = calloc(k, sizeof(int));
	int *sorted = malloc(((size_t) (last - first)) * sizeof(int));

	for (int *i = first; i < last; i++)
		count[*i]++;
	for (int i = 1; i < k; i++)
		count[i] += count[i - 1];
	for (int *i = last - 1; i >= first; i--) {
		sorted[count[*i] - 1] = *i;
		count[*i]--;
	}
	for (int *i = first; i < last; i++)
		*i = sorted[i - first];

	free(count);
	free(sorted);
}
