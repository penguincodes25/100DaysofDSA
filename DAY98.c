#include <stdio.h>
#include <stdlib.h>

// Interval structure
typedef struct {
    int start;
    int end;
} Interval;

// Comparator for qsort: sort by start time
int cmp(const void* a, const void* b) {
    Interval* i1 = (Interval*)a;
    Interval* i2 = (Interval*)b;
    return i1->start - i2->start;
}

// Merge overlapping intervals
int mergeIntervals(Interval* intervals, int n, Interval* result) {
    if (n == 0) return 0;

    // Sort intervals by start
    qsort(intervals, n, sizeof(Interval), cmp);

    int idx = 0; // index for result
    result[idx] = intervals[0];

    for (int i = 1; i < n; i++) {
        if (intervals[i].start <= result[idx].end) {
            // Overlap → extend end
            if (intervals[i].end > result[idx].end) {
                result[idx].end = intervals[i].end;
            }
        } else {
            // No overlap → new interval
            idx++;
            result[idx] = intervals[i];
        }
    }

    return idx + 1; // number of merged intervals
}

int main() {
    int n;
    printf("Enter number of intervals: ");
    scanf("%d", &n);

    Interval* intervals = (Interval*)malloc(n * sizeof(Interval));
    printf("Enter %d intervals (start end):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    Interval* result = (Interval*)malloc(n * sizeof(Interval));
    int mergedCount = mergeIntervals(intervals, n, result);

    printf("Merged intervals:\n");
    for (int i = 0; i < mergedCount; i++) {
        printf("[%d,%d]\n", result[i].start, result[i].end);
    }

    free(intervals);
    free(result);
    return 0;
}
