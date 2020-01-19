#include <stdio.h>
#include <stdlib.h>

#include <CS101/sorting.h>
#include <CS101/linked_list.h>
#include <CS101/heap.h>
#include <CS101/util.h>

int main()
{
	int arr[10] = {
		57102375,
		35759206,
		47592010,
		58320837,
		45721513,
		15701475
	};
	int n = 6;

	struct heap *heap = heap_new_max(arr, n);

	heap_insert(heap, 5);
	heap_insert(heap, 999999999);
	heap_insert(heap, 2);
	heap_insert(heap, -5);


	array_print(heap->arr, heap->size);
	heap_print(heap);
}
