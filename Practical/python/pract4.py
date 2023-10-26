def dfs(graph, start_node):
    n = len(graph)
    visited = [False] * n
    stack = []
    
    visited[start_node] = True
    stack.append(start_node)
    
    print(f"Depth-First Traversal [starting from node {chr(65 + start_node)}]:")
    
    while stack:
        current_node = stack.pop()
        print(f"{chr(65 + current_node)} ", end="")
        
        for i in range(n):
            if graph[current_node][i] == 1 and not visited[i]:
                visited[i] = True
                stack.append(i)
    
if __name__ == "__main__":
    n = 8
    adjacency_matrix = [
        [0, 1, 0, 0, 0, 0, 0, 0],
        [0, 0, 1, 0, 0, 1, 0, 0],
        [0, 0, 0, 0, 1, 0, 1, 1],
        [0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 1, 0, 0],
        [1, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 1, 0, 0],
        [1, 0, 0, 0, 0, 0, 0, 0]
    ]
    start_node = 0

    dfs(adjacency_matrix, start_node)
