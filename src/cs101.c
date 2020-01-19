#include <stdio.h>
#include <stdlib.h>

#include <CS101/sorting.h>
#include <CS101/linked_list.h>
#include <CS101/heap.h>
#include <CS101/util.h>

int main()
{
	int arr[5] = { 157, 671, 306, 713, 290 };
	int n = 5;

	radix_sort(arr, 0, n);
	
	array_print(arr, n);
}
