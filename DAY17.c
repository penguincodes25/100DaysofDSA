//Write a program to find the maximum and minimum values present in a given array of integers.
/*
Sample Test Cases:

Input 1:
6
3 5 1 9 2 8

Output 1:
Max: 9
Min: 1


Input 2:
5
10 20 30 40 50

Output 2:
Max: 50
Min: 10


Input 3:
4
-5 -2 -9 -1

Output 3:
Max: -1
Min: -9


Input 4:
1
100

Output 4:
Max: 100
Min: 100


Input 5:
7
7 7 7 7 7 7 7

Output 5:
Max: 7
Min: 7
*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    int min = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max)
            max = arr[i];

        if(arr[i] < min)
            min = arr[i];
    }

    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}