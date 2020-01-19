#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <CS101/sorting.h>
#include <CS101/util.h>

int get_digit(int x, int n)
{
	int div = (int) (pow(10, n) + .5);
	int mod = div * 10;
	return (x % mod) / div;
}

void radix_sort(int arr[], int first, int last, int n)
{
	int *count = malloc(10 * sizeof(int));
	int *sorted = malloc(((size_t)last - first) * sizeof(int));

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < 10; j++)
			count[j] = 0;
		for (int j = first; j < last; j++) {
			int digit = get_digit(arr[j], i);
			count[digit]++;
		}
		for (int j = 1; j < 10; j++)
			count[j] += count[j - 1];
		for (int j = last - 1; j >= first; j--) {
			int digit = get_digit(arr[j], i);
			sorted[count[digit] - 1] = arr[j];
			count[digit]--;
		}
		for (int j = first; j < last; j++)
			arr[j] = sorted[j - first];
	}

	free(count);
	free(sorted);
}
