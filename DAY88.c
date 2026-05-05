#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int canPlace(int stalls[], int n, int k, int dist) {
    int count = 1; // place first cow at stalls[0]
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
            if (count >= k) return 1; // successfully placed all cows
        }
    }
    return 0;
}

int maxDistance(int stalls[], int n, int k) {
    qsort(stalls, n, sizeof(int), cmp);

    int left = 1;
    int right = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canPlace(stalls, n, k, mid)) {
            ans = mid;       // candidate answer
            left = mid + 1;  // try larger distance
        } else {
            right = mid - 1; // try smaller distance
        }
    }
    return ans;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int stalls[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    printf("%d\n", maxDistance(stalls, n, k));
    return 0;
}
