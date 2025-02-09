#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void append_node_sorted(node** head, int new_data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = new_data;
    new_node->next = NULL;
    
    if (*head == NULL || (*head)->data >= new_data) {
        new_node->next = *head;
        *head = new_node;
        return;
    }
    
    node* current = *head;
    while (current->next != NULL && current->next->data < new_data) {
        current = current->next;
    }
    
    new_node->next = current->next;
    current->next = new_node;
}

void print_list(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int NC, N, h;
    
    printf("Digite o número de casos (NC): ");
    scanf("%d", &NC);
    
    node* head = NULL; 
    
    for (int i = 0; i < NC; ++i) {
        printf("Digite o número de elementos para o caso %d: ", i + 1);
        scanf("%d", &N);
        for (int j = 0; j < N; j++) {
            printf("Digite um valor: ");
            scanf("%d", &h);
            append_node_sorted(&head, h);
        }
    }
    
    printf("\nLista ordenada: ");
    print_list(head);
    
    node* current = head;
    while (current != NULL) {
        node* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}
