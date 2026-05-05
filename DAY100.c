#include <stdio.h>
#include <stdlib.h>

// Structure to keep value and original index
typedef struct {
    int val;
    int idx;
} Pair;

long long merge(Pair* arr, int left, int mid, int right, int* count) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Pair L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    long long invCount = 0;

    while (i < n1 && j < n2) {
        if (L[i].val <= R[j].val) {
            arr[k++] = L[i];
            count[L[i].idx] += j; // j elements from right are smaller
            i++;
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i];
        count[L[i].idx] += j;
        i++;
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }

    return invCount;
}

void mergeSort(Pair* arr, int left, int right, int* count) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, count);
        mergeSort(arr, mid + 1, right, count);
        merge(arr, left, mid, right, count);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Pair pairs[n];
    for (int i = 0; i < n; i++) {
        pairs[i].val = arr[i];
        pairs[i].idx = i;
    }

    int* count = (int*)calloc(n, sizeof(int));

    mergeSort(pairs, 0, n - 1, count);

    printf("Counts of smaller elements to the right:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }
    printf("\n");

    free(count);
    return 0;
}
