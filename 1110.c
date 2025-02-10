#include <stdlib.h>
#include <stdio.h>

struct DequeNode {
    int val;
    struct DequeNode *prev;
    struct DequeNode *next;
};

struct Deque {
    int size; 
    struct DequeNode *front; 
    struct DequeNode *back;  
};

// Adicionar
void push_front(struct Deque* dq, int num) {
    dq->size++;
    struct DequeNode* new_node = malloc(sizeof(struct DequeNode));
    new_node->val = num;
    new_node->prev = NULL;
    new_node->next = dq->front;

    if(dq->front != NULL) {
        dq->front->prev = new_node;
    }
    dq->front = new_node;

    if(dq->back == NULL) {
        dq->back = new_node;
    }
}

// d#include <stdlib.h>
#include <stdio.h>

// Double-linked list node
struct DequeNode {
    int val;
    struct DequeNode *prev;
    struct DequeNode *next;
};

struct Deque {
    int size;              
    struct DequeNode *front; 
    struct DequeNode *back;  
};

// Adicionar ao inicio
void push_front(struct Deque* dq, int num) {
    dq->size++;
    struct DequeNode* new_node = malloc(sizeof(struct DequeNode));
    new_node->val = num;
    new_node->prev = NULL;
    new_node->next = dq->front;

    if(dq->front != NULL) {
        dq->front->prev = new_node;
    }
    dq->front = new_node;

    // First node case
    if(dq->back == NULL) {
        dq->back = new_node;
    }
}

// Adicionar ao final
void push_back(struct Deque* dq, int num) {
    dq->size++;
    struct DequeNode* new_node = malloc(sizeof(struct DequeNode));
    new_node->val = num;
    new_node->prev = dq->back;
    new_node->next = NULL;

    if(dq->back != NULL) {
        dq->back->next = new_node;
    }
    dq->back = new_node;

    if(dq->front == NULL) {
        dq->front = new_node;
    }
}

// remover do incio
void pop_front(struct Deque* dq) {
    if(dq->size == 0) return;  
    
    dq->size--;
    struct DequeNode* old_front = dq->front;
    dq->front = old_front->next;
    
    if(dq->front != NULL) {
        dq->front->prev = NULL;
    } else {
        dq->back = NULL; 
    }
    
    free(old_front);
}

void pop_back(struct Deque* dq) {
    if(dq->size == 0) return;
    
    dq->size--;
    struct DequeNode* old_back = dq->back;
    dq->back = old_back->prev;
    
    if(dq->back != NULL) {
        dq->back->next = NULL;
    } else {
        dq->front = NULL; 
    }
    
    free(old_back);
}

int front_val(struct Deque* dq) {
    return dq->front->val;
}

int back_val(struct Deque* dq) {
    return dq->back->val;
}

int deque_size(struct Deque* dq) {
    return dq->size;
}

int is_empty(struct Deque* dq) {
    return dq->size == 0;
}

void init_deque(struct Deque* dq) {
    dq->size = 0;
    dq->front = dq->back = NULL;
}

void cleanup_deque(struct Deque* dq) {
    while(!is_empty(dq)) {
        pop_front(dq); 
    }
}

int main() {
    int n, first;
    struct Deque deck; 

    while(1) {
        scanf("%d", &n);
        if(n == 0) break; 
        
        init_deque(&deck);
        
        for(int i = 1; i <= n; i++) {
            push_back(&deck, i);
        }
        
        printf("Discarded cards: ");
        first = 1; 
        
        while(deque_size(&deck) > 1) {
            if(!first) {
                printf(", "); 
            } else {
                first = 0;
            }
            
            printf("%d", front_val(&deck));
            pop_front(&deck);
            
            push_back(&deck, front_val(&deck));
            pop_front(&deck);
        }
        
        printf("\nRemaining card: %d\n", front_val(&deck));
        cleanup_deque(&deck); 
    }

    return 0;
}A
void push_back(struct Deque* dq, int num) {
    dq->size++;
    struct DequeNode* new_node = malloc(sizeof(struct DequeNode));
    new_node->val = num;
    new_node->prev = dq->back;
    new_node->next = NULL;

    if(dq->back != NULL) {
        dq->back->next = new_node;
    }
    dq->back = new_node;

    // First node case
    if(dq->front == NULL) {
        dq->front = new_node;
    }
}

void pop_front(struct Deque* dq) {
    if(dq->size == 0) return;  
    
    dq->size--;
    struct DequeNode* old_front = dq->front;
    dq->front = old_front->next;
    
    if(dq->front != NULL) {
        dq->front->prev = NULL;
    } else {
        dq->back = NULL; 
    }
    
    free(old_front);
}


void pop_back(struct Deque* dq) {
    if(dq->size == 0) return;
    
    dq->size--;
    struct DequeNode* old_back = dq->back;
    dq->back = old_back->prev;
    
    if(dq->back != NULL) {
        dq->back->next = NULL;
    } else {
        dq->front = NULL;
    }
    
    free(old_back);
}

int front_val(struct Deque* dq) {
    return dq->front->val;
}

int back_val(struct Deque* dq) {
    return dq->back->val;
}

int deque_size(struct Deque* dq) {
    return dq->size;
}

int is_empty(struct Deque* dq) {
    return dq->size == 0;
}

void init_deque(struct Deque* dq) {
    dq->size = 0;
    dq->front = dq->back = NULL;
}

// Limpar tudo
void cleanup_deque(struct Deque* dq) {
    while(!is_empty(dq)) {
        pop_front(dq); 
    }
}

int main() {
    int n, first;
    struct Deque deck;

    while(1) {
        scanf("%d", &n);
        if(n == 0) break; 
        
        init_deque(&deck);
        
        for(int i = 1; i <= n; i++) {
            push_back(&deck, i);
        }
        
        printf("Discarded cards: ");
        first = 1; // um flag
        
        while(deque_size(&deck) > 1) {
            if(!first) {
                printf(", ");
            } else {
                first = 0;
            }
            
            printf("%d", front_val(&deck)); 
            pop_front(&deck);
            
            push_back(&deck, front_val(&deck));
            pop_front(&deck);
        }
        
        printf("\nRemaining card: %d\n", front_val(&deck));
        cleanup_deque(&deck);
    }

    return 0;
}
