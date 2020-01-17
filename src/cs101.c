#include <stdio.h>
#include <stdlib.h>

#include <sorting.h>
#include <linked_list.h>

int main()
{
	//int arr[8] = { 2, 3, 1, 0, 9, 1, 8, 6 };
	//int n = 8;

	//quicksort(arr, 0, 8);

	//for (int i = 0; i < n; i++)
	//	printf("%d\n", arr[i]);

	struct linked_list *list = linked_list_new();

	linked_list_append(list, 0);
	linked_list_append(list, 1);
	linked_list_append(list, 2);
	linked_list_append(list, 3);
	linked_list_insert(list, 99, 4);
	linked_list_set(list, -99, 0);
	linked_list_remove(list, 4);

	linked_list_print(list);

	linked_list_free(list);
}
