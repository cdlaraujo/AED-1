#include <stdio.h>
#include <stdlib.h>

// Estrutura de nó para guardar as posições visitadas
typedef struct node {
    int i;
    int j;
    struct node* next;
} node;

// Adiciona um novo nó (posição) ao final da lista
void adicionarNo(node** head, int x, int y) {
    node* novo = (node*)malloc(sizeof(node));
    novo->i = x;
    novo->j = y;
    novo->next = NULL;

    if (*head == NULL) {
        *head = novo;
    } else {
        node* atual = *head;
        while (atual->next != NULL) {
            atual = atual->next;
        }
        atual->next = novo;
    }
}

// Verifica se a posição (x, y) já foi visitada
int verificarDuplicata(node* head, int x, int y) {
    while (head != NULL) {
        if (head->i == x && head->j == y)
            return 1;
        head = head->next;
    }
    return 0;
}

// Libera toda a memória alocada para a lista
void liberarLista(node* head) {
    node* atual;
    while (head != NULL) {
        atual = head;
        head = head->next;
        free(atual);
    }
}

int main() {
    int largura, altura;
    int i, j;
    char c;

    // Lê as dimensões do mapa
    scanf("%d", &largura);
    scanf("%d", &altura);

    // Aloca a matriz que representa o mapa
    int** mapa = (int**)malloc(altura * sizeof(int*));
    for (i = 0; i < altura; i++) {
        mapa[i] = (int*)malloc(largura * sizeof(int));
    }

    // Preenche o mapa lendo os comandos de cada célula
    for (i = 0; i < altura; i++) {
        for (j = 0; j < largura; j++) {
            scanf(" %c", &c);
            switch (c) {
                case '>': mapa[i][j] = 1; break; // mover para a direita
                case '<': mapa[i][j] = 2; break; // mover para a esquerda
                case '^': mapa[i][j] = 3; break; // mover para cima
                case 'v': mapa[i][j] = 4; break; // mover para baixo
                case '.': mapa[i][j] = 5; break; // sem comando
                case '*': mapa[i][j] = 0; break; // baú encontrado
                default:  mapa[i][j] = -1; break; // comando inválido
            }
        }
    }

    // Ponto de partida: canto superior esquerdo (0,0)
    i = 0, j = 0;
    node* visitados = NULL;
    int comando = mapa[i][j]; // comando da célula inicial
    adicionarNo(&visitados, i, j);

    // Loop principal: segue as direções do mapa até achar o baú ou detectar problema
    while (1) {
        // Enquanto a célula atual não tiver um novo comando (valor 5), continua na mesma direção
        while (mapa[i][j] == 5) {
            if (comando == 1) j++; // vai para a direita
            else if (comando == 2) j--; // vai para a esquerda
            else if (comando == 3) i--; // sobe
            else if (comando == 4) i++; // desce

            // Se sair dos limites do mapa, encerra com erro
            if (i < 0 || j < 0 || j >= largura || i >= altura) {
                printf("!");
                liberarLista(visitados);
                for (int k = 0; k < altura; k++) 
                    free(mapa[k]);
                free(mapa);
                return 2;
            }
        }

        // Se encontrar o baú (célula com valor 0), está certo
        if (mapa[i][j] == 0) {
            printf("*");
            liberarLista(visitados);
            for (int k = 0; k < altura; k++) 
                free(mapa[k]);
            free(mapa);
            return 1;
        }

        // Se já visitou essa posição, significa loop:
        if (verificarDuplicata(visitados, i, j) == 1) {
            printf("!");
            liberarLista(visitados);
            for (int k = 0; k < altura; k++) 
                free(mapa[k]);
            free(mapa);
            return 2;
        } else {
            adicionarNo(&visitados, i, j);
        }

        // Atualiza o comando conforme a nova célula
        if (mapa[i][j] == 1) comando = 1;
        else if (mapa[i][j] == 2) comando = 2;
        else if (mapa[i][j] == 3) comando = 3;
        else if (mapa[i][j] == 4) comando = 4;
    }

    // Só para garantir
    liberarLista(visitados);
    for (int k = 0; k < altura; k++) 
        free(mapa[k]);
    free(mapa);

    return 0;
}
