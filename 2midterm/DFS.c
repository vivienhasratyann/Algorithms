// Depth First Search Recursive

#include <stdio.h>
#include <stdbool.h>
#define MAX 100 // Maximum number of vertices
int graph[MAX][MAX]; // Adjacency matrix representation of the graph
bool visited[MAX]; // Array to track visited vertices
int n; // Number of vertices

// Recursive Depth-First Search function
void dfs(int v) {
    visited[v] = true; // Mark the current vertex as visited
    printf("%d ", v); // Print the current vertex
    for (int i = 0; i < n; i++) { // Check all possible adjacent vertices
        if (graph[v][i] && !visited[i]) { // If there's an edge and vertex is not visited
            dfs(i); // Recur on the adjacent vertex
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n); // Read number of vertices

    // Read the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    // Initialize the visited array to false
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    // Perform DFS starting from vertex 0
    printf("DFS traversal starting from vertex 0: ");
    dfs(0);
    printf("\n");

    return 0;
}