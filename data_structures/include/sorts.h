#ifndef SORTS_H
#define SORTS_H

#include <stddef.h>
size_t BinarySearch(size_t arr[], size_t low, size_t high, size_t search);
size_t BinarySearchRecursive(size_t arr[], size_t low, size_t high, size_t search);
void BubbleSort(int arr[], int size);
void SelectionSort(int arr[], int size);
void InsertionSort(int arr[], int size);
void CountingSort(int arr[], int size);
void QuickSort(int *arr, int low, int high);	










#endif 		/* 	 SORTS_H 	*/
