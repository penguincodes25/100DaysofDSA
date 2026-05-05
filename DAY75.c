#include <stdio.h>
#include <stdlib.h>

// Structure to store prefix sum and its first index
typedef struct {
    int sum;
    int index;
} Prefix;

int longestZeroSumSubarray(int arr[], int n) {
    // Array to store prefix sums and their first occurrence
    Prefix *map = (Prefix*)malloc(n * sizeof(Prefix));
    int mapSize = 0;

    int maxLen = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            if (i + 1 > maxLen) maxLen = i + 1;
        }

        // Check if this sum was seen before
        int found = -1;
        for (int j = 0; j < mapSize; j++) {
            if (map[j].sum == sum) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            int len = i - map[found].index;
            if (len > maxLen) maxLen = len;
        } else {
            map[mapSize].sum = sum;
            map[mapSize].index = i;
            mapSize++;
        }
    }

    free(map);
    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = longestZeroSumSubarray(arr, n);
    printf("%d\n", result);

    return 0;
}
