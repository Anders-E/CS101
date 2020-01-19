#include <stdio.h>
#include <stdlib.h>

#include <CS101/sorting.h>
#include <CS101/linked_list.h>
#include <CS101/heap.h>
#include <CS101/util.h>

int main()
{
	int arr[10] = { 2, 4, 8, 1, 7, 14, 9, 10, 3, 16 };
	int n = 10;

	heapsort(arr, 0, 10);
	
	//struct heap heap = heap_new_max(arr, n);
	//
	array_print(arr, n);
	//heap_print(heap);
}
