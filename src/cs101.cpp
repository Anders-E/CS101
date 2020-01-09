#include <iostream>

#include "cs101.h"
#include "algorithms/sorting.h"
#include "datastructures/linkedlist.h"

int main()
{
  int arr[8] = { 16, 2, 77, 40, 12071, 1, 5, 6 };
  int n = 8;

  //sorting::bubble_sort(arr, n);

  //for (int i = 0; i < n; i++)
  //  std::cout << arr[i] << std::endl;

  datastructures::singly_linked_list list = datastructures::singly_linked_list(arr, n);
  //list.append(1);
  //list.append(2);
  std::cout << list << std::endl;
  std::cout << list.length() << std::endl;
  std::cout << list.get(3) << std::endl;
  list.insert(-1, 3);
  std::cout << list << std::endl;
  std::cout << list.remove(3) << std::endl;
  std::cout << list << std::endl;
  std::cout << list.remove(8) << std::endl;
}
