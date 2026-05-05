#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 1005
#define INF INT_MAX

// Min-heap node
struct HeapNode {
    int vertex;
    int dist;
};

// Min-heap structure
struct MinHeap {
    struct HeapNode* arr[MAXN];
    int size;
};

// Create new heap node
struct HeapNode* newNode(int v, int d) {
    struct HeapNode* node = (struct HeapNode*)malloc(sizeof(struct HeapNode));
    node->vertex = v;
    node->dist = d;
    return node;
}

// Swap
void swap(struct HeapNode** a, struct HeapNode** b) {
    struct HeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify
void heapify(struct MinHeap* heap, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < heap->size && heap->arr[l]->dist < heap->arr[smallest]->dist)
        smallest = l;
    if (r < heap->size && heap->arr[r]->dist < heap->arr[smallest]->dist)
        smallest = r;

    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        heapify(heap, smallest);
    }
}

// Extract min
struct HeapNode* extractMin(struct MinHeap* heap) {
    if (heap->size == 0) return NULL;
    struct HeapNode* root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    return root;
}

// Insert
void insertHeap(struct MinHeap* heap, struct HeapNode* node) {
    int i = heap->size++;
    heap->arr[i] = node;
    while (i != 0 && heap->arr[(i-1)/2]->dist > heap->arr[i]->dist) {
        swap(&heap->arr[i], &heap->arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Graph adjacency list
struct Edge {
    int v, w;
};
struct Edge* adj[MAXN][MAXN];
int deg[MAXN];

void dijkstra(int n, int source) {
    int dist[MAXN];
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[source] = 0;

    struct MinHeap heap;
    heap.size = 0;
    insertHeap(&heap, newNode(source, 0));

    while (heap.size > 0) {
        struct HeapNode* node = extractMin(&heap);
        int u = node->vertex;
        int d = node->dist;
        free(node);

        if (d > dist[u]) continue;

        for (int i = 0; i < deg[u]; i++) {
            int v = adj[u][i]->v;
            int w = adj[u][i]->w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                insertHeap(&heap, newNode(v, dist[v]));
            }
        }
    }

    // Print distances
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) deg[i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][deg[u]] = (struct Edge*)malloc(sizeof(struct Edge));
        adj[u][deg[u]]->v = v;
        adj[u][deg[u]]->w = w;
        deg[u]++;

        adj[v][deg[v]] = (struct Edge*)malloc(sizeof(struct Edge));
        adj[v][deg[v]]->v = u;
        adj[v][deg[v]]->w = w;
        deg[v]++;
    }

    int source;
    scanf("%d", &source);

    dijkstra(n, source);

    return 0;
}
