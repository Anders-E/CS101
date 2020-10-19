#include <math.h>
#include <stdlib.h>
#include <CS101/sorting.h>

int get_digit(int x, int n, int radix)
{
	int div = (int) (pow(radix, n) + .5);
	int mod = div * radix;
	return (x % mod) / div;
}

void CS101_radix_sort(int *first, int *last, int radix)
{
	int *count = malloc(radix * sizeof(int));
	int *sorted = malloc((last - first) * sizeof(int));

	for (int i = 0; i < radix; i++) {
		for (int j = 0; j < radix; j++)
			count[j] = 0;
		for (int *j = first; j < last; j++) {
			int digit = get_digit(*j, i, radix);
			count[digit]++;
		}
		for (int j = 1; j < radix; j++)
			count[j] += count[j - 1];
		for (int *j = last - 1; j >= first; j--) {
			int digit = get_digit(*j, i, radix);
			sorted[count[digit] - 1] = *j;
			count[digit]--;
		}
		for (int *j = first; j < last; j++)
			*j = sorted[j - first];
	}

	free(count);
	free(sorted);
}
