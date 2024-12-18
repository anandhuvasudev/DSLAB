#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int V;  
    int adj[MAX][MAX];  
} Graph;

Graph *createGraph(int V) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V + 1;
    for (int i = 0; i < graph->V; i++)
        for (int j = 0; j < graph->V; j++)
            graph->adj[i][j] = 0;
    return graph;
}

void addEdge(Graph *graph, int u, int v) {
    graph->adj[u][v] = 1;
}

void dfs(int v, bool visited[], int stack[], int *index, Graph *graph) {
    visited[v] = true;
    for (int i = 1; i < graph->V; i++) {
        if (graph->adj[v][i] && !visited[i])
            dfs(i, visited, stack, index, graph);
    }
    stack[(*index)++] = v;
}

void dfsT(int v, bool visited[], Graph *graph) {
    visited[v] = true;
    printf("%d ", v);
    for (int i = 1; i < graph->V; i++) {
        if (graph->adj[v][i] && !visited[i])
            dfsT(i, visited, graph);
    }
}

Graph *transposeGraph(Graph *graph) {
    Graph *transposed = createGraph(graph->V - 1);
    for (int i = 1; i < graph->V; i++) {
        for (int j = 1; j < graph->V; j++) {
            transposed->adj[j][i] = graph->adj[i][j];
        }
    }
    return transposed;
}

void kosaraju(Graph *graph) {
    bool visited[MAX] = {false};
    int stack[MAX], index = 0;

    for (int i = 1; i < graph->V; i++) {
        if (!visited[i])
            dfs(i, visited, stack, &index, graph);
    }

    Graph *transposed = transposeGraph(graph);

    for (int i = 1; i < graph->V; i++) {
        visited[i] = false;
    }
   
    while (index > 0) {
        int v = stack[--index];
        if (!visited[v]) {
            dfsT(v, visited, transposed);
            printf("\n");
        }
    }

    free(transposed);
}

int main() {
    int V, E, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    Graph *graph = createGraph(V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter the edges (u v) where u -> v:\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printf("Strongly Connected Components:\n");
    kosaraju(graph);

    free(graph);
    return 0;
}
