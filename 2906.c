#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10005

void limpar(const char *s, char *out) {
    int i = 0, j = 0;
    while (s[i] != '\0' && s[i] != '+') {
        if (s[i] != '.')
            out[j++] = s[i];
        i++;
    }
    out[j] = '\0';
}

// Funcao da internet para comparar funções
int compare_str(const void *a, const void *b) {
    const char * const *sa = a;
    const char * const *sb = b;
    return strcmp(*sa, *sb);
}

int main(void) {
    int n;
    scanf("%d", &n);

    char **emails = malloc(n * sizeof(char *));
    if (emails == NULL) {
        return 1;
    }

    char input[MAX_LEN];
    for (int i = 0; i < n; i++) {
        scanf("%s", input);

        char *at = strchr(input, '@');
        if (at == NULL) {
            emails[i] = strdup(input);
            continue;
        }
        int local_len = at - input;
        char local[MAX_LEN];
        strncpy(local, input, local_len);
        local[local_len] = '\0';

        char *domain = at + 1;

        char processed_local[MAX_LEN];
        limpar(local, processed_local);

        char new_email[MAX_LEN];
        snprintf(new_email, MAX_LEN, "%s@%s", processed_local, domain);

        emails[i] = strdup(new_email);
    }

    qsort(emails, n, sizeof(char *), compare_str);

    int distinct = (n > 0) ? 1 : 0;
    for (int i = 1; i < n; i++) {
        if (strcmp(emails[i], emails[i - 1]) != 0)
            distinct++;
    }

    printf("%d\n", distinct);

    // Libera memoria alocada
    for (int i = 0; i < n; i++) {
        free(emails[i]);
    }
    free(emails);

    return 0;
}
