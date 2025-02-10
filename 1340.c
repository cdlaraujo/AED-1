#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

// Observação:
//Algumas partes deste código foram adaptadas a partir de soluções encontradas na internet
// e de discussões no fórum "Programming Help"
// Foram adicionadas mensagens de debug para auxiliar na análise do fluxo durante a execução.


typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Inicializa a pilha: define o topo como -1 (indicando que está vazia)
void init_stack(Stack* s) {
    s->top = -1;
}

// Insere um elemento no topo da pilha
void push_stack(Stack* s, int value) {
    s->data[++(s->top)] = value;
    // Debug: mostrar operação de push na pilha
    printf("DEBUG [STACK]: push %d (top agora = %d)\n", value, s->top);
}

// Retorna o elemento no topo da pilha (sem remover)
int top_stack(Stack* s) {
    return s->data[s->top];
}

// Remove o elemento do topo da pilha
void pop_stack(Stack* s) {
    // Debug: mostrar operação de pop na pilha
    printf("DEBUG [STACK]: pop %d (top antes = %d)\n", s->data[s->top], s->top);
    --(s->top);
}

// Verifica se a pilha está vazia
bool is_empty_stack(Stack* s) {
    return s->top == -1;
}


typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} Queue;

// Inicializa a fila: front e rear começam em 0
void init_queue(Queue* q) {
    q->front = q->rear = 0;
}

// Insere um elemento no final da fila
void push_queue(Queue* q, int value) {
    q->data[q->rear++] = value;
    // Debug: mostrar operação de push na fila
    printf("DEBUG [QUEUE]: push %d (rear agora = %d)\n", value, q->rear);
}

// Retorna o elemento da frente da fila (sem remover)
int front_queue(Queue* q) {
    return q->data[q->front];
}


// Remove o elemento da frente da fila
void pop_queue(Queue* q) {
    // Debug: mostrar operação de pop na fila
    printf("DEBUG [QUEUE]: pop %d (front antes = %d)\n", q->data[q->front], q->front);
    q->front++;
}

// Verifica se a fila está vazia
bool is_empty_queue(Queue* q) {
    return q->front == q->rear;
}

// =================== FILA DE PRIORIDADES (PRIORITY QUEUE) ===================

// A prioridade é definida pelo maior valor:
typedef struct {
    int data[MAX_SIZE];
    int size;
} PriorityQueue;

// Inicializa a fila de prioridades
void init_pq(PriorityQueue* pq) {
    pq->size = 0;
}


// Insere um elemento e ordena a fila para manter o maior elemento na frente
void push_pq(PriorityQueue* pq, int value) {
    pq->data[pq->size++] = value;
    // "Bubble up" para manter a ordem decrescente
    for (int i = pq->size - 1; i > 0 && pq->data[i] > pq->data[i - 1]; i--) {
        int temp = pq->data[i];
        pq->data[i] = pq->data[i - 1];
        pq->data[i - 1] = temp;
    }
    // Debug: mostrar operação de push na PQ
    printf("DEBUG [PQ]: push %d (size agora = %d)\n", value, pq->size);
}

// Retorna o elemento com maior prioridade (maior valor)
int top_pq(PriorityQueue* pq) {
    return pq->data[0];
}

// Remove o elemento com maior prioridade
void pop_pq(PriorityQueue* pq) {
    // Debug: mostrar operação de pop na PQ
    printf("DEBUG [PQ]: pop %d (size antes = %d)\n", pq->data[0], pq->size);
    for (int i = 0; i < pq->size - 1; i++) {
        pq->data[i] = pq->data[i + 1];
    }
    pq->size--;
}


// Verifica se a fila de prioridades está vazia
bool is_empty_pq(PriorityQueue* pq) {
    return pq->size == 0;
}

// =================== FUNÇÃO MAIN ===================

int main() {
    int n, operacao, numero;
    // Flag de debug: altere para false para desativar as mensagens de debug
    bool debug = true;

    // Lê o número de operações até EOF
    while (scanf("%d", &n) != EOF) {
        // Inicializa as estruturas de dados
        Stack stack;
        Queue queue;
        PriorityQueue pq;
        init_stack(&stack);
        init_queue(&queue);
        init_pq(&pq);

        
        // "Flags" para indicar se cada estrutura é possível"
        bool possible_stack = true, possible_queue = true, possible_pq = true;

        if (debug)
            printf("DEBUG: Iniciando processamento de %d operações...\n", n);

        // Processa as operações
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &operacao, &numero);
            if (debug)
                printf("DEBUG: Operação %d, número %d\n", operacao, numero);

            if (operacao == 1) {
                // Inserção: adiciona o número em cada estrutura, se ainda possível
                if (possible_stack) {
                    push_stack(&stack, numero);
                }
                if (possible_queue) {
                    push_queue(&queue, numero);
                }
                if (possible_pq) {
                    push_pq(&pq, numero);
                }
            } else {
                // Remoção: verifica se o número removido bate com o esperado em cada estrutura

                // Pilha (stack)
                if (possible_stack) {
                    if (is_empty_stack(&stack)) {
                        if (debug)
                            printf("DEBUG [STACK]: Tentou remover, mas a pilha está vazia (esperava %d)\n", numero);
                        possible_stack = false;
                    } else if (top_stack(&stack) != numero) {
                        if (debug)
                            printf("DEBUG [STACK]: Topo %d não confere com %d\n", top_stack(&stack), numero);
                        possible_stack = false;
                    } else {
                        pop_stack(&stack);
                    }
                }

                // Fila (queue)
                if (possible_queue) {
                    if (is_empty_queue(&queue)) {
                        if (debug)
                            printf("DEBUG [QUEUE]: Tentou remover, mas a fila está vazia (esperava %d)\n", numero);
                        possible_queue = false;
                    } else if (front_queue(&queue) != numero) {
                        if (debug)
                            printf("DEBUG [QUEUE]: Frente %d não confere com %d\n", front_queue(&queue), numero);
                        possible_queue = false;
                    } else {
                        pop_queue(&queue);
                    }
                }

                // Fila de Prioridades (priority queue)
                if (possible_pq) {
                    if (is_empty_pq(&pq)) {
                        if (debug)
                            printf("DEBUG [PQ]: Tentou remover, mas a PQ está vazia (esperava %d)\n", numero);
                        possible_pq = false;
                    } else if (top_pq(&pq) != numero) {
                        if (debug)
                            printf("DEBUG [PQ]: Topo %d não confere com %d\n", top_pq(&pq), numero);
                        possible_pq = false;
                    } else {
                        pop_pq(&pq);
                    }
                }
            }
        }

        // Determina qual estrutura de dados se comportou conforme esperado
        if (possible_stack && !possible_queue && !possible_pq)
            printf("stack\n");
        else if (!possible_stack && possible_queue && !possible_pq)
            printf("queue\n");
        else if (!possible_stack && !possible_queue && possible_pq)
            printf("priority queue\n");
        else if (!possible_stack && !possible_queue && !possible_pq)
            printf("impossible\n");
        else
            printf("not sure\n");

        if (debug)
            printf("DEBUG: Final do processamento desta instância.\n\n");
    }

    return 0;
}
