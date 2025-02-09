#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 26

int visited[MAX_VERTICES];
char adjacency[MAX_VERTICES][MAX_VERTICES];
char component[MAX_VERTICES];
int component_size;

void dfs(int v, int total_vertices) {
    visited[v] = 1;
    component[component_size++] = 'a' + v;
    
    for (int i = 0; i < total_vertices; i++) {
        if (adjacency[v][i] && !visited[i]) {
            dfs(i, total_vertices);
        }
    }
}

int main() {
    int N, V, E;
    scanf("%d", &N);
    
    for (int t = 1; t <= N; t++) {
        scanf("%d %d", &V, &E);
        
        memset(visited, 0, sizeof(visited));
        memset(adjacency, 0, sizeof(adjacency));
        
        for (int i = 0; i < E; i++) {
            char u, v;
            scanf(" %c %c", &u, &v);
            adjacency[u - 'a'][v - 'a'] = 1;
            adjacency[v - 'a'][u - 'a'] = 1;
        }
        
        printf("Case #%d:\n", t);
        int component_count = 0;
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                component_size = 0;
                dfs(i, V);
                
                for (int j = 0; j < component_size - 1; j++) {
                    for (int k = j + 1; k < component_size; k++) {
                        if (component[j] > component[k]) {
                            char temp = component[j];
                            component[j] = component[k];
                            component[k] = temp;
                        }
                    }
                }
                
                for (int j = 0; j < component_size; j++) {
                    printf("%c,", component[j]);
                }
                printf("\n");
                component_count++;
            }
        }
        
        printf("%d connected components\n\n", component_count);
    }
    
    return 0;
}
