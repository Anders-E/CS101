#include <stdio.h>

#include <sorting.h>

int main()
{
	int arr[8] = { 2, 3, 1, 0, 9, 1, 8, 6 };
	int n = 8;

	quicksort(arr, 0, 8);

	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
}
