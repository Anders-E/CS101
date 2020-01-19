#include <stdio.h>
#include <CS101/heap.h>
#include <CS101/util.h>

int max_comp(int x, int y) { return x > y; }
int min_comp(int x, int y) { return x < y; }

void heapify(struct heap heap, int i)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	int largest;
	if (l < heap.size && heap.comp(heap.arr[l], heap.arr[i]))
		largest = l;
	else
		largest = i;
	if (r < heap.size && heap.comp(heap.arr[r], heap.arr[largest]))
		largest = r;

	if (largest != i) {
		swap(heap.arr + i, heap.arr + largest);
		heapify(heap, largest);
	}
}

struct heap heap_new(int arr[], int size, comp_func comp)
{
	struct heap heap = { arr, size, comp };
	for (int i = size / 2; i >= 0; i--)
		heapify(heap, i);
	return heap;
}

struct heap heap_new_max(int arr[], int size)
{
	return heap_new(arr, size, max_comp);
}

struct heap heap_new_min(int arr[], int size)
{
	return heap_new(arr, size, min_comp);
}

void heap_print_(struct heap heap, int i)
{
	printf("[%d", heap.arr[i]);

	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < heap.size || r < heap.size)
		printf(" ");
	if (l < heap.size)
		heap_print_(heap, l);
	if (r < heap.size)
		heap_print_(heap, r);
	
	printf("]");
}

void heap_print(struct heap heap)
{
	heap_print_(heap, 0);
	printf("\n");
}
