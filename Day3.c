#include <stdio.h>

int main() {
    int n, key;
    int comparisons = 0;
    int foundIndex = -1;

    // Input array size
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key to search
    scanf("%d", &key);

    // Linear search
    for(int i = 0; i < n; i++) {
        comparisons++;
        if(arr[i] == key) {
            foundIndex = i;
            break;
        }
    }

    // Output
    if(foundIndex != -1)
        printf("Found at index %d\n", foundIndex);
    else
        printf("Not Found\n");

    printf("Comparisons = %d", comparisons);

    return 0;
}
