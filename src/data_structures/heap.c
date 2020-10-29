#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <CS101/heap.h>
#include <CS101/util.h>

int max_compare(int x, int y) { return x > y; }
int min_compare(int x, int y) { return x < y; }

int parent(int i) { return (i - 1) / 2; }
int left(int i) { return i * 2 + 1; }
int right(int i) { return i * 2 + 2; }

CS101_heap *heap_new(int arr[], int size, compare_func compare)
{
	CS101_heap *heap = malloc(sizeof(CS101_heap));
	if (heap) {
		heap->arr = arr;
		heap->size = size;
		heap->compare = compare;
		for (int i = size / 2; i >= 0; i--)
			heapify(heap, i);
	}
	return heap;
}

CS101_heap *heap_new_max(int arr[], int size)
{
	return heap_new(arr, size, max_compare);
}

CS101_heap *heap_new_min(int arr[], int size)
{
	return heap_new(arr, size, min_compare);
}

int heap_root(CS101_heap *heap)
{
	return heap->arr[0];
}

int heap_extract_root(CS101_heap *heap)
{
	int max = heap->arr[0];
	heap->arr[0] = heap->arr[heap->size - 1];
	heap->size--;
	heapify(heap, 0);
	return max;
}

int heap_change_key(CS101_heap *heap, int i, int key)
{
	if (heap->compare(heap->arr[i], key))
		return 1; // error
	heap->arr[i] = key;
	while (i > 0 && heap->compare(heap->arr[i], heap->arr[parent(i)])) {
		swap(heap->arr + i, heap->arr + parent(i));
		i = parent(i);
	}
	return 0;
}

int heap_insert(CS101_heap *heap, int key)
{
	heap->size++;
	heap->arr[heap->size - 1] = (heap->compare(1, 0)) ? INT_MIN : INT_MAX;
	return heap_change_key(heap, heap->size - 1, key);
}

void heapify(CS101_heap *heap, int i)
{
	int l = left(i);
	int r = right(i);

	int largest;
	if (l < heap->size && heap->compare(heap->arr[l], heap->arr[i]))
		largest = l;
	else
		largest = i;
	if (r < heap->size && heap->compare(heap->arr[r], heap->arr[largest]))
		largest = r;

	if (largest != i) {
		swap(heap->arr + i, heap->arr + largest);
		heapify(heap, largest);
	}
}

void heap_print_(CS101_heap *heap, int i)
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

void heap_print(CS101_heap *heap)
{
	heap_print_(heap, 0);
	printf("\n");
}
