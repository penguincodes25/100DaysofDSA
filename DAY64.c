#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int front, rear;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(capacity * sizeof(int));
    q->front = 0;
    q->rear = 0;
    q->capacity = capacity;
    return q;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, int val) {
    q->data[q->rear++] = val;
}

int dequeue(Queue* q) {
    return q->data[q->front++];
}

void bfs(int s, int** adj, int* sizes, int n) {
    int* visited = (int*)calloc(n, sizeof(int));
    Queue* q = createQueue(n);

    visited[s] = 1;
    enqueue(q, s);

    while (!isEmpty(q)) {
        int v = dequeue(q);
        printf("%d ", v);

        for (int i = 0; i < sizes[v]; i++) {
            int neighbor = adj[v][i];
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                enqueue(q, neighbor);
            }
        }
    }

    free(visited);
    free(q->data);
    free(q);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // adjacency list
    int** adj = (int**)malloc(n * sizeof(int*));
    int* sizes = (int*)calloc(n, sizeof(int));
    int* capacity = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        capacity[i] = 2;
        adj[i] = (int*)malloc(capacity[i] * sizeof(int));
    }

    // read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (sizes[u] == capacity[u]) {
            capacity[u] *= 2;
            adj[u] = (int*)realloc(adj[u], capacity[u] * sizeof(int));
        }
        adj[u][sizes[u]++] = v;

        // for undirected graph, also add u to v
        // uncomment if needed:
        /*
        if (sizes[v] == capacity[v]) {
            capacity[v] *= 2;
            adj[v] = (int*)realloc(adj[v], capacity[v] * sizeof(int));
        }
        adj[v][sizes[v]++] = u;
        */
    }

    int s;
    scanf("%d", &s);

    bfs(s, adj, sizes, n);

    // cleanup
    for (int i = 0; i < n; i++) free(adj[i]);
    free(adj);
    free(sizes);
    free(capacity);

    return 0;
}