#include <stdio.h>
#include <stdlib.h>

typedef struct TipoItem {
    int chave;
    struct TipoItem *prox;
} TipoItem;

typedef struct {
    TipoItem *topo;
} TipoPilhaD;

void push(TipoPilhaD *pPilha, int x) {
    TipoItem *node = (TipoItem*)malloc(sizeof(TipoItem));
    if (node == NULL) {
        printf("Erro de memória!\n");
        return;
    }
    node->chave = x;
    node->prox = pPilha->topo;
    pPilha->topo = node;
}

int pop(TipoPilhaD *pPilha, int *px) {
    if (pPilha->topo == NULL) return 0;
    TipoItem *temp = pPilha->topo;
    *px = temp->chave;
    pPilha->topo = temp->prox;
    free(temp);
    return 1;
}

int main() {
    TipoPilhaD pPilha;
    int i, n, x;
    pPilha.topo = NULL; // Inicializa Pilha

    printf("Quantos números serão inseridos? ");
    scanf("%d", &n);

    for (i = 0; i < n; ++i) {
        scanf("%d", &x);
        if (x % 2 == 0) 
            push(&pPilha, x);
        else if (pop(&pPilha, &x) == 1) 
            printf("%d\n", x);
    }
    return 0;
}
