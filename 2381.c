#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó da lista encadeada
typedef struct node {
    char V[21];
    struct node *ptr;
} node;

// Função para liberar a memória da lista encadeada
void free_list(node *head) {
    while (head) {
        node *temp = head;
        head = head->ptr;
        free(temp);
    }
}

int main() {
    int N, K;               
    char input[1000];       
    node *head = NULL, *tail = NULL; 

    // Lê a entrada e separa os valores iniciais
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d %d", &N, &K);

    // Lê os valores da lista
    for (int i = 0; i < N; i++) {
        fgets(input, sizeof(input), stdin);

        node *new_node = malloc(sizeof(node));
        if (!new_node) {
            perror("Erro ao alocar memória");
            free_list(head);
            return 1;
        }
        sscanf(input, "%20s", new_node->V); // Lê no máximo 20 caracteres
        new_node->ptr = NULL;

        if (tail) {
            tail->ptr = new_node;
        } else {
            head = new_node;
        }
        tail = new_node;
    }

    // Percorre até o K-ésimo nó
    node *current = head;
    for (int i = 1; i < K && current; i++) {
        current = current->ptr;
    }

    if (current) {
        printf("%s\n", current->V);
    } else {
        printf("Índice fora do limite.\n");
    }

    // Libera a memória alocada
    free_list(head);
    return 0;
}
