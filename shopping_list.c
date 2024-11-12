#include <stdio.h>
#include <string.h>
 
int main() {
    
    /* Define a matrix of 100 lists, ordeined in 26
    first letters, 1000 items with 20 characters */
    char M[100][26][1000][20];

    /* Define a buffer of 100 lists, 1000 items * 20 characters.
    Define two checkers to compare possible duplicated words */
    char buffer[2000000] = {'\0'}, check1[20] = {'\0'}, check2[20] = {'\0'};
    
    fgets(buffer, sizeof(buffer), stdin);

    // the first character of buffer is the number of lines.
    int items = 0, j = 0, num_lines = buffer[0], cur_list = 0, aux, check;
    
    // Why do I need max if I have len already?
    int len = strlen(buffer);
    
    for(int i = 0; i < len; ++i){
        if(buffer[i] == '\n'){
            j = 0;
            ++cur_list;
        }
        else if(buffer[i] == ' '){
            ++items;
            j = 0;
        }
        else{
            if(buffer[i - 1] == ' ' || buffer[i - 1] == '\n'){
                aux = buffer[i] - 65;
                M[cur_list][aux][items][j] = buffer[i];
            }
            M[cur_list][aux][items][j] = buffer[i];
        }
    } 

    for(int x = 0; x < len; ++x){
        for(int y = 0; y < 26; ++y){
            check = 0;
            for(int z = check + 1; z < 100; ++z){
                // Get word that checks for duplicates
                for(int a = 0; a < 20; ++a){
                    check1[a] = M[x][y][check][a];
                }

                // Get all subsequent words.
                for(int a = 0; a < 20; ++a){
                    check2[a] = M[x][y][z][a];
                } 

                if(strcmp(check1, check2) == 0){
                    for(int a = 0; a < 20; ++a){
                        M[x][y][z][a] = '\0';
                    } 
                }
            }
        }
    }

    for(int x = 0; x < len; ++x){
        for(int y = 0; y < 26; ++y){
            printf('\n');
            for(int z = 0; z < 100; ++z){
                printf(' ');
                for(int a = 0; a < 20; ++a){
                    if(M[x][y][z][a] != '\0')
                        printf("%c", M[x][y][z][a]);
                }
            }
        }
    }
 
    return 0;
}