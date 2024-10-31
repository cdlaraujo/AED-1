#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int is_valid(int sudoku[9][9], int row, int col, int num) {
    // Checa a linha e coluna
    for (int x = 0; x < 9; x++) {
        if (sudoku[row][x] == num || sudoku[x][col] == num) {
            return 0;
        }
    }

    // Checa o bloco 3x3
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[i + startRow][j + startCol] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int fill_sudoku(int sudoku[9][9], int row, int col) {
    if (row == 9 - 1 && col == 9) {
        return 1;
    }
    if (col == 9) {
        row++;
        col = 0;
    }

    if (sudoku[row][col] != 0) {
        return fill_sudoku(sudoku, row, col + 1);
    }

    for (int num = 1; num <= 9; num++) {
        if (is_valid(sudoku, row, col, num)) {
            sudoku[row][col] = num;
            if (fill_sudoku(sudoku, row, col + 1)) {
                return 1;
            }
            sudoku[row][col] = 0;
        }
    }
    return 0;
}

void print_sudoku(int sudoku[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int sudoku[9][9] = {0}; // Inicia com zeros
    srand(time(0));
    if (fill_sudoku(sudoku, 0, 0)) {
        printf("Sudoku gerado:\n");
        print_sudoku(sudoku);
    } else {
        printf("Falha ao gerar o Sudoku.\n");
    }
    return 0;
}
