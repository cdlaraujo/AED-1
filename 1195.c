#include <stdio.h>
#include <stdlib.h> // pra malloc e free

struct No {
    int val; // valor do nó
    struct No *pai; // nó de cima
    struct No *esq; // galho esquerdo
    struct No *dir; // galho direito
};

struct Arvore {
    struct No* raiz; // raiz da árvore
};

// Prepara um nó novo
void setupNo(struct No *no) {
    no->val = 0;
    no->pai = no->esq = no->dir = NULL; // todos null
}

// Apaga um nó e seus filhos
void apagaNo(struct No *no) {
    if(!no) return;
    
    apagaNo(no->esq); // tanto faz esquerda ou direita
    apagaNo(no->dir); 
    free(no);         
}

// Começa uma árvore nova
void iniciaArvore(struct Arvore *arv) {
    arv->raiz = NULL; // sem raiz
}

// Destrói toda a árvore
void destroiArvore(struct Arvore *arv) {
    apagaNo(arv->raiz);
}

// Adiciona um valor na árvore (recursivo)
struct No* insere(struct No *no, int num, struct No *parente) {
    if(!no) {
        no = (struct No*)malloc(sizeof(struct No));
        setupNo(no);
        no->val = num;
        no->pai = parente; 
        return no;
    }
    
    if(num < no->val) {
        no->esq = insere(no->esq, num, no);
    } 
    else if(num > no->val) {
        no->dir = insere(no->dir, num, no);
    }
    // se igual, não faz nada
    
    return no;
}

// Função principal pra adicionar
void add(struct Arvore *arv, int num) {
    arv->raiz = insere(arv->raiz, num, NULL); 
}

// Procura um valor na árvore
struct No* busca(struct No *no, int alvo) {
    if(!no) return NULL; // não achou
    
    if(alvo == no->val) return no; // encontrou
    
    if(alvo < no->val) {
        return busca(no->esq, alvo); // procura na esquerda
    } else {
        return busca(no->dir, alvo); // procura na direita
    }
}

// Remove um nó específico
void tiraNo(struct No *no) {
    if(!no) return;

    // Caso 1: nó folha (sem filhos)
    if(!no->esq && !no->dir) {
        if(no->pai) {
            if(no->pai->esq == no) no->pai->esq = NULL;
            else no->pai->dir = NULL;
        }
        free(no);
    }
    else if(!no->esq || !no->dir) {
        struct No *filho = no->esq ? no->esq : no->dir;
        
        if(no->pai) { 
            if(no->pai->esq == no) no->pai->esq = filho;
            else no->pai->dir = filho;
        }
        filho->pai = no->pai; 
        free(no);
    }
    // Caso 3: tem dois filhos (chato)
    else {
        // Acha o menor da direita
        struct No* sucessor = no->dir;
        while(sucessor->esq) sucessor = sucessor->esq;
        
        no->val = sucessor->val; // copia o valor
        tiraNo(sucessor); // remove o sucessor
    }
}

// Remove um valor da árvore
void removeValor(struct Arvore* arv, int num) {
    struct No* alvo = busca(arv->raiz, num);
    if(!alvo) return; // não existe
    
    if(alvo == arv->raiz) {
        if(!alvo->esq && !alvo->dir) arv->raiz = NULL;
        else if(!alvo->esq || !alvo->dir) {
            arv->raiz = alvo->esq ? alvo->esq : alvo->dir;
            arv->raiz->pai = NULL;
        }
    }
    
    tiraNo(alvo);
}

// Imprime pré-ordem
void preOrdem(struct No* no) {
    if(!no) return;
    printf(" %d", no->val); // primeiro o valor
    preOrdem(no->esq); // depois esquerda
    preOrdem(no->dir); // depois direita
}

// Imprime em ordem
void emOrdem(struct No* no) {
    if(!no) return;
    emOrdem(no->esq); // esquerda primeiro
    printf(" %d", no->val); // valor no meio
    emOrdem(no->dir); // direita depois
}

// Imprime pós-ordem
void posOrdem(struct No* no) {
    if(!no) return;
    posOrdem(no->esq); // esquerda
    posOrdem(no->dir); // direita
    printf(" %d", no->val); // valor por último
}

// Main com uns prints bonitinhos
int main() {
    int C, N, x;
    struct Arvore arv;
    
    scanf("%d", &C); // número de casos
    
    for(int caso = 1; caso <= C; caso++) {
        scanf("%d", &N); // quantos números?
        
        iniciaArvore(&arv); // reseta a árvore
        
        for(int i = 0; i < N; i++) {
            scanf("%d", &x);
            add(&arv, x); // adiciona cada número
        }
        
        printf("Case %d:\n", caso);
        
        printf("Pre.:");
        preOrdem(arv.raiz);
        printf("\nIn..:");
        emOrdem(arv.raiz);
        printf("\nPost:");
        posOrdem(arv.raiz);
        printf("\n\n");
        
        destroiArvore(&arv); // limpa tudo
    }
    
    return 0;
}
