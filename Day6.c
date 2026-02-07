#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // If array is empty or has 1 element, nothing to do
    if(n <= 1) {
        for(int i = 0; i < n; i++) {
            printf("%d", arr[i]);
            if(i < n-1) printf(" ");
        }
        printf("\n");
        return 0;
    }
    
    // Pointer to place the next unique element
    int unique = 0;
    
    // Traverse the array and keep only unique elements
    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[unique]) {
            unique++;
            arr[unique] = arr[i];
        }
    }
    
    // Print the first (unique + 1) elements
    for(int i = 0; i <= unique; i++) {
        printf("%d", arr[i]);
        if(i < unique) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}
