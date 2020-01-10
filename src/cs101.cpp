#include <iostream>

#include "cs101.h"
#include "algorithms/sorting.h"
#include "data_structures/linkedlist.h"

int main()
{
  int arr[8] = { 2, 16, 12071, 40, 77, 1, 5, 6 };
  int n = 8;

  sorting::merge_sort(arr, 8);

  for (int i = 0; i < n; i++)
    std::cout << arr[i] << std::endl;
}
