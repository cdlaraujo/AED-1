#include <stdio.h>

int main() {
    int n1, n2, n3, n4;

    // Leitura dos números de entrada separados por espaço
    scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

    // Calculando o número máximo de dispositivos que podem ser conectados
    int result = n1 + n2 + n3 + n4 - 3;

    // Imprimindo o resultado
    printf("%d\n", result);

    return 0;
}
