#include <stdio.h>

char board[3][3];
char player1Marker = '$', player2Marker = '!';
char currentPlayer = '1';

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("---+---+---\n");
        }
    }
}

int checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return 1;
    }
    return 0;
}

int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

void makeMove(int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        currentPlayer = (currentPlayer == '1') ? '2' : '1';
    }
}

int main() {
    int row, col;
    
    initializeBoard();

    do {
        printBoard();

        int currentPlayerNum = (currentPlayer == '1') ? 1 : 2;
        printf("Player %d's turn\n", currentPlayerNum);

        printf("Enter row and column (0 2) separated by space: ");
        scanf("%d %d", &row, &col);

        makeMove(row, col);

        if (checkWin()) {
            printBoard();
            printf("Player %d wins!\n", currentPlayerNum);
            break;
        }

        if (checkDraw()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
    } while (1);

    return 0;
}