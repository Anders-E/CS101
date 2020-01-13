#include "bubble_sort.h"

void sorting::bubble_sort(int arr[], int n)
{
  bool sorted = false;
  while (!sorted) {
    sorted = true;
    for (int i = 0; i < n - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        int tmp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = tmp;
        sorted = false;
      }
    }
  }
}
