// Breadth First Search

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100 // Maximum number of vertices
int graph[MAX][MAX]; // Adjacency matrix representation of the graph
bool visited[MAX]; // Array to keep track of visited vertices
int queue[MAX]; // Queue for BFS
int front = 0, rear = -1; // Queue pointers
int n; // Number of vertices

// Enqueue operation: adds a vertex to the queue
void enqueue(int v) {
    queue[++rear] = v;
}

// Dequeue operation: removes a vertex from the queue
int dequeue() {
    return queue[front++];
}

// Check if the queue is empty
bool isEmpty() {
    return front > rear;
}

// Breadth-First Search starting from a given vertex
void bfs(int start) {
    visited[start] = true; // Mark starting vertex as visited
    enqueue(start); // Enqueue the starting vertex
    while (!isEmpty()) {
        int v = dequeue(); // Get the next vertex from the queue
        printf("%d ", v); // Print the current vertex
        // Visit all adjacent unvisited vertices
        for (int i = 0; i < n; i++) {
            if (graph[v][i] && !visited[i]) {
                visited[i] = true; // Mark as visited
                enqueue(i); // Enqueue the adjacent vertex
            }
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n); // Read the number of vertices

    // Read the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    // Perform BFS starting from vertex 0
    printf("BFS traversal starting from vertex 0: ");
    bfs(0);
    printf("\n");

    return 0;
}