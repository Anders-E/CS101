#ifndef HEAP_H
#define HEAP_H

typedef int (*comp_func)(int, int);

struct heap {
	int *arr;
	int size;
	comp_func comp;
};

struct heap *heap_new(int arr[], int size, comp_func comp);
struct heap *heap_new_max(int arr[], int size);
struct heap *heap_new_min(int arr[], int size);
int heap_root(struct heap *heap);
int heap_extract_root(struct heap *heap);
int heap_change_key(struct heap *heap, int i, int key);
int heap_insert(struct heap *heap, int key);
void heapify(struct heap *heap, int i);
void heap_print(struct heap *heap);

#endif // !HEAP_H
