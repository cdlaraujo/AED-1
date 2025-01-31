#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); // lê o número de casos de teste

    for (int i = 0; i < n; i++) {
        char a[4]; // Array para armazenar a string (3 caracteres + '\0')
        scanf("%s", a);

        int x = a[0] - '0'; // Primeiro número
        int y = a[2] - '0'; // Segundo número
        char c = a[1];      // Caracter operador

        if (x == y) {
            printf("%d\n", x * x);
        } else if (c >= 'a' && c <= 'z') {
            printf("%d\n", x + y);
        } else {
            printf("%d\n", y - x);
        }
    }

    return 0;
}
