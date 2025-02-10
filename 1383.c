#include <stdio.h>

int sudoku[9][9];

// Verifica se a linha 'x' do sudoku está correta (sem números repetidos)
int verificaLinha(int x) 
{
    int numeros[10] = {0};  // Vetor para contar as ocorrências dos números (1 a 9)

    // Percorre os 9 elementos da linha
    for (int j = 0; j < 9; ++j) {
        int valor = sudoku[x][j];
        if (numeros[valor] > 0) {
            // Se o número já apareceu, a linha é inválida
            return 0;
        }
        numeros[valor]++;
    }

    return 1;  // Linha válida
}

// Verifica se a coluna 'x' do sudoku está correta (sem números repetidos)
int verificaColuna(int x) 
{
    int numeros[10] = {0};

    // Percorre os 9 elementos da coluna
    for (int i = 0; i < 9; ++i) {
        int valor = sudoku[i][x];
        if (numeros[valor] > 0) {
            // Número repetido na coluna
            return 0;
        }
        numeros[valor]++;
    }

    return 1;  // Coluna válida
}

// Verifica se o quadrado 3x3 identificado por 'x' está correto
// x varia de 0 a 8, cada valor corresponde a um dos 9 quadrados do sudoku
int verificaQuadrado(int x) 
{
    int numeros[10] = {0};
    int linhaInicio = 3 * (x / 3);
    int colunaInicio = 3 * (x % 3);

    // Percorre as 3 linhas e 3 colunas do quadrado
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int valor = sudoku[linhaInicio + i][colunaInicio + j];
            if (numeros[valor] > 0) {
                // Número repetido no quadrado 3x3
                return 0;
            }
            numeros[valor]++;
        }
    }

    return 1;  // Quadrado válido
}

int main() {
    int n;// Número de instâncias a serem testadas
    char* resposta; // Ponteiro para a string de resposta ("SIM" ou "NAO")

    scanf("%d", &n);

    for (int k = 1; k <= n; ++k) {
        // Lê o tabuleiro do sudoku (9x9)
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        printf("Instancia %d\n", k);

        resposta = "SIM"; // Inicialmente, assume que o sudoku está correto

        // Verifica cada linha, coluna e quadrado 3x3
        for (int i = 0; i < 9; ++i) {
            if (!verificaLinha(i) || !verificaColuna(i) || !verificaQuadrado(i)) {
                resposta = "NAO"; // Encontrou alguma inconsistência
                break;
            }
        }

        printf("%s\n\n", resposta);
    }

    return 0;
}
