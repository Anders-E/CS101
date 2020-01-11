#include <utility>
#include <limits>

#include "merge_sort.h"

namespace sorting {

  const int SENTINEL = std::numeric_limits<int>::max();

  void merge(int arr[], int p, int q, int r)
  {
    int n1 = q - p + 1;
    int n2 = r - q;

    // TODO: Get rid of these dynamic allocations
    int* left = new int[(unsigned long long) n1 + 1];
    int* right = new int[(unsigned long long) n2 + 1];

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

  void merge_sort(int arr[], int p, int r)
  {
    if (p < r) {
      int q = (p + r) / 2;
      merge_sort(arr, p, q);
      merge_sort(arr, q + 1, r);
      merge(arr, p, q, r);
    }
  }

  void merge_sort(int arr[], int n)
  {
    merge_sort(arr, 0, n - 1);
  }

}
