#include <stdio.h>
#include <stdbool.h>

char board[3][3];
char currentPlayer;
bool gameFinished;

void initializeBoard() {
    char cellNum = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = cellNum++;
        }
    }
}

void printBoard() {
    printf("-------------\n");
    for (int i = 0; i < 3; i++) {
        printf("| ");
        for (int j = 0; j < 3; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n-------------\n");
    }
}

bool isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }
    return false;
}

void makeMove(int cell) {
    if (cell < 1 || cell > 9) {
        printf("Invalid move! Cell number must be between 1 and 9.\n");
        return;
    }
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;
    if (board[row][col] == 'X' || board[row][col] == 'O') {
        printf("Invalid move! Cell already occupied.\n");
        return;
    }
    board[row][col] = currentPlayer;
    if (checkWin()) {
        gameFinished = true;
        printf("Player %c wins!\n", currentPlayer);
    } else if (isBoardFull()) {
        gameFinished = true;
        printf("It's a draw!\n");
    } else {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main() {
    initializeBoard();
    currentPlayer = 'X';
    gameFinished = false;

    printf("Welcome to Tic Tac Toe!\n");
    while (!gameFinished) {
        printBoard();
        char currentPlayer = currentPlayer;
        printf("Player %c, enter your move (1-9): ", currentPlayer);
        int cell;
        scanf("%d", &cell);
        makeMove(cell);
    }
    printBoard();

    return 0;
}
