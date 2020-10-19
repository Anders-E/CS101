#ifndef HEAP_H
#define HEAP_H

typedef int (*comp_func)(int, int);

struct CS101_heap {
	int *arr;
	int size;
	comp_func comp;
};

struct CS101_heap *heap_new(int arr[], int size, comp_func comp);
struct CS101_heap *heap_new_max(int arr[], int size);
struct CS101_heap *heap_new_min(int arr[], int size);
int heap_root(struct CS101_heap *heap);
int heap_extract_root(struct CS101_heap *heap);
int heap_change_key(struct CS101_heap *heap, int i, int key);
int heap_insert(struct CS101_heap *heap, int key);
void heapify(struct CS101_heap *heap, int i);
void heap_print(struct CS101_heap *heap);

#endif // !HEAP_H
