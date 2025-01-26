#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node* next;
} node;

// Função de hash
int hash(int key, int table_size) {
    return key % table_size;
}

// Criação da tabela hash
node** create_hash_table(int table_size) {
    node** hash_table = (node**)malloc(table_size * sizeof(node*));
    for (int i = 0; i < table_size; i++) {
        hash_table[i] = NULL; // Inicializa cada posição como NULL
    }
    return hash_table;
}

// Inserção na tabela hash
void insert_hash_table(int K, node** hash_table, int table_size) {
    int hash_index = hash(K, table_size); // Calcula índice usando a função hash

    // Cria novo nó
    node* new_node = (node*)malloc(sizeof(node));
    new_node->key = K;
    new_node->next = NULL;

    // Insere na lista encadeada da posição hash_index
    if (hash_table[hash_index] == NULL) {
        hash_table[hash_index] = new_node;
    } else {
        node* current = hash_table[hash_index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Imprime a tabela hash
void print_hash_table(node** hash_table, int table_size) {
    for (int i = 0; i < table_size; i++) {
        printf("%d ->", i);
        node* current = hash_table[i];
        while (current != NULL) {
            printf(" %d ->", current->key);
            current = current->next;
        }
        printf(" \\\n");
    }
}

// Libera a memória da tabela hash
void free_hash_table(node** hash_table, int table_size) {
    for (int i = 0; i < table_size; i++) {
        node* current = hash_table[i];
        while (current != NULL) {
            node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hash_table);
}

int main() {
    int N, M, C, K;
    scanf("%d", &N); // Número de casos de teste

    while (N--) {
        scanf("%d", &M); // Tamanho da tabela
        scanf("%d", &C); // Número de chaves a inserir

        // Criação da tabela hash
        node** hash_table = create_hash_table(M);

        for (int i = 0; i < C; i++) {
            scanf("%d", &K);
            insert_hash_table(K, hash_table, M);
        }

        // Imprime a tabela hash
        print_hash_table(hash_table, M);

        // Libera a memória alocada
        free_hash_table(hash_table, M);
    }

    return 0;
}
