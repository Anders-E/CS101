#include <CS101/sorting.h>
#include <CS101/util.h>

int *partition(int *p, int *r)
{
	int x = *r;
	int *i = p - 1;
	for (int *j = p; j < r; j++) {
		if (*j <= x) {
			i++;
			swap(i, j);
		}
	}
	swap(i + 1, r);
	return i + 1;
}

void quicksort(int *p, int *r)
{
	if (p < r) {
		int *q = partition(p, r);
		quicksort(p, q - 1);
		quicksort(q + 1, r);
	}
}

void CS101_quicksort(int *first, int *last)
{
	quicksort(first, last - 1);
}
