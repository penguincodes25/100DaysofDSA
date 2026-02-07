#include <stdio.h>

int main() {
    int p, q;
    
    // Read size of first log
    scanf("%d", &p);
    int log1[p];
    for(int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }
    
    // Read size of second log
    scanf("%d", &q);
    int log2[q];
    for(int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }
    
    // Result array (size = p + q)
    int result[p + q];
    int i = 0;      // pointer for log1
    int j = 0;      // pointer for log2
    int k = 0;      // pointer for result
    
    // Merge two sorted arrays
    while(i < p && j < q) {
        if(log1[i] <= log2[j]) {
            result[k] = log1[i];
            i++;
        } else {
            result[k] = log2[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements from log1 (if any)
    while(i < p) {
        result[k] = log1[i];
        i++;
        k++;
    }
    
    // Copy remaining elements from log2 (if any)
    while(j < q) {
        result[k] = log2[j];
        j++;
        k++;
    }
    
    // Print the merged result
    for(int m = 0; m < p + q; m++) {
        printf("%d", result[m]);
        if(m < p + q - 1) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}
