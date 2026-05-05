#include <stdio.h>
#include <stdlib.h>

// Insertion sort for small buckets
void insertionSort(double arr[], int n) {
    for (int i = 1; i < n; i++) {
        double key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Bucket Sort
void bucketSort(double arr[], int n) {
    // Step 1: Create n empty buckets
    double* buckets[n];
    int bucketSizes[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = (double*)malloc(n * sizeof(double));
        bucketSizes[i] = 0;
    }

    // Step 2: Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int idx = (int)(arr[i] * n); // bucket index
        buckets[idx][bucketSizes[idx]++] = arr[i];
    }

    // Step 3: Sort each bucket
    for (int i = 0; i < n; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
        }
    }

    // Step 4: Concatenate buckets back into arr
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[k++] = buckets[i][j];
        }
        free(buckets[i]);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    double arr[n];
    printf("Enter %d real numbers in [0,1):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    return 0;
}
