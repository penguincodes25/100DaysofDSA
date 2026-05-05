#include <stdio.h>

int integerSqrt(int n) {
    if (n == 0 || n == 1) return n;

    int left = 0, right = n, ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long sq = (long long)mid * mid; // avoid overflow

        if (sq == n) {
            return mid; // perfect square
        } else if (sq < n) {
            ans = mid;       // candidate answer
            left = mid + 1;  // search higher
        } else {
            right = mid - 1; // search lower
        }
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", integerSqrt(n));
    return 0;
}
