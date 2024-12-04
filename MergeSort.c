#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int number;
    struct node *ptrpro;
    struct node *ptrant;
} node;

// Helper function to print the list
void print_list(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("%d ", current->number);
        current = current->ptrpro;
    }
    printf("\n");
}

// Function to split the list into two halves
node* split(node* head) {
    node* slow = head;
    node* fast = head;
    while (fast->ptrpro != NULL && fast->ptrpro->ptrpro != NULL) {
        slow = slow->ptrpro;
        fast = fast->ptrpro->ptrpro;
    }
    node* second_half = slow->ptrpro;
    slow->ptrpro = NULL; // Break the list
    if (second_half != NULL) {
        second_half->ptrant = NULL; // Disconnect the second half
    }
    return second_half;
}

// Function to merge two sorted halves
node* merge(node* first, node* second) {
    if (!first) return second;
    if (!second) return first;

    if (first->number <= second->number) {
        first->ptrpro = merge(first->ptrpro, second);
        first->ptrpro->ptrant = first;
        first->ptrant = NULL;
        return first;
    } else {
        second->ptrpro = merge(first, second->ptrpro);
        second->ptrpro->ptrant = second;
        second->ptrant = NULL;
        return second;
    }
}

// Merge sort function
node* merge_sort(node* head) {
    if (!head || !head->ptrpro) {
        return head; // Base case: 0 or 1 node
    }

    // Split the list into two halves
    node* second_half = split(head);

    // Recursively sort both halves
    head = merge_sort(head);
    second_half = merge_sort(second_half);

    // Merge the sorted halves
    return merge(head, second_half);
}

// Main function
int main() {
    srand(time(0));

    // Create the doubly linked list
    node* head = (node*)malloc(sizeof(node));
    node* current = head;
    current->number = rand() % 1000;
    current->ptrant = NULL;

    for (int i = 1; i < 10; i++) { // Small size for demonstration
        node* new_node = (node*)malloc(sizeof(node));
        new_node->number = rand() % 1000;
        new_node->ptrpro = NULL;
        new_node->ptrant = current;
        current->ptrpro = new_node;
        current = new_node;
    }

    printf("Original list:\n");
    print_list(head);

    // Perform merge sort
    head = merge_sort(head);

    printf("Sorted list:\n");

    
    print_list(head);

    // Free memory
    current = head;
    while (current != NULL) {
        node* temp = current;
        current = current->ptrpro;
        free(temp);
    }

    return 0;
}

