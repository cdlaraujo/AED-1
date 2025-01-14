#include <stdio.h>

int main() {
    int width, height;
    int i, j;
    char c;

    // Get width and height
    scanf("%d", &width);
    scanf("%d", &height);
    
    // Criate map
    int map[width][height];

    // Process the grid character by character
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            scanf(" %c", &c);
            if (c == '>') map[i][j] = 1;
            else if (c == '<') map[i][j] = 2;
            else if (c == '^') map[i][j] = 3;
            else if (c == 'v') map[i][j] = 4;
            else if (c == '.') map[i][j] = 5;
            else if (c == '*') map[i][j] = 0;
        }
    }
    
    // Algoritmn to check if map is valid (to build)
    i = 0, j = 0;
    
    int command = map[i][j];
    
    while (1){
        while (map[i][j] == 5){
            if (command == 1) j++;
            else if(command == 2) j--;
            else if (command == 3) i++;
            else if (command == 4) i--;
            
            if ((i < 0 || j < 0) || (j > width || i > height)){
                printf("!");
                return 2;
            }
        }
        if (map[i][j] == 1) command == 1;
        else if(map[i][j] == 2) command == 2;
        else if (map[i][j] == 3) command == 3;
        else if (map[i][j] == 4) command == 4;
        
        if(map[i][j] == 0){
            printf("*");
            return 1;
        }
    }
    
    return 0;

}
