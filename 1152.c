#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, weight;
} Edge;

int compareEdges(const void *a, const void *b) {
    Edge *edge1 = (Edge *)a;
    Edge *edge2 = (Edge *)b;
    return edge1->weight - edge2->weight;
}

int find(int parent[], int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n), m || n) {
        Edge edges[n];
        long long totalCost = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
            totalCost += edges[i].weight;
        }

        qsort(edges, n, sizeof(Edge), compareEdges);

        // algoritmo de Kruskal
        int parent[m], rank[m];
        for (int i = 0; i < m; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        long long mstCost = 0;
        int edgesUsed = 0;

        for (int i = 0; i < n && edgesUsed < m - 1; i++) {
            int u = edges[i].u;
            int v = edges[i].v;

            if (find(parent, u) != find(parent, v)) {
                unionSets(parent, rank, u, v);
                mstCost += edges[i].weight;
                edgesUsed++;
            }
        }


        printf("%lld\n", totalCost - mstCost);
    }

    return 0;
}
