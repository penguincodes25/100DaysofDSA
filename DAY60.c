#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Check Min-Heap property
    for (int i = 0; i < N; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < N && arr[i] > arr[left]) {
            printf("NO\n");
            return 0;
        }
        if (right < N && arr[i] > arr[right]) {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");
    return 0;
}