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

  const int SENTINEL = INT_MAX;

  void merge(int arr[], int p, int q, int r)
  {
    int n1 = q - p;
    int n2 = r - q;

    int* left = new int[(unsigned long long) n1 + 1];
    int* right = new int[(unsigned long long) n2 + 1];

    for (int i = 0; i < n1; i++)
      left[i] = arr[p + i];
    for (int i = 0; i < n2; i++)
      right[i] = arr[q + i];

    left[n1 + 1] = right[n2 + 1] = SENTINEL;

    int i = 0;
    int j = 0;
    
    for (int k = p; k < r; k++) {

    }
  }

  void merge_sort(int arr[], int n)
  {

  }

}
