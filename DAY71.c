#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -1

int m;          // table size
int *table;     // hash table

// Base hash function
int h(int k) {
    return k % m;
}

// Insert using quadratic probing
void insert(int key) {
    for (int i = 0; i < m; i++) {
        int idx = (h(key) + i*i) % m;
        if (table[idx] == EMPTY) {
            table[idx] = key;
            return;
        }
    }
    // If table is full, do nothing (could print error)
}

// Search using quadratic probing
int search(int key) {
    for (int i = 0; i < m; i++) {
        int idx = (h(key) + i*i) % m;
        if (table[idx] == EMPTY) return 0; // not found
        if (table[idx] == key) return 1;   // found
    }
    return 0;
}

int main() {
    int n; // number of operations
    scanf("%d", &m);
    scanf("%d", &n);

    table = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) table[i] = EMPTY;

    char op[10];
    int key;
    for (int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);
        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(key)) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }

    free(table);
    return 0;
}