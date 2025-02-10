#include <stdio.h>
#include <stdbool.h>

#define SIZE 25  // Labirinto com 25 células (5x5)

// Função para achar os vizinhos válidos da célula 'n'
void acharVizinhos(int n, int *result, int *count) {
    *count = 0;
    // Se puder descer (soma 5) sem sair do labirinto
    if (n + 5 <= SIZE)
        result[(*count)++] = n + 5;
    // Se não estiver na borda direita, pode ir para a direita
    if (n % 5 != 0)
        result[(*count)++] = n + 1;
    // Se não estiver na borda esquerda, pode ir para a esquerda
    if (n % 5 != 1)
        result[(*count)++] = n - 1;
    // Se puder subir (subtrai 5) sem sair do labirinto
    if (n - 5 >= 1)
        result[(*count)++] = n - 5;
}

// Função recursiva que verifica se a polícia consegue alcançar o ladrão
bool tentaCapturar(int labirinto[], int caminho[], int tamCaminho) {
    int posAtual = caminho[tamCaminho - 1];  // última posição do caminho

    // Se chegou à célula 25, a polícia alcançou o ladrão!
    if (posAtual == 25)
        return true;

    int vizinhos[4], qtdVizinhos;
    acharVizinhos(posAtual, vizinhos, &qtdVizinhos);  // obtém os vizinhos válidos

    for (int i = 0; i < qtdVizinhos; i++) {
        int proximo = vizinhos[i];
        // Verifica se a célula está livre (0 = livre)
        if (labirinto[proximo - 1] == 0) {
            bool jaVisitado = false;
            // Checa se já passamos por essa célula para evitar loops
            for (int j = 0; j < tamCaminho; j++) {
                if (caminho[j] == proximo) {
                    jaVisitado = true;
                    break;
                }
            }
            if (!jaVisitado) {
                int novoCaminho[SIZE];
                // Copia o caminho atual para um novo caminho
                for (int k = 0; k < tamCaminho; k++)
                    novoCaminho[k] = caminho[k];
                novoCaminho[tamCaminho] = proximo;

                // Se conseguirmos alcançar o destino por esse caminho, retornamos true
                if (tentaCapturar(labirinto, novoCaminho, tamCaminho + 1))
                    return true;
            }
        }
    }
    return false;
}

// Função para ler o labirinto da entrada
void lerLabirinto(int labirinto[]) {
    int index = 0;
    // Continua lendo até preencher todas as 25 células
    while (index < SIZE) {
        char linha[100];
        scanf("%s", linha);
        // Percorre cada caractere da linha
        for (int i = 0; linha[i] != '\0' && index < SIZE; i++) {
            if (linha[i] == '0' || linha[i] == '1')
                labirinto[index++] = linha[i] - '0';
        }
    }
}

int main() {
    int t;
    scanf("%d", &t); 

    for (int caso = 0; caso < t; caso++) {
        int labirinto[SIZE];
        lerLabirinto(labirinto);
        
        int caminho[SIZE];
        // Começamos com -4 pois (-4 + 5) = 1, que é a célula inicial
        caminho[0] = -4; 

        if (tentaCapturar(labirinto, caminho, 1))
            printf("COPS\n");
        else
            printf("ROBBERS\n");
    }

    return 0;
}
