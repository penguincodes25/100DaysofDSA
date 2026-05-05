//You are given a rectangular matrix of integers.
// Starting from the outer boundary, traverse the matrix in a clockwise manner 
//and continue moving inward layer by layer until all elements are visited.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    
    int **matrix = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        matrix[i] = (int*)malloc(c * sizeof(int));
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int result[1000];  // Assuming max 1000 elements
    int idx = 0;
    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;
    
    while (top <= bottom && left <= right) {
        // Right
        for (int col = left; col <= right; col++) {
            result[idx++] = matrix[top][col];
        }
        top++;
        
        // Down
        for (int row = top; row <= bottom; row++) {
            result[idx++] = matrix[row][right];
        }
        right--;
        
        // Left
        if (top <= bottom) {
            for (int col = right; col >= left; col--) {
                result[idx++] = matrix[bottom][col];
            }
            bottom--;
        }
        
        // Up
        if (left <= right) {
            for (int row = bottom; row >= top; row--) {
                result[idx++] = matrix[row][left];
            }
            left++;
        }
    }
    
    // Print result
    for (int i = 0; i < idx; i++) {
        printf("%d", result[i]);
        if (i < idx - 1) printf(" ");
    }
    printf("\n");
    
    // Free memory
    for (int i = 0; i < r; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return 0;
}