/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20*/
#include <stdio.h>
#include <string.h>

int pq[1000];
int size = 0;

void insert(int x) {
    pq[size++] = x;

    // sort to maintain priority
    for(int i = size - 1; i > 0; i--) {
        if(pq[i] < pq[i-1]) {
            int temp = pq[i];
            pq[i] = pq[i-1];
            pq[i-1] = temp;
        } else {
            break;
        }
    }
}

void delete() {
    if(size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[0]);

    for(int i = 1; i < size; i++)
        pq[i-1] = pq[i];

    size--;
}

void peek() {
    if(size == 0)
        printf("-1\n");
    else
        printf("%d\n", pq[0]);
}

int main() {
    int n, x;
    char op[10];

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%s", op);

        if(strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        }
        else if(strcmp(op, "delete") == 0) {
            delete();
        }
        else if(strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}