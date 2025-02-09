#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 1000

// op == operador
int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}

void infixToPostfix(const char *expr) {
    char stack[MAX];  
    int top = -1;    

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        if (isalnum(c)) {
            printf("%c", c);
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                printf("%c", stack[top]);
                top--;
            }
            stack[++top] = c;
        }
        else if (c == '(') {
            stack[++top] = c;
        }
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                printf("%c", stack[top]);
                top--;
            }
            if (top != -1)
                top--;
        }
    }
    while (top != -1) {
        printf("%c", stack[top]);
        top--;
    }
    printf("\n");
}

int main() {
    int t;
    char expr[400]; 

    scanf("%d", &t);
    while(t--) {
        scanf("%s", expr);
        infixToPostfix(expr);
    }
    return 0;
}
