#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int main() {
    int N, K;
    char input[1000];
    char names[100][21];

    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d %d", &N, &K);

    for (int i = 0; i < N; i++) {
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%20s", names[i]);
    }

    qsort(names, N, sizeof(names[0]), compare);

    printf("%s\n", names[K - 1]);

    return 0;
}
