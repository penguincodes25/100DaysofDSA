#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
int degree[MAX];   // adjacency list size for each vertex
int stack[MAX];    // to store topological order
int top = -1;

void dfs(int v, bool visited[]) {
    visited[v] = true;

    for (int i = 0; i < degree[v]; i++) {
        int neighbor = graph[v][i];
        if (!visited[neighbor]) {
            dfs(neighbor, visited);
        }
    }

    // push to stack after visiting all neighbors
    stack[++top] = v;
}

void topologicalSort(int n) {
    bool visited[MAX] = {false};

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, visited);
        }
    }

    // print stack in reverse order
    printf("Topological Ordering: ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
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