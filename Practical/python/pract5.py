import queue as Q

graph = []

# Function for adding edges to graph
def add_edge(x, y, cost):
    graph[x].append((cost, y))
    graph[y].append((cost, x))

# Function for implementing Best First Search
# Gives output path having the lowest cost
def best_first_search(actual_src, target, n):
    visited = [False] * n
    # MIN HEAP priority queue
    pq = Q.PriorityQueue()
    pq.put((0, actual_src))
    s = actual_src
    visited[s] = True
    while not pq.empty():
        x = pq.get()[1]
        # Displaying the path having the lowest cost
        print(x, end=" ")
        if x == target:
            break

        for i in range(len(graph[x])):
            if not visited[graph[x][i][1]]:
                visited[graph[x][i][1]] = True
                pq.put((graph[x][i][0], graph[x][i][1]))

# Driver code to test above methods
if __name__ == "__main__":
    # No. of Nodes
    v = 14
    for _ in range(v):
        graph.append([])

    # The nodes shown in the above example (by integers) are
    # implemented using integers add_edge(x, y, cost)
    add_edge(0, 1, 3)
    add_edge(0, 2, 6)
    add_edge(0, 3, 5)
    add_edge(1, 4, 9)
    add_edge(1, 5, 8)
    add_edge(2, 6, 12)
    add_edge(2, 7, 14)
    add_edge(3, 8, 7)
    add_edge(8, 9, 5)
    add_edge(8, 10, 6)
    add_edge(9, 11, 1)
    add_edge(9, 12, 10)
    add_edge(9, 13, 2)

    source = 0
    target = 9

    # Function call
    best_first_search(source, target, v)
