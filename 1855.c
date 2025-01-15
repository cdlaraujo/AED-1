#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list nodes
typedef struct node {
    int i; 
    int j; 
    struct node* next; 
} node;

// Function to append a new node to the linked list
void append_node(node** head, int x, int y) {
    node* new_node = (node*)malloc(sizeof(node)); 
    new_node->i = x;
    new_node->j = y; 
    new_node->next = NULL; 

    if (*head == NULL) {
        // If the list is empty, set the head to the new node
        *head = new_node;
    } else {
        // Otherwise, traverse to the end of the list and append the new node
        node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to check if a pair of coordinates (x, y) exists in the linked list
int check_duplicates(node* head, int x, int y) {
    while (head != NULL) {
        // If the current node matches the coordinates, return 1 (true)
        if (head->i == x && head->j == y) return 1;
        head = head->next; 
    }
    return 0; // No duplicates found
}

// Function to free the memory used by the linked list
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

    // Get the width and height of the map
    scanf("%d", &width);
    scanf("%d", &height);

    // Dynamically allocate memory for the map
    int** map = (int**)malloc(height * sizeof(int*));
    for (i = 0; i < height; i++) {
        map[i] = (int*)malloc(width * sizeof(int));
    }

    // Populate the map based on character input
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            scanf(" %c", &c); // Read a single character
            switch (c) {
                case '>': map[i][j] = 1; break; // Move right
                case '<': map[i][j] = 2; break; // Move left
                case '^': map[i][j] = 3; break; // Move up
                case 'v': map[i][j] = 4; break; // Move down
                case '.': map[i][j] = 5; break; // No command
                case '*': map[i][j] = 0; break; // Target found
                default: map[i][j] = -1; break; // Invalid character
            }
        }
    }

    // Initialize variables
    i = 0, j = 0;
    node* head = NULL; // Create an empty linked list for tracking visited nodes
    int command = map[i][j]; // Get the initial command
    append_node(&head, i, j); 

    while (1) {
        // Handle non-command spaces (continuing the current direction)
        while (map[i][j] == 5) {
            if (command == 1) j++;       
            else if (command == 2) j--;  
            else if (command == 3) i--;  
            else if (command == 4) i++;   

            // Check for out-of-bounds movement
            if (i < 0 || j < 0 || j >= width || i >= height) {
                printf("!"); 
                free_list(head);
                for (int k = 0; k < height; k++) free(map[k]);
                free(map);
                return 2;
            }
        }

        // Check if the current space is the target
        if (map[i][j] == 0) {
            printf("*"); 
            free_list(head);
            for (int k = 0; k < height; k++) free(map[k]);
            free(map);
            return 1;
        }

        // Check for cycles (repeated positions)
        if (check_duplicates(head, i, j) == 1) {
            printf("!"); 
            free_list(head); 
            for (int k = 0; k < height; k++) free(map[k]);
            free(map);
            return 2;
        } else {
            // Add the current position to the list
            append_node(&head, i, j);
        }

        // Update the command based on the current space
        if (map[i][j] == 1) command = 1; 
        else if (map[i][j] == 2) command = 2; 
        else if (map[i][j] == 3) command = 3;
        else if (map[i][j] == 4) command = 4; 
    }

    // Cleanup
    free_list(head);
    for (int k = 0; k < height; k++) free(map[k]);
    free(map);

    return 0;
}
