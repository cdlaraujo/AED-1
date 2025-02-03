#include <stdio.h>

int main() {
    double A, B, C;  // Changed to double for decimal inputs
    double MEDIA;
    
    scanf("%lf %lf %lf", &A, &B, &C);  // Use %lf for double
    
    MEDIA = (A * 2 + B * 3 + C * 5) / 10.0;
    
    printf("MEDIA = %.1f\n", MEDIA);  // Exactly 1 decimal place
    
    return 0;
}
