#include <stdio.h>
 
int main() {
    int dia, ano = 0, mes = 0;
    
    scanf("%d", &dia);
    
    while (dia > 364){
        ano += 1;
        dia = dia - 365;
    }
    
    while (dia > 29){
        mes += 1;
        dia = dia - 30;
    }
    
    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", ano, mes, dia);
 
    return 0;
}
