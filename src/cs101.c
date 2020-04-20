#include <stdio.h>
#include <stdlib.h>
#include <CS101/sorting.h>
#include <CS101/util.h>

int main()
{
	int arr[6] = { 3, 2, 5, 6, 1, 4};
	merge_sort(arr, arr + 6);
	array_print(arr, arr + 6);
}
