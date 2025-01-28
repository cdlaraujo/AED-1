#include <stdio.h>

int main() {
    double A, B, AVG;

    // Lê os valores de A e B
    scanf("%lf", &A); // Usamos %lf para ler um double
    scanf("%lf", &B);

    // Calcula a média ponderada
    AVG = (A * 3.5 + B * 7.5) / (3.5 + 7.5);

    // Imprime o resultado com 5 casas decimais
    printf("MEDIA = %.5lf\n", AVG);

    return 0;
}
