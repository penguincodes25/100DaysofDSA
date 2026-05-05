#include <stdio.h>
#include <limits.h>

#define INF 1000000000  // large value to represent infinity
#define MAXN 105

int main() {
    int n;
    scanf("%d", &n);

    int dist[MAXN][MAXN];

    // Read adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int w;
            scanf("%d", &w);
            if (w == -1 && i != j) {
                dist[i][j] = INF;  // no edge
            } else {
                dist[i][j] = w;
            }
        }
    }

    // Floyd–Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print shortest distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] >= INF) printf("-1 ");
            else printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
