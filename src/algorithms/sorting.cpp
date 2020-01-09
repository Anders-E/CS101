#include <utility>

#include "sorting.h"

namespace sorting {

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

  const int SENTINEL = 999999;

  void merge(int arr[], int p, int q, int r)
  {
    int n1 = q - p + 1;
    int n2 = r - q;

    int* left = new int[n1 + 1];
    int* right = new int[n2 + 1];

    for (int i = 0; i < n1; i++)
      left[i] = arr[p + i];
    for (int i = 0; i < n2; i++)
      right[i] = arr[q + i + 1];

    left[n1] = SENTINEL;
    right[n2] = SENTINEL;

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++) {
      if (left[i] <= right[j]) {
        arr[k] = left[i];
        i++;
      } else {
        arr[k] = right[j];
        j++;
      }
    }

    delete[] left;
    delete[] right;
  }

  void merge_sort(int arr[], int n)
  {

  }

}
