#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[101];
    int count;
} Candidate;

// Compare function for qsort
int cmp(const void *a, const void *b) {
    Candidate *c1 = (Candidate*)a;
    Candidate *c2 = (Candidate*)b;
    if (c1->count != c2->count) {
        return c2->count - c1->count; // higher votes first
    }
    return strcmp(c1->name, c2->name); // lexicographically smaller first
}

int main() {
    int n;
    scanf("%d", &n);

    Candidate candidates[1000]; // assuming max 1000 distinct candidates
    int size = 0;

    for (int i = 0; i < n; i++) {
        char name[101];
        scanf("%s", name);

        // check if candidate already exists
        int found = -1;
        for (int j = 0; j < size; j++) {
            if (strcmp(candidates[j].name, name) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            candidates[found].count++;
        } else {
            strcpy(candidates[size].name, name);
            candidates[size].count = 1;
            size++;
        }
    }

    // sort candidates by votes (desc) and lexicographically (asc)
    qsort(candidates, size, sizeof(Candidate), cmp);

    // winner is first after sorting
    printf("%s %d\n", candidates[0].name, candidates[0].count);

    return 0;
}
