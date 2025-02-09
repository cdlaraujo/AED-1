#include <stdio.h>

int main(void) {
    int N; 
    int caseNumber = 1;
    
    // processar os casos até chegar em 0
    while (scanf("%d", &N) == 1 && N != 0) {
        int groups[201] = {0}; 
                               
        int x;    
        int y;    
        long long totalResidents = 0;
        long long totalConsumption = 0;
        
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &x, &y);
            totalResidents += x;
            totalConsumption += y;
            int key = y / x;  
            groups[key] += x;
        }
        
        if (caseNumber > 1)
            printf("\n");
        
        printf("Cidade# %d:\n", caseNumber++);
        
        int firstOutput = 1;
        for (int i = 0; i <= 200; i++) {
            if (groups[i] > 0) {
                if (!firstOutput)
                    printf(" ");
                printf("%d-%d", groups[i], i);
                firstOutput = 0;
            }
        }
        printf("\n");
        
        double avg = totalConsumption / (double) totalResidents;
        int truncAvg = (int)(avg * 100);  
        avg = truncAvg / 100.0;
        
        printf("Consumo medio: %.2f m3.\n", avg);
    }
    
    return 0;
}
