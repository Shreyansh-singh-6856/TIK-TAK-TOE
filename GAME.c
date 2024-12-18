#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];  // Board of size 3x3

// Function to initialize the board
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';  // Empty space
        }
    }
}

// Function to print the board
void printBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");  // Print separator between cells
        }
        printf("\n");
        if (i < 2) {
            printf("---|---|---\n");  // Horizontal separator between rows
        }
    }
}

// Function for the computer to make a random move
void cmpMove() {
    int row, col;
    do {
        row = rand() % 3;       // Random row (0-2)
        col = rand() % 3;       // Random column (0-2)
    } while (board[row][col] != ' ');  // Ensure the spot is empty

    board[row][col] = 'X';  // Computer marks 'X'
    printf("\nComputer's move (X):\n");
    printBoard();
}

// Function for the user to make a move
void userMove() {
    int row, col;
    printf("\nYour move (O): Enter row and column (0-2) separated by space: ");
    scanf("%d %d", &row, &col);

    if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
        printf("Invalid move! Try again.\n");
        userMove();  // Recursive call to let the user try again
    } else {
        board[row][col] = 'O';  // User marks 'O'
        printBoard();
    }
}

// Function to check for a win
char checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];  // Row win
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];  // Column win
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];  // Top-left to bottom-right diagonal
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];  // Top-right to bottom-left diagonal

    return ' ';  // No winner yet
}

// Function to check if the board is full
int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0;  // Empty space found, not full
        }
    }
    return 1;  // Board is full
}

int main() {
    srand(time(0));  // Seed the random number generator

    initializeBoard();  // Initialize the board
    printf("Initial Board ::\n");
    printBoard();

    while (1) {
      

        // Computer's turn
        printf("\nComputer's Turn (X):\n");
        cmpMove();

        // Check if the computer wins
        if (checkWin() == 'X') {
            printf("\nComputer wins! Better luck next time!\n");
            break;
        }

        // Check if the board is full
        if (isBoardFull()) {
            printf("\nIt's a draw!\n");
            break;
        }

          // User's turn
        printf("\nYour Turn (O):\n");
        userMove();

        // Check if the user wins
        if (checkWin() == 'O') {
            printf("\nCongratulations! You win!\n");
            break;
        }

        // Check if the board is full
        if (isBoardFull()) {
            printf("\nIt's a draw!\n");
            break;
        }
    }

    return 0;
}
