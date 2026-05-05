#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 1005

int n, m;
int adj[MAXN][MAXN];   // adjacency matrix
int deg[MAXN];         // degree of each node
bool visited[MAXN];

void dfs(int u) {
    visited[u] = true;
    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    // Build adjacency list
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][deg[u]++] = v;
        adj[v][deg[v]++] = u;  // undirected
    }

    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    printf("%d\n", components);
    return 0;
}
