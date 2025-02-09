#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int i; 
    int j; 
    struct node* next; 
} node;

void append_node(node** head, int x, int y) {
    node* new_node = (node*)malloc(sizeof(node)); 
    new_node->i = x;
    new_node->j = y; 
    new_node->next = NULL; 

    if (*head == NULL) {
        *head = new_node;
    } else {
        node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}


int check_duplicates(node* head, int x, int y) {
    while (head != NULL) {
        if (head->i == x && head->j == y) return 1;
        head = head->next; 
    }
    return 0; 
}

void free_list(node* head) {
    node* current;
    while (head != NULL) {
        current = head; 
        head = head->next; 
        free(current); 
    }
}

int main() {
    int width, height;
    int i, j; 
    char c;

    scanf("%d", &width);
    scanf("%d", &height);

    int** map = (int**)malloc(height * sizeof(int*));
    for (i = 0; i < height; i++) {
        map[i] = (int*)malloc(width * sizeof(int));
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            scanf(" %c", &c);
            switch (c) {
                case '>': map[i][j] = 1; break; // direita
                case '<': map[i][j] = 2; break; // esquerda
                case '^': map[i][j] = 3; break; // para cima
                case 'v': map[i][j] = 4; break; // para baixo
                case '.': map[i][j] = 5; break; // sem comando
                case '*': map[i][j] = 0; break; // baú encontrado
                default: map[i][j] = -1; break; // inválido
            }
        }
    }

    i = 0, j = 0;
    node* head = NULL; 
    int command = map[i][j];
    append_node(&head, i, j); 

    while (1) {
        while (map[i][j] == 5) {
            if (command == 1) j++;       
            else if (command == 2) j--;  
            else if (command == 3) i--;  
            else if (command == 4) i++;   

            if (i < 0 || j < 0 || j >= width || i >= height) {
                printf("!"); 
                free_list(head);
                for (int k = 0; k < height; k++) free(map[k]);
                free(map);
                return 2;
            }
        }

        if (map[i][j] == 0) {
            printf("*"); 
            free_list(head);
            for (int k = 0; k < height; k++) free(map[k]);
            free(map);
            return 1;
        }

        if (check_duplicates(head, i, j) == 1) {
            printf("!"); 
            free_list(head); 
            for (int k = 0; k < height; k++) free(map[k]);
            free(map);
            return 2;
        } else {
            append_node(&head, i, j);
        }

        if (map[i][j] == 1) command = 1; 
        else if (map[i][j] == 2) command = 2; 
        else if (map[i][j] == 3) command = 3;
        else if (map[i][j] == 4) command = 4; 
    }

    free_list(head);
    for (int k = 0; k < height; k++) free(map[k]);
    free(map);

    return 0;
}
