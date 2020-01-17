#include <sorting.h>

void insertion_sort(int arr[], int first, int last)
{
	for (int i = first + 1; i < last; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= first && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
