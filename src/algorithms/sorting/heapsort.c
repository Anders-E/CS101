#include <stdlib.h>
#include <CS101/sorting.h>
#include <CS101/heap.h>
#include <CS101/util.h>

void CS101_heapsort(int *first, int *last)
{
	int length = last - first;
	CS101_heap *heap = heap_new_max(first, length);

	for (int i = length - 1; i >= 1; i--) {
		swap(heap->arr, heap->arr + i);
		heap->size--;
		heapify(heap, 0);
	}
	free(heap);
}
