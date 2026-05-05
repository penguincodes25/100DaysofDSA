#include <stdio.h>
#include <stdlib.h>

void dfs(int v, int** adj, int* sizes, int* visited) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < sizes[v]; i++) {
        int neighbor = adj[v][i];
        if (!visited[neighbor]) {
            dfs(neighbor, adj, sizes, visited);
        }
    }
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

        // add v to u's list
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

    int* visited = (int*)calloc(n, sizeof(int));

    dfs(s, adj, sizes, visited);

    // cleanup
    for (int i = 0; i < n; i++) free(adj[i]);
    free(adj);
    free(sizes);
    free(capacity);
    free(visited);

    return 0;
}