#include <stdio.h>
#include <stdlib.h>
#include <CS101/sorting.h>
#include <CS101/util.h>

int main()
{
	int arr[6] = { 3, 2, 5, 6, 1, 4};
	CS101_merge_sort(arr, arr + 6);
	print_array(arr, arr + 6);
}
