#include <stdlib.h>
#include <stdio.h>

// Estrutura do nó da pilha
struct StackNode {
    int val;// valor atual
    struct StackNode* prox; // próximo nó (embaixo na pilha)
};

// Estrutura principal da pilha
struct Stack {
    int tamanho; // qtd de elementos
    struct StackNode* topo; // elemento do topo
};

// Coloca um valor na pilha
void empilha(struct Stack* p, int num) {
    struct StackNode* novo = malloc(sizeof(struct StackNode));
    novo->val = num;
    novo->prox = p->topo;  // novo nó aponta pro antigo topo
    p->topo = novo;        // atualiza o topo
    p->tamanho++;
}

// Tira o elemento do topo
void desempilha(struct Stack* p) {
    if(p->tamanho == 0) return;  // pilha vazia
    
    struct StackNode* velho = p->topo;
    p->topo = p->topo->prox;    // novo topo é o próximo
    free(velho);
    p->tamanho--;
}

// Pega o valor do topo (cuidado se estiver vazia!)
int topo(struct Stack* p) {
    return p->topo->val;  // TODO: devia verificar se existe
}

// Verifica se a pilha tá vazia
int vazia(struct Stack* p) {
    return p->tamanho == 0;
}

// Prepara uma nova pilha
void nova_pilha(struct Stack* p) {
    p->tamanho = 0;
    p->topo = NULL;
}

// Limpa toda a pilha
void limpa_pilha(struct Stack* p) {
    while(!vazia(p)) {
        desempilha(p);  // vai desempilhando até esvaziar
    }
}

int main() {
    int N, num;
    struct Stack entrada, estacao, saida;

    while(scanf("%d", &N) != EOF) {
        if(N == 0) break;  // fim da entrada
        
        while(1) {
            scanf("%d", &num);
            if(num == 0) {  // fim do caso de teste
                printf("\n");
                break;
            }
            
            // Reseta todas as pilhas
            nova_pilha(&entrada);
            nova_pilha(&estacao);
            nova_pilha(&saida);
            
            // Preenche as pilhas com os valores iniciais
            empilha(&entrada, num);
            empilha(&saida, 1);  // sequência desejada começa com 1
            
            for(int i = 2; i <= N; i++) {
                scanf("%d", &num);
                empilha(&entrada, num);
                empilha(&saida, i);  // sequência ideal 1,2,3...N
            }
            
            // Processamento principal
            while(1) {
                // Tenta encaixar direto da entrada pra saída
                if(!vazia(&entrada) && !vazia(&saida) && topo(&entrada) == topo(&saida)) {
                    desempilha(&entrada);
                    desempilha(&saida);
                }
                // Tenta pegar da estação pra saída
                else if(!vazia(&estacao) && !vazia(&saida) && topo(&estacao) == topo(&saida)) {
                    desempilha(&estacao);
                    desempilha(&saida);
                }
                // Move da entrada pra estação
                else if(!vazia(&entrada)) {
                    empilha(&estacao, topo(&entrada));
                    desempilha(&entrada);
                }
                else {
                    break;  // não tem mais o que fazer
                }
            }
            
            // Verifica se deu certo
            if(vazia(&entrada) && vazia(&estacao) && vazia(&saida)) {
                printf("Yes\n");
            }
            else {
                printf("No\n");
            }
            
            // Limpeza das pilhas para o próximo caso
            limpa_pilha(&entrada);
            limpa_pilha(&estacao);
            limpa_pilha(&saida);
        }
    }
    
    return 0;
}
