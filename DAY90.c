#include <stdio.h>
#include <stdlib.h>

// Helper function to check if allocation is possible
int isPossible(int* boards, int n, int k, int maxLen) {
    int painters = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxLen) return 0; // single board exceeds limit
        if (sum + boards[i] > maxLen) {
            painters++;
            sum = boards[i];
            if (painters > k) return 0;
        } else {
            sum += boards[i];
        }
    }
    return 1;
}

int minTimeToPaint(int* boards, int n, int k) {
    int low = boards[0], high = 0;
    for (int i = 0; i < n; i++) {
        if (boards[i] > low) low = boards[i]; // largest single board
        high += boards[i]; // total sum
    }

    int result = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(boards, n, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int* boards = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    int answer = minTimeToPaint(boards, n, k);
    printf("%d\n", answer);

    free(boards);
    return 0;
}
