##include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int number;
    struct node *ptrpro;
    struct node *ptrant;
} node;

int const MAX = 500000;

int main() {
    int V[MAX];

    int key;

    srand(time(0));

    // Preenchendo o vetor V com valores aleatórios
    for (int i = 0; i < MAX; i++) {
        V[i] = rand() % 1000;
    }

    // Criando nós para a lista duplamente encadeada
    node* head = (node*)malloc(sizeof(node));
    node* new_node;
    node* current_node;

    // Inicializando o primeiro nó
    head->number = V[0];
    head->ptrant = NULL;
    head->ptrpro = NULL;
    current_node = head;

    // Construindo a lista duplamente encadeada
    for (int j = 1; j < MAX; j++) {
        new_node = (node*)malloc(sizeof(node));
        new_node->number = V[j];
        new_node->ptrant = current_node;
        new_node->ptrpro = NULL;
        current_node->ptrpro = new_node;
        current_node = new_node;
    }

    current_node = head;

    // Algoritmo InsertSort
    for (int k = 0; k < MAX; k++){
        while(current_node->ptrant != NULL){
            key = current_node->number;
            current_node = current_node->ptrant;
            if (current_node->number <= key){
                // Faz o esquema de inserir novo nó antes de current node
                node* new_node = (node*)malloc(sizeof(node));
                
            }
        }
    }



    // Liberação de memória
    current_node = head;
    while (current_node != NULL) {
        node* temp = current_node;
        current_node = current_node->ptrpro;
        free(temp);
    }

    return 0;
}


int function(node* head, node* key_node, node* new_node, int key){
    // todo
}
