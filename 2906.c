#include <stdio.h>
#include <stdlib.h> // pro malloc e qsort
#include <string.h> // pro strcmp

// Remove pontos e tudo depois do +
void limpar(const char *entrada, char *saida) {
    int l = 0, r = 0;
    while (entrada[l] && entrada[l] != '+') { // vai até o + ou fim
        if (entrada[l] != '.') { // ignora pontos
            saida[r] = entrada[l];
            r++;
        }
        l++;
    }
    saida[r] = '\0'; // termina a string
}

// Função comparadora pro qsort (peguei de um fórum)
int cmp(const void *a, const void *b) {
    return strcmp(*(char**)a, *(char**)b);
}

int main() {
    int N;
    scanf("%d", &N); // número de emails

    char **lista = malloc(N * sizeof(char*)); // aloca a lista
    // if (!lista) return 1; // deveria verificar mas nem sempre lembro

    char temp[99999]; // buffer pro email
    for (int i = 0; i < N; i++) {
        scanf("%s", temp);
        
        char *arroba = strchr(temp, '@'); // acha o @
        if (!arroba) { // sem @? estranho mas copia mesmo assim
            lista[i] = strdup(temp);
            continue;
        }

        // Separa local e domínio
        *arroba = '\0'; // corta no @
        char dominio[99999];
        strcpy(dominio, arroba+1);
        
        char local_limpo[99999];
        limpar(temp, local_limpo); // processa a parte local

        // Remonta o email
        char final[99999];
        sprintf(final, "%s@%s", local_limpo, dominio);
        lista[i] = strdup(final); // duplica na lista
        
        // printf("DEBUG: %s => %s\n", temp, final); // útil pra testar
    }

    // Ordena pra contar os únicos
    qsort(lista, N, sizeof(char*), cmp);

    int unicos = N ? 1 : 0; // se tiver pelo menos 1, começa com 1
    for (int j = 1; j < N; j++) {
        if (strcmp(lista[j], lista[j-1])) // se for diferente
            unicos++;
    }
    printf("%d\n", unicos);

    // Libera a memória (importante!)
    for (int k = 0; k < N; k++) free(lista[k]);
    free(lista);

    return 0;
}
