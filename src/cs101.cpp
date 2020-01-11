#include <iostream>

#include "cs101.h"
#include "algorithms/sorting/merge_sort.h"
#include "data_structures/linkedlist.h"
#include "data_structures/binary_search_tree.h"

int main()
{
  /*
  data_structures::binary_search_tree tree = data_structures::binary_search_tree();

  tree.insert(8);
  tree.insert(3);
  tree.insert(10);
  tree.insert(1);
  tree.insert(6);
  tree.insert(4);
  tree.insert(7);
  tree.insert(14);
  tree.insert(13);

  std::cout << tree << std::endl;
  */

  int arr[8] = { 2, 16, 12071, 40, 77, 1, 5, 6 };
  int n = 8;

  sorting::merge_sort(arr, 8);

  for (int i = 0; i < n; i++)
    std::cout << arr[i] << std::endl;
}
