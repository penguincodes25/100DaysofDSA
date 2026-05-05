#include <stdio.h>
#include <stdlib.h>

// Structure for interval
typedef struct {
    int start;
    int end;
} Interval;

// Comparator for sorting by start time
int cmp(const void* a, const void* b) {
    Interval* i1 = (Interval*)a;
    Interval* i2 = (Interval*)b;
    return i1->start - i2->start;
}

// Min-heap for end times
typedef struct {
    int* data;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->data = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(int* a, int* b) {
    int temp = *a; *a = *b; *b = temp;
}

void heapifyUp(MinHeap* heap, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap->data[parent] <= heap->data[idx]) break;
        swap(&heap->data[parent], &heap->data[idx]);
        idx = parent;
    }
}

void heapifyDown(MinHeap* heap, int idx) {
    while (2 * idx + 1 < heap->size) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int smallest = left;
        if (right < heap->size && heap->data[right] < heap->data[left]) {
            smallest = right;
        }
        if (heap->data[idx] <= heap->data[smallest]) break;
        swap(&heap->data[idx], &heap->data[smallest]);
        idx = smallest;
    }
}

void push(MinHeap* heap, int val) {
    heap->data[heap->size++] = val;
    heapifyUp(heap, heap->size - 1);
}

int pop(MinHeap* heap) {
    int root = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    heapifyDown(heap, 0);
    return root;
}

int top(MinHeap* heap) {
    return heap->data[0];
}

int minMeetingRooms(Interval* intervals, int n) {
    if (n == 0) return 0;

    // Sort by start time
    qsort(intervals, n, sizeof(Interval), cmp);

    MinHeap* heap = createHeap(n);

    // Process intervals
    for (int i = 0; i < n; i++) {
        if (heap->size > 0 && top(heap) <= intervals[i].start) {
            pop(heap); // free room
        }
        push(heap, intervals[i].end); // occupy room
    }

    int result = heap->size;
    free(heap->data);
    free(heap);
    return result;
}

int main() {
    int n;
    printf("Enter number of meetings: ");
    scanf("%d", &n);

    Interval* intervals = (Interval*)malloc(n * sizeof(Interval));
    printf("Enter %d intervals (start end):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    int rooms = minMeetingRooms(intervals, n);
    printf("Minimum rooms required: %d\n", rooms);

    free(intervals);
    return 0;
}
