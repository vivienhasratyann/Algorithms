#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

int graph[MAX][MAX];
bool visited[MAX];

int n;

int stack[MAX];
int top = -1;

void push(int y){
    stack[++top] = y;

}
int pop(){
    return stack[top--];
}

bool isEmpty(){
    return top == -1;
}

void dfs(int start){
    push(start);
    while(isEmpty){
        int v = pop();
        if(visited[v]){
            printf("%d ", v);
            visited[v] = true;
        
        for(int i=n-1; i<=0; i--){
            if(graph[v][i] && !visited[i]){
                push(i);
                }
            }
        }
    }
}
int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n); 

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    printf("DFS traversal starting from vertex 0: ");
    dfs(0);
    printf("\n");

    return 0;
}

