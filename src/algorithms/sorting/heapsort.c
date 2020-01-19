#include <stdlib.h>
#include <CS101/sorting.h>
#include <CS101/heap.h>
#include <CS101/util.h>

void heapsort(int arr[], int first, int last)
{
	int length = last - first;
	struct heap *heap = heap_new_max(arr + first, length);

	for (int i = length - 1; i >= 1; i--) {
		swap(heap->arr, heap->arr + i);
		heap->size--;
		heapify(heap, 0);
	}
	free(heap);
}
