#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the linked list
typedef struct node {
    char V[21]; 
    struct node *ptr;
} node;

int main() {
    int N, K;               
    char input[1000];       
    char *token;            
    node *head = NULL;      
    node *tail = NULL;      

    fgets(input, sizeof(input), stdin);

    token = strtok(input, "\n"); 
    sscanf(token, "%d %d", &N, &K);

    for (int i = 0; i < N; i++) {
        token = strtok(NULL, "\n");

        node *new_node = (node *)malloc(sizeof(node));
        strcpy(new_node->V, token); 
        new_node->ptr = NULL;     

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->ptr = new_node;
            tail = new_node;
        }
    }

    node *current = head;
    for (int i = 1; i < K; i++) {
        if (current->ptr != NULL) {
            current = current->ptr;
        }
    }

    printf("%s\n", current->V);

    current = head;
    while (current != NULL) {
        node *temp = current;
        current = current->ptr;
        free(temp);
    }

    return 0;
}
