#include<stdbool.h>

void bfs(int graph[7][7],int startNode, int endNode){
    bool visited[7];
    int queue[7];
    int front =0,  rear=0;

    for(int i=0;i<7;i++){
        visited[i] = false;
    }

    queue[rear++] = startNode;
    visited[startNode] = true;

    while(front != rear){
        int currentNode = queue[front++];
        if(currentNode != endNode){
            printf("->");
        }else{
            printf("Target Not Found ");
            return;
        }
        for(int i=0;i<7;i++){
                if(!visited[i] && graph[currentNode][i] == 1){
                    visited[i] = true;
                    queue[rear++] = i;
                }
        }
    }
    printf("Target  Found !!");

}