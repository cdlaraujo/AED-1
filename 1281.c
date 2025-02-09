#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[51];
    double price;
} Product;

int main() {
    int N; 
    scanf("%d", &N);

    while (N--) {
        int M; 
        scanf("%d", &M);

        Product market[MAX_PRODUCTS];

        for (int i = 0; i < M; i++) {
            scanf("%s %lf", market[i].name, &market[i].price);
        }

        int P; 
        scanf("%d", &P);

        double totalCost = 0.0;

        for (int i = 0; i < P; i++) {
            char itemName[51];
            int quantity;
            scanf("%s %d", itemName, &quantity);

            for (int j = 0; j < M; j++) {
                if (strcmp(itemName, market[j].name) == 0) {
                    totalCost += market[j].price * quantity;
                    break;
                }
            }
        }

        printf("R$ %.2f\n", totalCost);
    }

    return 0;
}
