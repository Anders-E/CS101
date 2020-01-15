#include <stdio.h>

#include "cs101.h"
#include "algorithms/sorting/sorting.h"

int main()
{
  int arr[8] = { 2, 16, 12071, 40, 77, 1, 5, 6 };
  int n = 8;

  insertion_sort(arr, 8);

  for (int i = 0; i < n; i++)
    printf("%d\n", arr[i]);
}
