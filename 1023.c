#include <stdio.h>

int main(void) {
    int N;  // number of properties in a test case
    int caseNumber = 1;
    
    // Process test cases until we read 0.
    while (scanf("%d", &N) == 1 && N != 0) {
        // There are 201 possible floor values: 0 through 200.
        int groups[201] = {0};  // groups[i] will hold the total residents 
                                // for properties whose (Y/X) equals i.
        int x;      // number of residents in a property
        int y;      // consumption in that property
        long long totalResidents = 0;
        long long totalConsumption = 0;
        
        // Read all N properties.
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &x, &y);
            totalResidents += x;
            totalConsumption += y;
            // Calculate consumption per resident (integer division rounds down)
            int key = y / x;  
            groups[key] += x;
        }
        
        // Print a blank line between test cases (but not before the first).
        if (caseNumber > 1)
            printf("\n");
        
        // Print header for the city.
        printf("Cidade# %d:\n", caseNumber++);
        
        // Print the groups in ascending order.
        // We print each group as "<total residents>-<consumption floor>"
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
        
        // Compute the average consumption per resident.
        // Note: the average must be truncated to two decimal places.
        double avg = totalConsumption / (double) totalResidents;
        int truncAvg = (int)(avg * 100);  // truncate extra decimals
        avg = truncAvg / 100.0;
        
        // Print the average consumption line.
        printf("Consumo medio: %.2f m3.\n", avg);
    }
    
    return 0;
}
