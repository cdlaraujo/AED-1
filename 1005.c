#include <stdio.h>

int main() {
    double A, B, AVG;

    scanf("%lf", &A); 
    scanf("%lf", &B);

    AVG = (A * 3.5 + B * 7.5) / (3.5 + 7.5);

    printf("MEDIA = %.5lf\n", AVG);

    return 0;
}
