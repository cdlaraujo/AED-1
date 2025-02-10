#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define MAX 1000000

typedef struct {
    int stack[MAX]; // elementos normais
    int min_stack[MAX]; // guarda os mínimos
    int topo; // índice do topo
} Pilha;

// Começa uma pilha nova
void start(Pilha *p) {
    p->topo = -1; // topo inválido
}

// Coloca um valor na pilha
void push(Pilha *p, int num) {
    if (p->topo + 1 >= MAX) {
        return; // cheio
    }
    p->topo++;
    p->stack[p->topo] = num;

    // Atualiza o mínimo atual
    if (p->topo == 0 || num < p->min_stack[p->topo - 1]) {
        p->min_stack[p->topo] = num;
    } else {
        // Repete o mínimo anterior
        p->min_stack[p->topo] = p->min_stack[p->topo - 1];
    }
}

// Tira o último elemento
void pop(Pilha *p) {
    if (p->topo == -1) {
        printf("EMPTY\n"); // está vazio
    } else {
        p->topo--; // diminui o topo
    }
}

// Mostra o menor valor
void min(Pilha *p) {
    if (p->topo == -1) {
        printf("EMPTY\n");
    } else {
        printf("%d\n", p->min_stack[p->topo]);
    }
}

int main() {
    Pilha p;
    start(&p);

    int n, x;
    char cmd[6]; // "PUSH", "POP", "MIN"

    scanf("%d", &n); 

    for(int i = 0; i < n; i++) {
        scanf("%s", cmd);
        
        if (strcmp(cmd, "PUSH") == 0) {
            scanf("%d", &x);
            push(&p, x);
            // printf("--> Pushed %d\n", x); // para debug
        } else if (strcmp(cmd, "POP") == 0) {
            pop(&p);
        } else if (strcmp(cmd, "MIN") == 0) {
            min(&p);
        } else {
            printf("INVALIDO\n"); // comando errado
            return 1;
        }
    }

    return 0;
}
