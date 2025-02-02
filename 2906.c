#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10005

// The limpar function:
// Copies characters from s to out while skipping '.' and stops when encountering '+'
void limpar(const char *s, char *out) {
    int i = 0, j = 0;
    while (s[i] != '\0' && s[i] != '+') {
        if (s[i] != '.')
            out[j++] = s[i];
        i++;
    }
    out[j] = '\0';
}

// Comparison function for qsort
int compare_str(const void *a, const void *b) {
    const char * const *sa = a;
    const char * const *sb = b;
    return strcmp(*sa, *sb);
}

int main(void) {
    int n;
    scanf("%d", &n);

    // Allocate an array of pointers to hold processed emails.
    char **emails = malloc(n * sizeof(char *));
    if (emails == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    char input[MAX_LEN];
    for (int i = 0; i < n; i++) {
        scanf("%s", input);

        // Find the '@' character in the input
        char *at = strchr(input, '@');
        if (at == NULL) {
            // If no '@' is found, use the email as is.
            emails[i] = strdup(input);
            continue;
        }

        // Split input into local and domain parts.
        // Local part is from input[0] to (at - 1).
        int local_len = at - input;
        char local[MAX_LEN];
        strncpy(local, input, local_len);
        local[local_len] = '\0';
        // Domain part is everything after '@'
        char *domain = at + 1;

        // Process the local part using limpar.
        char processed_local[MAX_LEN];
        limpar(local, processed_local);

        // Build the new email: processed_local + "@" + domain.
        char new_email[MAX_LEN];
        snprintf(new_email, MAX_LEN, "%s@%s", processed_local, domain);

        // Save a copy of the new email.
        emails[i] = strdup(new_email);
    }

    // Sort the emails array.
    qsort(emails, n, sizeof(char *), compare_str);

    // Count distinct emails:
    // Since the emails are sorted, we simply count how many times
    // an email differs from its predecessor.
    int distinct = (n > 0) ? 1 : 0;
    for (int i = 1; i < n; i++) {
        if (strcmp(emails[i], emails[i - 1]) != 0)
            distinct++;
    }

    printf("%d\n", distinct);

    // Free allocated memory.
    for (int i = 0; i < n; i++) {
        free(emails[i]);
    }
    free(emails);

    return 0;
}
