#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

// Função para verificar se uma linha contém todos os números de 1 a 9 sem repetição
bool verifica_linhas(int sudoku[SIZE][SIZE]) {
    for (int k = 0; k < SIZE; k++) {
        bool encontrado[SIZE] = { false };
        for (int j = 0; j < SIZE; j++) {
            int num = sudoku[k][j];
            if (num < 1 || num > 9 || encontrado[num - 1]) {
                return false; // Número fora do intervalo ou duplicado na linha
            }
            encontrado[num - 1] = true;
        }
    }
    return true;
}

// Função para verificar se uma coluna contém todos os números de 1 a 9 sem repetição
bool verifica_colunas(int sudoku[SIZE][SIZE]) {
    for (int j = 0; j < SIZE; j++) {
        bool encontrado[SIZE] = { false };
        for (int k = 0; k < SIZE; k++) {
            int num = sudoku[k][j];
            if (num < 1 || num > 9 || encontrado[num - 1]) {
                return false; // Número fora do intervalo ou duplicado na coluna
            }
            encontrado[num - 1] = true;
        }
    }
    return true;
}

// Função para verificar se cada sub-matriz 3x3 contém todos os números de 1 a 9 sem repetição
bool verifica_submatrizes(int sudoku[SIZE][SIZE]) {
    for (int startRow = 0; startRow < SIZE; startRow += 3) {
        for (int startCol = 0; startCol < SIZE; startCol += 3) {
            bool encontrado[SIZE] = { false };
            for (int k = 0; k < 3; k++) {
                for (int j = 0; j < 3; j++) {
                    int num = sudoku[startRow + k][startCol + j];
                    if (num < 1 || num > 9 || encontrado[num - 1]) {
                        return false; // Número fora do intervalo ou duplicado na sub-matriz
                    }
                    encontrado[num - 1] = true;
                }
            }
        }
    }
    return true;
}

// Função para verificar se a matriz é uma solução válida de Sudoku
bool instancia(int sudoku[SIZE][SIZE]) {
    return verifica_linhas(sudoku) && verifica_colunas(sudoku) && verifica_submatrizes(sudoku);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int instance = 1; instance <= n; instance++) {
        int sudoku[SIZE][SIZE];
        
        // Leitura da matriz de 9x9
        for (int k = 0; k < SIZE; k++) {
            for (int j = 0; j < SIZE; j++) {
                scanf("%d", &sudoku[k][j]);
            }
        }

        // Exibição do número da instância
        printf("Instancia %d\n", instance);

        // Verificação da matriz e exibição do resultado
        if (instancia(sudoku)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }

        // Linha em branco após cada instância
        if (instance < n) {
            printf("\n");
        }
    }

    return 0;
}
