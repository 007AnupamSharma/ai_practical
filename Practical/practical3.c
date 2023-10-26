// breadth first search

#include <stdio.h>
#include <stdbool.h>

void bfs(int graph[7][7], int startNode, int targetNode);

int main() {
    int n = 7;
    int adjacencyMatrix[7][7] = {
        {0, 1, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 1, 0},
        {1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };
    int startNode = 0;
    int targetNode = 4;

    printf("Breadth-First Traversal [starting from node %c]:\n", 'A' + startNode);
    bfs(adjacencyMatrix, startNode, targetNode);

    return 0;
}

void bfs(int graph[7][7], int startNode, int targetNode) {
    int n = 7;
    bool visited[7];
    int queue[7];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    visited[startNode] = true;
    queue[rear++] = startNode;

    while (front != rear) {
        int currentNode = queue[front++];
        printf("%c", 'A' + currentNode);

        if (currentNode != targetNode) {
            printf("->");
        } else {
            printf("\nTarget node found.\n");
            return;
        }

        for (int i = 0; i < n; i++) {
            if (graph[currentNode][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }

    printf("\nTarget node not found.\n");
}
