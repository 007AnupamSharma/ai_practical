// depth first search 

#include <stdio.h>
#include <stdbool.h>

void dfs(int graph[8][8], int startNode);

int main() {
    int n = 8;
    int adjacencyMatrix[8][8] = {
        {0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0}
    };
    int startNode = 0;

    printf("Depth-First Traversal [starting from node %c]:\n", 'A' + startNode);
    dfs(adjacencyMatrix, startNode);

    return 0;
}

void dfs(int graph[8][8], int startNode) {
    int n = 8;
    bool visited[8];
    int stack[8];
    int top = 0;

    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    visited[startNode] = true;
    stack[top++] = startNode;

    while (top > 0) {
        int currentNode = stack[--top];
        printf("%c ", 'A' + currentNode);

        for (int i = 0; i < n; i++) {
            if (graph[currentNode][i] == 1 && !visited[i]) {
                visited[i] = true;
                stack[top++] = i;
            }
        }
    }
}
