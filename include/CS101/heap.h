#ifndef HEAP_H
#define HEAP_H

typedef int (*compare_func)(int, int);

typedef struct CS101_heap {
	int *arr;
	int size;
	compare_func compare;
} CS101_heap;

CS101_heap *heap_new(int arr[], int size, compare_func compare);
CS101_heap *heap_new_max(int arr[], int size);
CS101_heap *heap_new_min(int arr[], int size);
int heap_root(CS101_heap *heap);
int heap_extract_root(CS101_heap *heap);
int heap_change_key(CS101_heap *heap, int i, int key);
int heap_insert(CS101_heap *heap, int key);
void heapify(CS101_heap *heap, int i);
void heap_print(CS101_heap *heap);

#endif // !HEAP_H
