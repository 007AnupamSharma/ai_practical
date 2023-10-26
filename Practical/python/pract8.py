import random

def calculate_tour_length(graph, tour):
    length = 0
    n = len(tour)
    for i in range(n - 1):
        length += graph[tour[i]][tour[i + 1]]
    length += graph[tour[n - 1]][tour[0]]  # Return to the starting city
    return length

def shuffle_array(array):
    n = len(array)
    for i in range(n - 1, 0, -1):
        index = random.randint(0, i)
        array[i], array[index] = array[index], array[i]

def generate_random_tour(n):
    tour = list(range(n))
    shuffle_array(tour)
    return tour

def two_opt_swap(tour, i, j):
    new_tour = tour[:]
    while i < j:
        new_tour[i], new_tour[j] = new_tour[j], new_tour[i]
        i += 1
        j -= 1
    return new_tour

def hill_climbing_tsp(graph):
    n = len(graph)
    current_tour = generate_random_tour(n)
    current_tour_length = calculate_tour_length(graph, current_tour)
    improved = True
    while improved:
        improved = False
        for i in range(n):
            for j in range(i + 1, n):
                new_tour = two_opt_swap(current_tour, i, j)
                new_tour_length = calculate_tour_length(graph, new_tour)
                if new_tour_length < current_tour_length:
                    current_tour = new_tour
                    current_tour_length = new_tour_length
                    improved = True
    return current_tour

def main():
    random.seed()
    n = 4
    graph = [
        [0, 10, 15, 20],
        [10, 0, 35, 25],
        [15, 35, 0, 30],
        [20, 25, 30, 0]
    ]

    tour = hill_climbing_tsp(graph)

    print("Optimal Tour:", tour)
    print("Optimal Tour Length:", calculate_tour_length(graph, tour))

if __name__ == "__main__":
    main()
