#ifndef SORTING_H
#define SORTING_H

void bubble_sort(int *first, int *last);
void bucket_sort(int *first, int *last);
void counting_sort(int *first, int *last, int k);
void heapsort(int *first, int *last);
void insertion_sort(int *first, int *last);
void merge_sort(int *first, int *last);
void quicksort(int *first, int *last);
void radix_sort(int *first, int *last, int radix);

#endif // !SORTING_H
