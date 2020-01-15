#include "sorting.h"

void bubble_sort(int arr[], int n)
{
  int sorted = 0;
  while (!sorted) {
    sorted = 1;
    for (int i = 0; i < n - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        int tmp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = tmp;
        sorted = 0;
      }
    }
  }
}
