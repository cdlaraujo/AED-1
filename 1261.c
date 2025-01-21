#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_DESC 100
#define MAX_LENGTH 17 // Maximum word length (16 + 1 for null terminator)
#define HASH_TABLE_SIZE 2003 // Prime number for better hashing

// Hash table node structure
typedef struct Node {
    char word[MAX_LENGTH];
    int value;
    struct Node* next;
} Node;

Node* hashTable[HASH_TABLE_SIZE];

// Hash function
unsigned int hash(const char* str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash * 31 + *str) % HASH_TABLE_SIZE;
        str++;
    }
    return hash;
}

// Insert into hash table
void insert(const char* word, int value) {
    unsigned int index = hash(word);
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->value = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Search in hash table
int search(const char* word) {
    unsigned int index = hash(word);
    Node* current = hashTable[index];
    while (current) {
        if (strcmp(current->word, word) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return 0; // Word not found
}

// Free hash table memory
void freeHashTable() {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Node* current = hashTable[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main() {
    int M, N;

    // Read M and N
    scanf("%d %d", &M, &N);

    // Initialize hash table
    memset(hashTable, 0, sizeof(hashTable));

    // Read the dictionary
    for (int i = 0; i < M; i++) {
        char word[MAX_LENGTH];
        int value;
        scanf("%s %d", word, &value);
        insert(word, value);
    }

    // Process job descriptions
    for (int i = 0; i < N; i++) {
        char line[1001];
        int totalSalary = 0;

        // Read job description lines until a period (.)
        while (1) {
            fgets(line, sizeof(line), stdin);
            if (line[0] == '.') break;

            // Split line into words
            char* token = strtok(line, " \n");
            while (token) {
                totalSalary += search(token);
                token = strtok(NULL, " \n");
            }
        }

        // Output the salary for the current job description
        printf("%d\n", totalSalary);
    }

    // Free memory
    freeHashTable();

    return 0;
}
