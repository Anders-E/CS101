#include <CS101/sorting.h>

void bubble_sort(int *first, int *last)
{
	int sorted = 0;
	while (!sorted) {
		sorted = 1;
		for (int *i = first; i < last - 1; i++) {
			if (*i > i[1]) {
				int tmp = *i;
				*i = i[1];
				i[1] = tmp;
				sorted = 0;
			}
		}
	}
}
