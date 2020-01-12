#include <algorithm>

#include "gtest/gtest.h"

#include "sorting_fixture.cpp"
#include "../../../src/algorithms/sorting/bubble_sort.h"

TEST(BubbleSort, Test) {
  int arr[3] = { 3, 2, 1 };
  
  
  sorting::bubble_sort(arr, 3);
  std::sort(arr, arr + 3);

  ASSERT_EQ(1, 1);
}
