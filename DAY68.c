#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int degree[MAX];   // adjacency list size for each vertex
int indegree[MAX]; // in-degree array

// Simple queue implementation
int queue[MAX], front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void topologicalSort(int n) {
    // Initialize in-degree array
    for (int i = 0; i < n; i++) indegree[i] = 0;

    // Compute in-degree of each vertex
    for (int u = 0; u < n; u++) {
        for (int i = 0; i < degree[u]; i++) {
            int v = graph[u][i];
            indegree[v]++;
        }
    }

    // Enqueue all vertices with in-degree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;
    printf("Topological Ordering: ");
    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);
        count++;

        // Decrease in-degree of neighbors
        for (int i = 0; i < degree[u]; i++) {
            int v = graph[u][i];
            indegree[v]--;
            if (indegree[v] == 0) {
                enqueue(v);
            }
        }
    }
    printf("\n");

    // If count != n, graph has a cycle
    if (count != n) {
        printf("Graph is not a DAG (cycle exists)\n");
    }
}

int main() {
    int n, e;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    for (int i = 0; i < n; i++) degree[i] = 0;

    printf("Enter directed edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][degree[u]++] = v; // directed edge
    }

    topologicalSort(n);
    return 0;
}