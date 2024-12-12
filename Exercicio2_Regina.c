#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int senha;
  struct Node *proximo;
} Node;

typedef struct Fila {
  Node* inicio;
  Node* fim;
}

Fila* inicializaFila(){
  Fila* fila = (fila*)malloc(sizeof(Fila));
  fila->inicio = NULL;
  fila->fim = NULL;
  return fila;
}

void chegadaCliente(Fila* fila, int senha) {
  Node* newnode = (Node*)malloc(sizeof(Node));
  newnode->senha = senha;
  newnode->proximo = NULL;

  if(fila->inicio = NULL){
    fila->inicio = newnode;
    fila->fim = newnode;
  } else {
    fila->fim->proximo = newnode;
    fila->fim = newnode;
  }
}

void atenderCliente(Fila* fila) {
    if (fila->inicio == NULL) printf("Não há clientes na fila.\n");
    else {
        Nodo* temp = fila->inicio;
        printf("Atendendo cliente com senha %d.\n", temp->senha);
        fila->inicio = fila->inicio->proximo;

        if (fila->inicio == NULL) {
            fila->fim = NULL;
        }

        free(temp);
    }
}

int main() {
  FILA* fila = inicializaFila();
  chegadacliente(fila, 5);
  chegadacliente(fila, 5);
  atenderCliente(fila);
  atenderCliente(fila);
}
