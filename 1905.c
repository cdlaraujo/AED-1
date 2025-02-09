#include <stdio.h>
#include <stdbool.h>

#define SIZE 25

// Função para encontrar os vizinhos válido
void vizinhos(int n, int *result, int *count) {
    *count = 0;
    if (n + 5 <= SIZE) result[(*count)++] = n + 5;
    if (n % 5 != 0) result[(*count)++] = n + 1;
    if (n % 5 != 1) result[(*count)++] = n - 1;
    if (n - 5 >= 1) result[(*count)++] = n - 5;
}

// Função recursiva para verificar se a polícia alcança o ladrão
bool policia(int labirinto[], int caminho[], int caminho_size) {
    int pos = caminho[caminho_size - 1]; // ultima posição no caminho

    if (pos == 25) return true; // Se chegou na célula 25, retorna verdadeiro

    int prox[4], prox_count;
    vizinhos(pos, prox, &prox_count); // Obtém vizinhos válidos

    for (int i = 0; i < prox_count; i++) {
        int next = prox[i];
        if (labirinto[next - 1] == 0) { // Somente células '0' são válidas
            bool ja_visitado = false;
            for (int j = 0; j < caminho_size; j++) {
                if (caminho[j] == next) {
                    ja_visitado = true;
                    break;
                }
            }
            if (!ja_visitado) {
                int novo_caminho[SIZE];
                for (int k = 0; k < caminho_size; k++) novo_caminho[k] = caminho[k];
                novo_caminho[caminho_size] = next;

                if (policia(labirinto, novo_caminho, caminho_size + 1)) return true;
            }
        }
    }
    return false;
}

void leia_labirinto(int labirinto[]) {
    int index = 0;
    while (index < SIZE) {
        char linha[100];
        scanf("%s", linha);
        for (int i = 0; linha[i] != '\0' && index < SIZE; i++) {
            if (linha[i] == '0' || linha[i] == '1') {
                labirinto[index++] = linha[i] - '0';
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t); 

    for (int i = 0; i < t; i++) {
        int labirinto[SIZE];
        leia_labirinto(labirinto); 
        int caminho[SIZE];
        caminho[0] = -4; 

        if (policia(labirinto, caminho, 1)) {
            printf("COPS\n");
        } else {
            printf("ROBBERS\n");
        }
    }

    return 0;
}
