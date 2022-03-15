#ifndef LABA5C_SORT_H
#define LABA5C_SORT_H

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

void outputArray_(int *a, size_t size);

int isOrdered(int *a, size_t size);

void swap(int *a, int *b);

void generateRandomArray(int *a, size_t size);

void generateOrderedArray(int *a, size_t size);

void generateOrderedBackwards(int *a, size_t size);

void selectionSort(int *a, size_t size);

unsigned long long getSelectionSortNComps(int *a, size_t n);

#endif //LABA5C_SORT_H