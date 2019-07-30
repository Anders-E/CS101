// CS101.cpp : Defines the entry point for the application.
//

#include <iostream>

#include "CS101.h"
#include "sorting.h"

int main()
{
  int arr[8] = { 16, 2, 77, 40, 12071, 1, 5, 6 };
  int n = 8;

  bubble_sort(arr, n);

  for (int i = 0; i < n; i++)
    std::cout << arr[i] << std::endl;
}
