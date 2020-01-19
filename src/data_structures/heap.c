#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <CS101/heap.h>
#include <CS101/util.h>

int max_comp(int x, int y) { return x > y; }
int min_comp(int x, int y) { return x < y; }

int parent(int i) { return (i - 1) / 2; }
int left(int i) { return i * 2 + 1; }
int right(int i) { return i * 2 + 2; }

struct heap *heap_new(int arr[], int size, comp_func comp)
{
	struct heap *heap = malloc(sizeof(struct heap));
	if (heap) {
		heap->arr = arr;
		heap->size = size;
		heap->comp = comp;
		for (int i = size / 2; i >= 0; i--)
			heapify(heap, i);
	}
	return heap;
}

struct heap *heap_new_max(int arr[], int size)
{
	return heap_new(arr, size, max_comp);
}

struct heap *heap_new_min(int arr[], int size)
{
	return heap_new(arr, size, min_comp);
}

int heap_root(struct heap *heap)
{
	return heap->arr[0];
}

int heap_extract_root(struct heap *heap)
{
	int max = heap->arr[0];
	heap->arr[0] = heap->arr[heap->size - 1];
	heap->size--;
	heapify(heap, 0);
	return max;
}

int heap_change_key(struct heap *heap, int i, int key)
{
	if (heap->comp(heap->arr[i], key))
		return 1; // error
	heap->arr[i] = key;
	while (i > 0 && heap->comp(heap->arr[i], heap->arr[parent(i)])) {
		swap(heap->arr + i, heap->arr + parent(i));
		i = parent(i);
	}
	return 0;
}

int heap_insert(struct heap *heap, int key)
{
	heap->size++;
	heap->arr[heap->size - 1] = (heap->comp(1, 0)) ? INT_MIN : INT_MAX;
	return heap_change_key(heap, heap->size - 1, key);
}

void heapify(struct heap *heap, int i)
{
	int l = left(i);
	int r = right(i);

	int largest;
	if (l < heap->size && heap->comp(heap->arr[l], heap->arr[i]))
		largest = l;
	else
		largest = i;
	if (r < heap->size && heap->comp(heap->arr[r], heap->arr[largest]))
		largest = r;

	if (largest != i) {
		swap(heap->arr + i, heap->arr + largest);
		heapify(heap, largest);
	}
}

void heap_print_(struct heap *heap, int i)
{
	printf("[%d", heap->arr[i]);

	int l = left(i);
	int r = right(i);

	if (l < heap->size || r < heap->size)
		printf(" ");
	if (l < heap->size)
		heap_print_(heap, l);
	if (r < heap->size)
		heap_print_(heap, r);
	
	printf("]");
}

void heap_print(struct heap *heap)
{
	heap_print_(heap, 0);
	printf("\n");
}
