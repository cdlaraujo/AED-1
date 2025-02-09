#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_DESC 100
#define MAX_LENGTH 17 // Maximum word length (16 + 1 for null terminator)
#define HASH_TABLE_SIZE 2003 // Prime number for better hashing

typedef struct Node {
    char word[MAX_LENGTH];
    int value;
    struct Node* next;
} Node;

Node* hashTable[HASH_TABLE_SIZE];

unsigned int hash(const char* str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash * 31 + *str) % HASH_TABLE_SIZE;
        str++;
    }
    return hash;
}

void insert(const char* word, int value) {
    unsigned int index = hash(word);
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->value = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

int search(const char* word) {
    unsigned int index = hash(word);
    Node* current = hashTable[index];
    while (current) {
        if (strcmp(current->word, word) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return 0;
}

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

    scanf("%d %d", &M, &N);

    memset(hashTable, 0, sizeof(hashTable));

    for (int i = 0; i < M; i++) {
        char word[MAX_LENGTH];
        int value;
        scanf("%s %d", word, &value);
        insert(word, value);
    }

    for (int i = 0; i < N; i++) {
        char line[1001];
        int totalSalary = 0;

        while (1) {
            fgets(line, sizeof(line), stdin);
            if (line[0] == '.') break;

            char* token = strtok(line, " \n");
            while (token) {
                totalSalary += search(token);
                token = strtok(NULL, " \n");
            }
        }

        printf("%d\n", totalSalary);
    }

    freeHashTable();

    return 0;
}
