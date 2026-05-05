#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
int degree[MAX];  // adjacency list size for each vertex

bool dfs(int v, bool visited[], bool recStack[]) {
    visited[v] = true;
    recStack[v] = true;

    for (int i = 0; i < degree[v]; i++) {
        int neighbor = graph[v][i];
        if (!visited[neighbor]) {
            if (dfs(neighbor, visited, recStack))
                return true;
        } else if (recStack[neighbor]) {
            return true; // cycle detected
        }
    }

    recStack[v] = false; // backtrack
    return false;
}

const char* detectCycle(int n) {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack))
                return "YES";
        }
    }
    return "NO";
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

    printf("%s\n", detectCycle(n));
    return 0;
}