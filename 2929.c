#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Pilha para armazenar os valores e uma auxiliar para manter o mínimo
int stack[1000000], int minStack[1000000], int topo = -1;

void push(int value) {
    int currentMin = value;
    if (topo != -1) {
        if (minStack[topo] < value)
            currentMin = minStack[topo];
    }
    stack[++topo] = value;
    minStack[topo] = currentMin;
}

void pop() {
    if (top == -1) {
        printf("EMPTY\n");
    } else {
        top--;
    }
}

void printMin() {
    if (top == -1) {
        printf("EMPTY\n");
    } else {
        printf("%d\n", minStack[topo]);
    }
}

int main(void) {
    int N, value;
    char op[5]; // 5 posições para comportar "PUSH", "POP", "MIN" e terminador '\0'

    if (scanf("%d", &N) != 1) {
        return 4;
    }

    while (N--) {
        if (scanf("%s", op) != 1) {
            return 3;
        }

        // Compara as strings usando strcmp
        if (strcmp(op, "PUSH") == 0) {
            if (scanf("%d", &value) != 1) {
                return 1;
            }
            push(value);
        } else if (strcmp(op, "POP") == 0) {
            pop();
        } else if (strcmp(op, "MIN") == 0) {
            printMin();
        } else {
            return 2;
        }
    }

    return 0;
}
