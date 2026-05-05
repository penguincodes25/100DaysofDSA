#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Adjacency list representation
int graph[MAX][MAX];
int degree[MAX];  // number of neighbors for each vertex

bool dfs(int v, bool visited[], int parent) {
    visited[v] = true;

    for (int i = 0; i < degree[v]; i++) {
        int neighbor = graph[v][i];
        if (!visited[neighbor]) {
            if (dfs(neighbor, visited, v))
                return true;
        } else if (neighbor != parent) {
            return true; // cycle detected
        }
    }
    return false;
}

const char* detectCycle(int n) {
    bool visited[MAX] = {false};

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, -1))
                return "YES";
        }
    }
    return "NO";
}

int main() {
    int n, e;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    // Initialize adjacency list
    for (int i = 0; i < n; i++) degree[i] = 0;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][degree[u]++] = v;
        graph[v][degree[v]++] = u; // undirected
    }

    printf("%s\n", detectCycle(n));
    return 0;
}