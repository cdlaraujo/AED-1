#include <stdio.h>
#include <stdlib.h>

int main() {
    // Identificadores de entrada e saída
    int N, M;
    
    scanf("%d", &N);

    int* fila = (int*)malloc(N * sizeof(int));
    if (fila == NULL){
        printf("Erro de alocação de memória\n");
        return 1;
    }
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &fila[i]);
    }

    scanf("%d", &M);

    int* saida = (int*)malloc(M * sizeof(int));
    if (saida == NULL){
        printf("Erro de alocação de memória\n");
        return 1;
    }
    
    for (int i = 0; i < M; i++) {
        scanf("%d", &saida[i]);
    }

    int mapa[100001] = {0};  
    
    for (int i = 0; i < M; i++) {
        mapa[saida[i]] = 1;
    }

    node* current == NULL;
    node* head == NULL;
    
    for(int i = 0; i < N; ++i)
    {
        node* new_node = (node*)malloc(sizeof(node));
        if(new_node == NULL)
        {
            printf("Erro de alocação de memória\n");
            return 1;
        }

        new_node->id = fila[i];
        new_node->ptr = NULL;

        if(head == NULL)
        {
            head = new_node;
            current = new_node;
        }
        else
        {
            current->ptr = new_node;
            current = new_node;
        }
    }

    node* temp = head;
    node* prev = NULL;

    while (temp != NULL) {
        if (mapa[temp->id] == 1) {
            if (prev == NULL) {
                head = temp->ptr;  
                free(temp);
                temp = head;  
            } else {
                prev->ptr = temp->ptr;
                free(temp);
                temp = prev->ptr;
            }
        } else {
            prev = temp;
            temp = temp->ptr;
        }
    }

    free(fila);
    free(saida);
    
    return 0;
}
