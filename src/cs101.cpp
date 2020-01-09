#include <iostream>

#include "cs101.h"
#include "algorithms/sorting.h"
#include "datastructures/linkedlist.h"

int main()
{
  int arr[8] = { 2, 16, 12071, 40, 77, 1, 5, 6 };
  int n = 8;

  sorting::merge(arr, 0, 2, 4);

  for (int i = 0; i < n; i++)
    std::cout << arr[i] << std::endl;
}
