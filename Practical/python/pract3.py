from collections import deque

def bfs(graph, start_node, target_node):
    n = len(graph)
    visited = [False] * n
    queue = deque()

    visited[start_node] = True
    queue.append(start_node)

    print(f"Breadth-First Traversal [starting from node {chr(65 + start_node)}]:")
    
    while queue:
        current_node = queue.popleft()
        print(f"{chr(65 + current_node)}", end="")
        
        if current_node != target_node:
            print("->", end="")
        else:
            print("\nTarget node found.")
            return
        
        for i in range(n):
            if graph[current_node][i] == 1 and not visited[i]:
                visited[i] = True
                queue.append(i)
    
    print("Target node not found.")

if __name__ == "__main__":
    n = 7
    adjacency_matrix = [
        [0, 1, 0, 1, 0, 0, 0],
        [0, 0, 1, 0, 0, 1, 0],
        [0, 0, 0, 0, 1, 0, 1],
        [0, 0, 0, 0, 0, 1, 0],
        [1, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 0, 0]
    ]
    start_node = 0
    target_node = 4

    bfs(adjacency_matrix, start_node, target_node)
