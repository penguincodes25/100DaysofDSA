#include <stdio.h>
#include <stdlib.h>

// Helper function to check if allocation is possible
int isPossible(int* pages, int n, int m, int maxPages) {
    int students = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (pages[i] > maxPages) return 0; // single book exceeds limit
        if (sum + pages[i] > maxPages) {
            students++;
            sum = pages[i];
            if (students > m) return 0;
        } else {
            sum += pages[i];
        }
    }
    return 1;
}

int allocateBooks(int* pages, int n, int m) {
    if (m > n) return -1; // not enough books

    int low = pages[0], high = 0;
    for (int i = 0; i < n; i++) {
        if (pages[i] > low) low = pages[i]; // max single book
        high += pages[i]; // total sum
    }

    int result = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(pages, n, m, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int* pages = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    int answer = allocateBooks(pages, n, m);
    printf("%d\n", answer);

    free(pages);
    return 0;
}
