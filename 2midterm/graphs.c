#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

int v; // number of vertices
int graph[MAX][MAX];
int visited[MAX];

void dfs(int node) {
    visited[node] = true;
    printf("%d ", node);
    for (int i = 0; i < v; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &v);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize visited array to false (0)
    for (int i = 0; i < v; i++) {
        visited[i] = 0;
    }

    printf("DFS traversal: ");
    dfs(0);  // start DFS from node 0
    printf("\n");

    return 0;
}


