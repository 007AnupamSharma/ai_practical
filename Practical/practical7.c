// constraints satisfacation problem

#include <stdio.h>
#include <string.h>

#define NUM_CITIES 7
#define NUM_COLORS 3

char* cities[] = {"WA", "NT", "SA", "Q", "NSW", "V", "T"};
int adjacencyMatrix[NUM_CITIES][NUM_CITIES] = {
    {0, 1, 1, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 0, 0},
    {1, 1, 0, 1, 1, 1, 0},
    {0, 1, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 0},
    {0, 0, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0}
};

char cityColors[NUM_CITIES][10];
char* colors[] = {"Red", "Blue", "Green"};

void printState();

int main() {
    for (int i = 0; i < NUM_CITIES; i++) {
        strcpy(cityColors[i], "-*-");
    }

    printState();

    for (int i = 0; i < NUM_CITIES; i++) {
        char* city = cities[i];
        char usedColors[NUM_COLORS][10];
        for (int j = 0; j < NUM_COLORS; j++) {
            strcpy(usedColors[j], "");
        }

        for (int j = 0; j < NUM_CITIES; j++) {
            if (adjacencyMatrix[i][j] == 1) {
                char* neighborColor = cityColors[j];
                if (strcmp(neighborColor, "-*-") != 0) {
                    strcpy(usedColors[j], neighborColor);
                }
            }
        }

        for (int j = 0; j < NUM_COLORS; j++) {
            if (strcmp(usedColors[j], "") == 0) {
                strcpy(cityColors[i], colors[j]);
                break;
            }
        }

        printState();
    }

    return 0;
}

void printState() {
    printf("Current Coloring:\n");
    for (int i = 0; i < NUM_CITIES; i++) {
        printf("%s: %s\n", cities[i], cityColors[i]);
    }
    printf("------------------\n");
}
