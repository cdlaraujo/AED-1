#include <stdio.h>

int main() {
    int A, B, C;
    float AVG, SUM;

    scanf("%d %d %d", &A, &B, &C);

    SUM = A * 2 + B * 3 + C * 5;
    AVG = SUM / (2 + 3 + 5);

    printf("MEDIA = %.5f\n", AVG);

    return 0;
}
