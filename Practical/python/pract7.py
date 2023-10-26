NUM_CITIES = 7
NUM_COLORS = 3

cities = ["WA", "NT", "SA", "Q", "NSW", "V", "T"]
adjacency_matrix = [
    [0, 1, 1, 0, 0, 0, 0],
    [1, 0, 1, 1, 0, 0, 0],
    [1, 1, 0, 1, 1, 1, 0],
    [0, 1, 1, 0, 1, 0, 0],
    [0, 0, 1, 1, 0, 1, 0],
    [0, 0, 1, 0, 1, 0, 0],
    [0, 0, 0, 0, 0, 0, 0]
]

city_colors = ["-*-" for _ in range(NUM_CITIES)]
colors = ["Red", "Blue", "Green"]

def print_state():
    print("Current Coloring:")
    for i in range(NUM_CITIES):
        print(f"{cities[i]}: {city_colors[i]}")
    print("------------------")

for i in range(NUM_CITIES):
    city_colors[i] = "-*-"

print_state()

for i in range(NUM_CITIES):
    city = cities[i]
    used_colors = [""] * NUM_COLORS

    for j in range(NUM_CITIES):
        if adjacency_matrix[i][j] == 1:
            neighbor_color = city_colors[j]
            if neighbor_color != "-*-":
                used_colors[colors.index(neighbor_color)] = neighbor_color

    for j in range(NUM_COLORS):
        if used_colors[j] == "":
            city_colors[i] = colors[j]
            break

    print_state()
