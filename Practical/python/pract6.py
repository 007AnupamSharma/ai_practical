import queue

N = 3

# State space tree nodes
class Node:
    def __init__(self, mat, x, y, newX, newY, level, parent):
        self.parent = parent  # Stores the parent node of the current node
        self.mat = [row[:] for row in mat]  # Stores the matrix
        self.x = x  # Stores blank tile coordinates
        self.y = y
        self.cost = float('inf')  # Stores the number of misplaced tiles
        self.level = level  # Stores the number of moves so far

        # Move tile by 1 position
        self.mat[x][y], self.mat[newX][newY] = self.mat[newX][newY], self.mat[x][y]

        # Update new blank tile coordinates
        self.x = newX
        self.y = newY

    def __lt__(self, other):
        return (self.cost + self.level) < (other.cost + other.level)


# Bottom, left, top, right
row = [1, 0, -1, 0]
col = [0, -1, 0, 1]


# Function to print N x N matrix
def printMatrix(mat):
    for i in range(N):
        for j in range(N):
            print(mat[i][j], end=" ")
        print()


# Function to calculate the number of misplaced tiles
def calculateCost(initial, final):
    count = 0
    for i in range(N):
        for j in range(N):
            if initial[i][j] and initial[i][j] != final[i][j]:
                count += 1
    return count


# Function to check if (x, y) is a valid matrix coordinate
def isSafe(x, y):
    return 0 <= x < N and 0 <= y < N


# Print path from root node to destination node
def printPath(root):
    if root is None:
        return
    printPath(root.parent)
    printMatrix(root.mat)
    print()


# Function to solve N*N - 1 puzzle algorithm using Branch and Bound
def solve(initial, x, y, final):
    pq = queue.PriorityQueue()  # Create a priority queue to store live nodes of search tree
    root = Node(initial, x, y, x, y, 0, None)  # Create a root node
    root.cost = calculateCost(initial, final)  # Calculate its cost
    pq.put(root)  # Add root to the list of live nodes

    # Find the node with the least estimated cost, add its children to the list of live nodes, and finally delete it from the list
    while not pq.empty():
        minNode = pq.get()  # Find a live node with the least estimated cost

        # If min is an answer node
        if minNode.cost == 0:
            printPath(minNode)  # Print the path from the root to the destination
            return

        # Do for each child of min (maximum 4 children for a node)
        for i in range(4):
            if isSafe(minNode.x + row[i], minNode.y + col[i]):
                child = Node(minNode.mat, minNode.x, minNode.y, minNode.x + row[i], minNode.y + col[i], minNode.level + 1, minNode)  # Create a child node and calculate its cost
                child.cost = calculateCost(child.mat, final)
                pq.put(child)  # Add the child to the list of live nodes


# Driver code
if __name__ == "__main__":
    # Initial configuration (Value 0 is used for empty space)
    initial = [
        [1, 2, 3],
        [5, 6, 0],
        [7, 8, 4]
    ]

    # Solvable Final configuration (Value 0 is used for empty space)
    final = [
        [1, 2, 3],
        [5, 8, 6],
        [0, 7, 4]
    ]

    # Blank tile coordinates in the initial configuration
    x, y = 1, 2

    solve(initial, x, y, final)
