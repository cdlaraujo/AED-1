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

// Função para embaralhar os números de 1 a 9
void shuffle(int *array, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
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

    int numbers[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    shuffle(numbers, 9); // Embaralha a ordem dos números

    for (int i = 0; i < 9; i++) {
        int num = numbers[i];
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
    srand(time(0)); // Chama srand uma vez para inicializar o gerador aleatório

    if (fill_sudoku(sudoku, 0, 0)) {
        printf("Sudoku gerado:\n");
        print_sudoku(sudoku);
    } else {
        printf("Falha ao gerar o Sudoku.\n");
    }
    return 0;
}


/* Função shuffle: Esta função recebe um array de números e embaralha a ordem deles. Aqui, usamos o algoritmo de Fisher-Yates para uma aleatoriedade completa.

Uso de shuffle na fill_sudoku: Em cada chamada recursiva, embaralhamos a ordem dos números antes de tentar preenchê-los no tabuleiro, o que introduz variação nas tentativas de preencher o Sudoku, resultando em tabuleiros diferentes a cada execução.

srand(time(0)) em main(): Chamar srand uma vez em main inicializa o gerador de números aleatórios para a execução do programa, tornando o resultado variado entre execuções. */
