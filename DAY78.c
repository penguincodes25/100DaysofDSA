#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAXN 1005

int n, m;
int graph[MAXN][MAXN];   // adjacency matrix

int primMST() {
    int key[MAXN];       // minimum edge weight to connect each node
    bool inMST[MAXN];    // whether node is already in MST
    int totalWeight = 0;

    // Initialize
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        inMST[i] = false;
    }

    // Start from node 1
    key[1] = 0;

    for (int count = 1; count <= n; count++) {
        // Pick minimum key vertex not yet in MST
        int u = -1, minKey = INT_MAX;
        for (int v = 1; v <= n; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = true;
        totalWeight += key[u];

        // Update keys of neighbors
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return totalWeight;
}

int main() {
    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;  // undirected
    }

    int mstWeight = primMST();
    printf("%d\n", mstWeight);

    return 0;
}
