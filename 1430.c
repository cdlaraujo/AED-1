#include <string.h>
#include <stdio.h>

double duracaoNota(char nota)
{
    if (nota == 'W')
        return 1.0;
    else if (nota == 'H')
        return 0.5;
    else if (nota == 'Q')
        return 0.25;
    else if (nota == 'E')
        return 0.125;
    else if (nota == 'S')
        return 0.0625;
    else if (nota == 'T')
        return 0.03125;
    else if (nota == 'X')
        return 0.015625;
    
    return 0.0; // Caso a nota não seja reconhecida
}

int main()
{
    int resposta;
    double duracao;
    char composicao[1000];

    while (scanf("%[^\n]\n", composicao) != EOF)
    {
        if (strcmp(composicao, "*") == 0)
            break;

        resposta = 0;
        duracao = 0.0;
        for (int i = 0; i < strlen(composicao); ++i)
        {
            if (composicao[i] == '/')
            {
                if (duracao == 1.0)
                    ++resposta;
                duracao = 0.0;
            }
            else
            {
                duracao += duracaoNota(composicao[i]);
            }
        }

        printf("%d\n", resposta);
    }

    return 0;
}
