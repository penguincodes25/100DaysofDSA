#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int front;
    int rear;
    int capacity;
} Queue;

Queue* createQueue(int n) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->capacity = n;
    q->array = (int*)malloc(q->capacity * sizeof(int));
    q->front = 0;
    q->rear = 0;
    return q;
}

void enqueue(Queue* q, int value) {
    if (q->rear < q->capacity) {
        q->array[q->rear++] = value;
    }
}

void display(Queue* q) {
    for (int i = q->front; i < q->rear; i++) {
        printf("%d%s", q->array[i], (i == q->rear - 1) ? "" : " ");
    }
    printf("\n");
}

int main() {
    int n, value;
    if (scanf("%d", &n) != 1) return 0;

    Queue* q = createQueue(n);

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &value) == 1) {
            enqueue(q, value);
        }
    }

    display(q);

    free(q->array);
    free(q);

    return 0;
}