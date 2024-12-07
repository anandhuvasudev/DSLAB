#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 10

typedef struct
{
        int adj[MAX_VERTICES][MAX_VERTICES];
        int visited[MAX_VERTICES];
        int n;
} Graph;

int startTime[MAX_VERTICES], endTime[MAX_VERTICES], timeCounter = 0;


void initializeGraph(Graph* g, int n)
{
        g->n = n;
        for (int i = 0; i < n; i++)
        {
                g->visited[i] = 0;
                for (int j = 0; j < n; j++)
                {
                        g->adj[i][j] = 0;
                }
        }
}


void addEdge(Graph* g, int u, int v)
{
        g->adj[u][v] = 1;
        g->adj[v][u] = 1;
}


void DFS_Visit(Graph* g, int vertex)
{
        g->visited[vertex] = 1;
        startTime[vertex] = ++timeCounter;
        printf("%d (Start time: %d)\n", vertex, startTime[vertex]);


        for (int i = 0; i < g->n; i++)
        {
                if (g->adj[vertex][i] == 1 && !g->visited[i])
                {
                        DFS_Visit(g, i);
                }
        }

        endTime[vertex] = ++timeCounter;
        printf("%d (End time: %d)\n", vertex, endTime[vertex]);
}


void DFS(Graph* g)
{
        printf("Depth-First Search Traversal:\n");
        for (int i = 0; i < g->n; i++)
        {
                if (!g->visited[i])
                {
                        DFS_Visit(g, i);
                }
        }
}


void BFS(Graph* g, int start)
{
        bool queue[MAX_VERTICES];
        for (int i = 0; i < g->n; i++)
        {
                g->visited[i] = 0;
        }

        int front = 0, rear = 0;
        queue[rear++] = start;
        g->visited[start] = 1;

        printf("Breadth-First Search Traversal from vertex %d:\n", start);

        while (front < rear)
        {
                int vertex = queue[front++];
                printf("%d ", vertex);

                for (int i = 0; i < g->n; i++)
                {
                        if (g->adj[vertex][i] == 1 && !g->visited[i])
                        {
                                queue[rear++] = i;
                                g->visited[i] = 1;
                        }
                }
        }
        printf("\n");
}


void topologicalSort(Graph* g)
{
        int sorted[MAX_VERTICES], index = 0;


        for (int i = 0; i < g->n; i++)
        {
                if (!g->visited[i])
                {
                        DFS_Visit(g, i);
                }
        }


        for (int i = 0; i < g->n; i++)
        {
                sorted[i] = i;
        }

        for (int i = 0; i < g->n - 1; i++)
        {
                for (int j = i + 1; j < g->n; j++)
                {
                        if (endTime[sorted[i]] < endTime[sorted[j]])
                        {

                                int temp = sorted[i];
                                sorted[i] = sorted[j];
                                sorted[j] = temp;
                        }
                }
        }


        printf("Topological Sort (Based on DFS finishing times):\n");
        for (int i = 0; i < g->n; i++)
        {
                printf("%d ", sorted[i]);
        }
        printf("\n");
}


int main()
{
        Graph g;
        int n, e, u, v, choice, start;


        printf("Enter the number of vertices: ");
        scanf("%d", &n);
        initializeGraph(&g, n);

        printf("Enter the number of edges: ");
        scanf("%d", &e);


        printf("Enter the edges (u v):\n");
        for (int i = 0; i < e; i++)
        {
                scanf("%d %d", &u, &v);
                addEdge(&g, u, v);
        }


        while (1)
        {
                printf("\nChoose an operation:\n");
                printf("1. Perform DFS traversal\n");
                printf("2. Perform BFS traversal\n");
                printf("3. Perform Topological Sort\n");
                printf("4. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                        case 1:
                                DFS(&g);
                                break;
                        case 2:
                                printf("Enter the starting vertex for BFS: ");
                                scanf("%d", &start);
                                BFS(&g, start);
                                break;
                        case 3:
                                topologicalSort(&g);
                                break;
                        case 4:
                                printf("Exiting...\n");
                                return 0;
                        default:
                                printf("Invalid choice! Please try again.\n");
                }
        }

        return 0;
}
