#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 1000

// Structure for adjacency list node
typedef struct AdjNode {
    int vertex;
    int weight;
    struct AdjNode* next;
} AdjNode;

// Structure for adjacency list
typedef struct {
    AdjNode* head;
} AdjList;

// Graph structure
typedef struct {
    int V;
    AdjList* array;
} Graph;

// Min-heap node
typedef struct {
    int vertex;
    int dist;
} HeapNode;

// Min-heap structure
typedef struct {
    int size;
    int capacity;
    int *pos;
    HeapNode **array;
} MinHeap;

// Utility: create adjacency node
AdjNode* newAdjNode(int v, int w) {
    AdjNode* node = (AdjNode*)malloc(sizeof(AdjNode));
    node->vertex = v;
    node->weight = w;
    node->next = NULL;
    return node;
}

// Create graph
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (AdjList*)malloc(V * sizeof(AdjList));
    for (int i = 0; i < V; i++)
        graph->array[i].head = NULL;
    return graph;
}

// Add edge (undirected or directed depending on use case)
void addEdge(Graph* graph, int src, int dest, int weight) {
    AdjNode* node = newAdjNode(dest, weight);
    node->next = graph->array[src].head;
    graph->array[src].head = node;
}

// MinHeap utility functions
HeapNode* newHeapNode(int v, int dist) {
    HeapNode* node = (HeapNode*)malloc(sizeof(HeapNode));
    node->vertex = v;
    node->dist = dist;
    return node;
}

MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->pos = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (HeapNode**)malloc(capacity * sizeof(HeapNode*));
    return heap;
}

void swapHeapNode(HeapNode** a, HeapNode** b) {
    HeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    if (left < heap->size && heap->array[left]->dist < heap->array[smallest]->dist)
        smallest = left;
    if (right < heap->size && heap->array[right]->dist < heap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        HeapNode* smallestNode = heap->array[smallest];
        HeapNode* idxNode = heap->array[idx];

        heap->pos[smallestNode->vertex] = idx;
        heap->pos[idxNode->vertex] = smallest;

        swapHeapNode(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

HeapNode* extractMin(MinHeap* heap) {
    if (heap->size == 0) return NULL;

    HeapNode* root = heap->array[0];
    HeapNode* lastNode = heap->array[heap->size - 1];
    heap->array[0] = lastNode;

    heap->pos[root->vertex] = heap->size - 1;
    heap->pos[lastNode->vertex] = 0;

    heap->size--;
    minHeapify(heap, 0);

    return root;
}

void decreaseKey(MinHeap* heap, int v, int dist) {
    int i = heap->pos[v];
    heap->array[i]->dist = dist;

    while (i && heap->array[i]->dist < heap->array[(i-1)/2]->dist) {
        heap->pos[heap->array[i]->vertex] = (i-1)/2;
        heap->pos[heap->array[(i-1)/2]->vertex] = i;
        swapHeapNode(&heap->array[i], &heap->array[(i-1)/2]);
        i = (i-1)/2;
    }
}

int isInMinHeap(MinHeap* heap, int v) {
    return heap->pos[v] < heap->size;
}

// Dijkstra’s algorithm
void dijkstra(Graph* graph, int src) {
    int V = graph->V;
    int dist[V];

    MinHeap* heap = createMinHeap(V);

    for (int v = 0; v < V; v++) {
        dist[v] = INT_MAX;
        heap->array[v] = newHeapNode(v, dist[v]);
        heap->pos[v] = v;
    }

    heap->array[src] = newHeapNode(src, dist[src]);
    heap->pos[src] = src;
    dist[src] = 0;
    decreaseKey(heap, src, dist[src]);
    heap->size = V;

    while (heap->size > 0) {
        HeapNode* minNode = extractMin(heap);
        int u = minNode->vertex;

        AdjNode* crawl = graph->array[u].head;
        while (crawl != NULL) {
            int v = crawl->vertex;
            if (isInMinHeap(heap, v) && dist[u] != INT_MAX &&
                crawl->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + crawl->weight;
                decreaseKey(heap, v, dist[v]);
            }
            crawl = crawl->next;
        }
    }

    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Example usage
int main() {
    int V = 9;
    Graph* graph = createGraph(V);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    dijkstra(graph, 0);

    return 0;
}