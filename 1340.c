#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void stack_init(Stack* s) {
    s->top = -1;
}

void stack_push(Stack* s, int value) {
    s->data[++(s->top)] = value;
}

int stack_top(Stack* s) {
    return s->data[s->top];
}

void stack_pop(Stack* s) {
    --(s->top);
}

bool stack_is_empty(Stack* s) {
    return s->top == -1;
}

typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} Queue;

void queue_init(Queue* q) {
    q->front = q->rear = 0;
}

void queue_push(Queue* q, int value) {
    q->data[q->rear++] = value;
}

int queue_front(Queue* q) {
    return q->data[q->front];
}

void queue_pop(Queue* q) {
    q->front++;
}

bool queue_is_empty(Queue* q) {
    return q->front == q->rear;
}

// lista de prioridades
typedef struct {
    int data[MAX_SIZE];
    int size;
} PriorityQueue;

void pq_init(PriorityQueue* pq) {
    pq->size = 0;
}

void pq_push(PriorityQueue* pq, int value) {
    pq->data[pq->size++] = value;
    for (int i = pq->size - 1; i > 0 && pq->data[i] > pq->data[i - 1]; i--) {
        int temp = pq->data[i];
        pq->data[i] = pq->data[i - 1];
        pq->data[i - 1] = temp;
    }
}

int pq_top(PriorityQueue* pq) {
    return pq->data[0];
}

void pq_pop(PriorityQueue* pq) {
    for (int i = 0; i < pq->size - 1; i++) {
        pq->data[i] = pq->data[i + 1];
    }
    pq->size--;
}

bool pq_is_empty(PriorityQueue* pq) {
    return pq->size == 0;
}

int main() {
    int n, operacao, numero;

    while (scanf("%d", &n) != EOF) {
        Stack stack;
        Queue queue;
        PriorityQueue pq;

        stack_init(&stack);
        queue_init(&queue);
        pq_init(&pq);

        bool is_stack = true, is_queue = true, is_priority_queue = true;

        for (int i = 0; i < n; i++) {
            scanf("%d %d", &operacao, &numero);

            if (operacao == 1) {
                if (is_stack) stack_push(&stack, numero);
                if (is_queue) queue_push(&queue, numero);
                if (is_priority_queue) pq_push(&pq, numero);
            } else {
                if (is_stack) {
                    if (stack_is_empty(&stack) || stack_top(&stack) != numero) {
                        is_stack = false;
                    } else {
                        stack_pop(&stack);
                    }
                }

                if (is_queue) {
                    if (queue_is_empty(&queue) || queue_front(&queue) != numero) {
                        is_queue = false;
                    } else {
                        queue_pop(&queue);
                    }
                }

                if (is_priority_queue) {
                    if (pq_is_empty(&pq) || pq_top(&pq) != numero) {
                        is_priority_queue = false;
                    } else {
                        pq_pop(&pq);
                    }
                }
            }
        }

        if (is_stack && !is_queue && !is_priority_queue) {
            printf("stack\n");
        } else if (!is_stack && is_queue && !is_priority_queue) {
            printf("queue\n");
        } else if (!is_stack && !is_queue && is_priority_queue) {
            printf("priority queue\n");
        } else if (!is_stack && !is_queue && !is_priority_queue) {
            printf("impossible\n");
        } else {
            printf("not sure\n");
        }
    }

    return 0;
}
