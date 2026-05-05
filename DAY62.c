#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // adjacency list: array of int* with sizes
    int** adj = (int**)malloc(n * sizeof(int*));
    int* sizes = (int*)calloc(n, sizeof(int));   // track size of each list
    int* capacity = (int*)malloc(n * sizeof(int)); // track capacity for each list

    for (int i = 0; i < n; i++) {
        capacity[i] = 2; // initial capacity
        adj[i] = (int*)malloc(capacity[i] * sizeof(int));
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Add v to u's list
        if (sizes[u] == capacity[u]) {
            capacity[u] *= 2;
            adj[u] = (int*)realloc(adj[u], capacity[u] * sizeof(int));
        }
        adj[u][sizes[u]++] = v;

        // For undirected graph, also add u to v's list
        // Uncomment below if undirected:
        /*
        if (sizes[v] == capacity[v]) {
            capacity[v] *= 2;
            adj[v] = (int*)realloc(adj[v], capacity[v] * sizeof(int));
        }
        adj[v][sizes[v]++] = u;
        */
    }

    // Print adjacency lists
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        for (int j = 0; j < sizes[i]; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(sizes);
    free(capacity);

    return 0;
}