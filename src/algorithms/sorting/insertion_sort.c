#include <CS101/sorting.h>

void CS101_insertion_sort(int *first, int *last)
{
	for (int *i = first + 1; i < last; i++) {
		int key = *i;
		int *j = i - 1;
		while (j >= first && *j > key) {
			j[1] = *j;
			j--;
		}
		j[1] = key;
	}
}
