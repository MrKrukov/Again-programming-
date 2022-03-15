#include "sort.h"

void outputArray_(int *a, size_t size) {
    for (int i = 0; i < size; i++)
        printf("%d", a[i]);
}

int isOrdered(int *a, size_t size) {
    for (int i = 0; i < size - 1; i++)
        if (a[i] > a[i + 1])
            return 0;

    return 1;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void generateRandomArray(int *a, size_t size) {
    srand(time(0));
    for (int i = 0; i < size; i++)
        a[i] = rand() % 1000 + 42;
}

void generateOrderedArray(int *a, size_t size) {
    for (int i = 0; i < size; i++)
        a[i] = i;
}

void generateOrderedBackwards(int *a, size_t size) {
    int i = 0;
    int j = size - 1;
    while (j >= 0)
        a[i++] = j--;
}

void selectionSort(int *a, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < size; j++)
            if ( a [j] < a [minPos])
                minPos = j;
        swap (&a[i], &a[minPos]);
    }
}

unsigned long long getSelectionSortNComps(int *a, size_t n) {
    unsigned long long nComps = 0;
    for (int i = 0; ++nComps && i < n; i++) {
        int min = a[i];
        int minIndex = i;
        for (int j = i + 1; ++nComps && j < n; j++)
            if (++nComps && a[j] < min) {
                min = a[j];
                minIndex = j;
            }
        if (++nComps && i != minIndex)
            swap(&a[i], &a[minIndex]);
    }

    return nComps;
}

void bubbleSort(int *a, const size_t size) {
    for (int i = 0; i < size; ++i)
        for (int j = i; j < size; ++j)
            if (a[i] > a[j])
                swap(&a[i], &a[j]);
}

unsigned long long getBubbleSortNComps(int *a, const size_t size) {
    unsigned long long nComps = 0;
    for (int i = 0; ++nComps && i < size; ++i)
        for (int j = i; ++nComps && j < size; ++j)
            if (++nComps && a[i] > a[j]) {
                swap(&a[i], &a[j]);
            }

    return nComps;
}

void insertionSort(int *a, const size_t size) {
    for (size_t i = 1; i < size; i++) {
        int t = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}

unsigned long long getInsertionSortNComps(int *a, const size_t size) {
    unsigned long long nComps = 0;
    for (size_t i = 1; ++nComps && i < size; i++) {
        int t = a[i];
        int j = i;
        while (++nComps && j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }

    return nComps;
}

void combsort(int *a, const size_t size) {
    size_t step = size;
    int swapped = 1;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= 1.24733;
        swapped = 0;
        for (size_t i = 0, j = i + step; j < size; ++i, ++j)
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
                swapped = 1;
            }
    }
}

unsigned long long getCombsortNComps(int *a, const size_t size) {
    size_t step = size;
    int swapped = 1;
    unsigned long long nComps = 2;
    while (++nComps && step > 1 || swapped) {
        if (++nComps && step > 1) {
            step /= 1.24733;
        }
        swapped = 0;
        for (size_t i = 0, j = i + step; ++nComps && j < size; ++i, ++j)
            if (++nComps && a[i] > a[j]) {
                swap(&a[i], &a[j]);
                swapped = 1;
            }
    }

    return nComps;
}

