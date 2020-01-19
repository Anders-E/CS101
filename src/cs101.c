#include <stdio.h>
#include <stdlib.h>

#include <CS101/sorting.h>
#include <CS101/linked_list.h>
#include <CS101/heap.h>
#include <CS101/util.h>

int main()
{
	int arr[6] = {
		57102375,
		35759206,
		47592010,
		58320837,
		45721513,
		15701475
	};
	int n = 6;

	radix_sort(arr, 0, n, 8);
	
	array_print(arr, n);
}
