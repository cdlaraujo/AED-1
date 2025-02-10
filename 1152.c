#include <stdio.h>
#include <stdlib.h> // pra qsort e malloc

typedef struct {
    int u, v;       // vértices
    int peso;        // peso da aresta
} Aresta;

// Compara duas arestas pro qsort (ordem crescente)
int cmp(const void *a, const void *b) {
    Aresta *x = (Aresta*)a;
    Aresta *y = (Aresta*)b;
    return x->peso - y->peso; // mais leve primeiro
}

// Acha o pai do conjunto (com path compression)
int encontraPai(int conj[], int x) {
    if (conj[x] != x) {
        conj[x] = encontraPai(conj, conj[x]); // comprime caminho
    }
    return conj[x];
}

// Une dois conjuntos (union by rank)
void uneConj(int conj[], int rank[], int x, int y) {
    int px = encontraPai(conj, x);
    int py = encontraPai(conj, y);
    
    if (px == py) return; // já tão juntos
    
    // Faz a menor árvore ficar debaixo da maior
    if (rank[px] > rank[py]) {
        conj[py] = px;
    } else {
        conj[px] = py;
        if (rank[px] == rank[py]) rank[py]++;
    }
}

int main() {
    int m, n; // m = vértices, n = arestas
    
    // Lê enquanto m e n não forem ambos zero
    while(scanf("%d %d", &m, &n), m || n) {
        Aresta lista[n];
        long long total = 0;
        
        // Lê todas arestas
        for(int i = 0; i < n; i++) {
            scanf("%d %d %d", &lista[i].u, &lista[i].v, &lista[i].peso);
            total += lista[i].peso; // soma total
        }
        
        // Ordena as arestas por peso
        qsort(lista, n, sizeof(Aresta), cmp);
        
        int conj[m];  // array de pais
        int rank[m]; // altura da árvore
        for(int i = 0; i < m; i++) {
            conj[i] = i; // cada um é seu próprio pai
            rank[i] = 0; // altura inicial zero
        }
        
        long long mst = 0;
        int pegas = 0; // arestas na MST
        
        // Algoritmo de Kruskal
        for(int i = 0; i < n && pegas < m-1; i++) {
            int u = lista[i].u;
            int v = lista[i].v;
            
            if(encontraPai(conj, u) != encontraPai(conj, v)) {
                uneConj(conj, rank, u, v);
                mst += lista[i].peso;
                pegas++;
                // printf("Usei aresta %d-%d\n", u, v); // debug
            }
        }
        
        // Economia = Total - MST
        printf("%lld\n", total - mst);
    }

    return 0;
}
