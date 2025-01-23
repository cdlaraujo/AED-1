#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[51];
    double price;
} Product;

int main() {
    int N; // Number of test cases
    scanf("%d", &N);

    while (N--) {
        int M; // Number of products in the market
        scanf("%d", &M);

        Product market[MAX_PRODUCTS];

        // Read the market price list
        for (int i = 0; i < M; i++) {
            scanf("%s %lf", market[i].name, &market[i].price);
        }

        int P; // Number of products Ms. Parcinova wants to buy
        scanf("%d", &P);

        double totalCost = 0.0;

        // Process Ms. Parcinova's shopping list
        for (int i = 0; i < P; i++) {
            char itemName[51];
            int quantity;
            scanf("%s %d", itemName, &quantity);

            // Find the price of the item in the market list
            for (int j = 0; j < M; j++) {
                if (strcmp(itemName, market[j].name) == 0) {
                    totalCost += market[j].price * quantity;
                    break;
                }
            }
        }

        // Print the total cost for the current test case
        printf("R$ %.2f\n", totalCost);
    }

    return 0;
}
