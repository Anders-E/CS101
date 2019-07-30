#include <utility>

#include "sorting.h"

void bubble_sort(int arr[], int n)
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

void insertion_sort(int arr[], int n)
{
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}
