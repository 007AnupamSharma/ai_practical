//  tsp using hill climbing algorithm

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calculateTourLength(int n, int graph[n][n], int tour[n]) {
    int length = 0;
    for (int i = 0; i < n - 1; i++) {
        length += graph[tour[i]][tour[i + 1]];
    }
    length += graph[tour[n - 1]][tour[0]]; // Return to the starting city
    return length;
}

void shuffleArray(int n, int array[n]) {
    for (int i = n - 1; i > 0; i--) {
        int index = rand() % (i + 1);
        int temp = array[index];
        array[index] = array[i];
        array[i] = temp;
    }
}

int* generateRandomTour(int n) {
    int* tour = (int*)malloc(n * sizeof(int));
    if (tour == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        tour[i] = i;
    }
    shuffleArray(n, tour);
    return tour;
}

int* twoOptSwap(int n, int tour[n], int i, int j) {
    int* newTour = (int*)malloc(n * sizeof(int));
    if (newTour == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (int k = 0; k < n; k++) {
        newTour[k] = tour[k];
    }
    while (i < j) {
        int temp = newTour[i];
        newTour[i] = newTour[j];
        newTour[j] = temp;
        i++;
        j--;
    }
    return newTour;
}

int* hillClimbingTSP(int n, int graph[n][n]) {
    int* currentTour = generateRandomTour(n);
    int currentTourLength = calculateTourLength(n, graph, currentTour);
    int improved;
    do {
        improved = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int* newTour = twoOptSwap(n, currentTour, i, j);
                int newTourLength = calculateTourLength(n, graph, newTour);
                if (newTourLength < currentTourLength) {
                    free(currentTour);
                    currentTour = newTour;
                    currentTourLength = newTourLength;
                    improved = 1;
                } else {
                    free(newTour);
                }
            }
        }
    } while (improved);
    return currentTour;
}

int main() {
    srand(time(NULL));

    int n = 4;
    int graph[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int* tour = hillClimbingTSP(n, graph);

    printf("Optimal Tour: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tour[i]);
    }
    printf("\n");
    printf("Optimal Tour Length: %d\n", calculateTourLength(n, graph, tour));

    free(tour);

    return 0;
}


// Optimal Tour: 2 3 1 0 
// Optimal Tour Length: 80