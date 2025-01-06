#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

// Função para verificar o balanceamento dos parênteses
const char* is_balanced(const char* expression) {
    int balance = 0;
    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(') {
            balance++;
        } else if (expression[i] == ')') {
            balance--;
        }
        if (balance < 0) { // Parêntese de fechamento sem abertura correspondente
            return "incorrect";
        }
    }
    return balance == 0 ? "correct" : "incorrect";
}

int main() {
    char expression[MAX_LEN];
    
    // Leitura até o EOF
    while (fgets(expression, MAX_LEN, stdin)) {
        // Remove o caractere de nova linha, se existir
        expression[strcspn(expression, "\n")] = '\0';
        printf("%s\n", is_balanced(expression));
    }
    
    return 0;
}
