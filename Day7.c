#include <stdio.h>

// Recursive function to compute the n-th Fibonacci number
int fib(int n) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    // Recursive case: fib(n) = fib(n-1) + fib(n-2)
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    scanf("%d", &n);
    
    // Handle negative input (though usually not required)
    if (n < 0) {
        printf("Invalid input\n");
        return 1;
    }
    
    printf("%d\n", fib(n));
    
    return 0;
}
