#include <stdio.h>

#include <sorting.h>

int main()
{
	int arr[8] = { 64, 3, 1324, 0, 643, 1, 1236161, 6 };
	int n = 8;

	quicksort(arr, 8);

	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
}
