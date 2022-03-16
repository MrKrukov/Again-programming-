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

void shellSort(int *a, const size_t size) {
    for (int step = size / 2; step > 0; step /= 2)
        for (int i = step; i < size; ++i)
            for (int j = i - step; j >= 0 && a[j] > a[j + step]; j -= step)
                swap(&a[j], &a[j + step]);
}


unsigned long long getShellSortNComps(int *a, const size_t size) {
    unsigned long long nComps = 0;
    for (int step = size / 2; ++nComps && step > 0; step /= 2)
        for (int i = step; ++nComps && i < size; ++i)
            for (int j = i - step; ++nComps && j >= 0 && ++nComps && a[j] > a[j + step]; j -= step)
                swap(&a[j], &a[j + step]);

    return nComps;
}

int digit(int n, int k, int N, int M) {
    return (n >> (N * k) & (M - 1));
}

void radixSort(int *a, size_t size) {
    int N = 8;
    int *l = a;
    int *r = a + size;
    int k = (32 + N - 1) / N;
    int M = 1 << N;
    int sz = r - l;
    int *b = (int *) malloc(sizeof(int) * sz);
    int *c = (int *) malloc(sizeof(int) * M);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < M; j++)
            c[j] = 0;

        for (int *j = l; j < r; j++)
            c[digit(*j, i, N, M)]++;

        for (int j = 1; j < M; j++)
            c[j] += c[j - 1];

        for (int *j = r - 1; j >= l; j--)
            b[--c[digit(*j, i, N, M)]] = *j;

        int cur = 0;
        for (int *j = l; j < r; j++)
            *j = b[cur++];
    }
    free(b);
    free(c);
}

unsigned long long getRadixSortNComps(int *a, const size_t size) {
    int N = 8;
    int *l = a;
    int *r = a + size;
    int k = (32 + N - 1) / N;
    int M = 1 << N;
    int sz = r - l;
    int *b = (int *) malloc(sizeof(int) * sz);
    int *c = (int *) malloc(sizeof(int) * M);
    unsigned long long nComps = 0;
    for (int i = 0; ++nComps && i < k; i++) {
        for (int j = 0; ++nComps && j < M; j++) {
            c[j] = 0;
        }
        for (int *j = l; ++nComps && j < r; j++) {
            c[digit(*j, i, N, M)]++;
        }
        for (int j = 1; ++nComps && j < M; j++) {
            c[j] += c[j - 1];
        }

        for (int *j = r - 1; ++nComps && j >= l; j--) {
            b[--c[digit(*j, i, N, M)]] = *j;
        }
        int cur = 0;
        for (int *j = l; ++nComps && j < r; j++) {
            *j = b[cur++];
        }
    }
    free(b);
    free(c);

    return nComps;
}