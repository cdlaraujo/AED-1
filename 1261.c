#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// define like that //
#define MAX_WORDS 1000
#define MAX_DESC 100
#define MAX_LENGTH 17 
#define HASH_TABLE_SIZE 2003 

// Flag de debug: 1 ativa as mensagens; 0 desativa.
int debug = 1;

typedef struct Node {
    char word[MAX_LENGTH];
    int value;
    struct Node* next;
} Node;

// A tabela de hash é um vetor global de ponteiros para Node.
Node* hashTable[HASH_TABLE_SIZE];

/* Função hash:
 * Utiliza a multiplicação por 31 e o módulo com HASH_TABLE_SIZE para calcular o índice.
 */
unsigned int hash(const char* str) {
    unsigned int h = 0;
    while (*str) {
        h = (h * 31 + *str) % HASH_TABLE_SIZE;
        str++;
    }
    if (debug)
        printf("DEBUG: Hash calculado = %u\n", h);
    return h;
}

/* Insere a palavra com seu valor na tabela de hash */
void insert(const char* word, int value) {
    unsigned int index = hash(word);
    if (debug)
        printf("DEBUG: Inserindo '%s' com valor %d no índice %u\n", word, value, index);
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->value = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

/* Procura a palavra na tabela de hash e retorna seu valor; retorna 0 se não encontrada */
int search(const char* word) {
    unsigned int index = hash(word);
    if (debug)
        printf("DEBUG: Procurando '%s' no índice %u\n", word, index);
    Node* current = hashTable[index];
    while (current) {
        if (strcmp(current->word, word) == 0) {
            if (debug)
                printf("DEBUG: Palavra '%s' encontrada com valor %d\n", word, current->value);
            return current->value;
        }
        current = current->next;
    }
    if (debug)
        printf("DEBUG: Palavra '%s' não encontrada. Retornando 0\n", word);
    return 0;
}

/* Libera toda a memória alocada para a tabela de hash */
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

void process_salary_case() {
    char line[1001];
    int totalSalary = 0;
    
    if (debug)
        printf("DEBUG: Iniciando processamento do caso de salário...\n");
    
    while (1) {
        if (!fgets(line, sizeof(line), stdin))
            break;  // Se não conseguir ler mais linhas, sai
        // Ignora linhas vazias
        if (line[0] == '\n')
            continue;
        // Se a linha começa com '.', encerra este caso
        if (line[0] == '.')
            break;
        if (debug)
            printf("DEBUG: Linha lida: %s", line);
        char* token = strtok(line, " \n");
        while (token) {
            totalSalary += search(token);
            token = strtok(NULL, " \n");
        }
    }
    
    printf("%d\n", totalSalary);
}

int main() {
    int M, N;
    
    if (scanf("%d %d", &M, &N) != 2) {
        fprintf(stderr, "Erro na leitura de M e N.\n");
        return 1;
    }
    
    if (debug)
        printf("DEBUG: M = %d, N = %d\n", M, N);
    
    // Inicializa a tabela de hash
    memset(hashTable, 0, sizeof(hashTable));
    
    // Lê o dicionário de palavras e seus valores
    for (int i = 0; i < M; i++) {
        char word[MAX_LENGTH];
        int value;
        if (scanf("%s %d", word, &value) != 2) {
            fprintf(stderr, "Erro na leitura da palavra e valor.\n");
            return 1;
        }
        insert(word, value);
    }
    
    // Consome o caractere de nova linha pendente // por que? - conversa 01/01/2025
    getchar();
    
    // Processa cada um dos N casos de salário
    for (int i = 0; i < N; i++) {
        if (debug)
            printf("DEBUG: Processando caso de salário %d\n", i + 1);
        process_salary_case();
    }
    
    freeHashTable();
    
    return 0;
}
