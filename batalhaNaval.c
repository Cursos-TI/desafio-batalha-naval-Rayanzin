#include <stdio.h>

int main()
{
    int tabuleiro[10][10];
    int navioX[3] = {3, 4, 5};
    int navioY[3] = {7, 8, 9};
    int navioDiagonal1[3] = {7, 8, 9};
    int navioDiagonal2[3] = {9, 8, 7};

    // Inicializa o tabuleiro com zeros
    for (int y = 0; y <= 9; y++)
    {
        for (int x = 0; x <= 9; x++)
        {
            tabuleiro[y][x] = 0;
        }
    }

    // adiciona os navios X e Y com validação
    for (int i = 0; i <= 2; i++)
    {
        if (navioX[i] >= 0 && navioX[i] <= 9 && 3 >= 0 && 3 <= 9)
        {
            if (tabuleiro[3][navioX[i]] == 0)
            {
                tabuleiro[3][navioX[i]] = 3;
            }
            else
            {
                printf("Sobreposição detectada em navioX[%d]: posição [3][%d]\n", i, navioX[i]);
            }
        }
        else
        {
            printf("Coordenadas inválidas para navioX[%d]: [3][%d]\n", i, navioX[i]);
        }

        if (navioY[i] >= 0 && navioY[i] <= 9 && 4 >= 0 && 4 <= 9)
        {
            if (tabuleiro[navioY[i]][4] == 0)
            {
                tabuleiro[navioY[i]][4] = 3;
            }
            else
            {
                printf("Sobreposição detectada em navioY[%d]: posição [%d][4]\n", i, navioY[i]);
            }
        }
        else
        {
            printf("Coordenadas inválidas para navioY[%d]: [%d][4]\n", i, navioY[i]);
        }
    }

    // Mostra o tabuleiro após navios X e Y
    printf("\nTabuleiro com navios X e Y adicionados:\n");
    for (int y = 0; y <= 9; y++)
    {
        for (int x = 0; x <= 9; x++)
        {
            printf(" %d ", tabuleiro[y][x]);
        }
        printf("\n");
    }

    // Adiciona navioDiagonal1
    for (int i = 0; i <= 2; i++)
    {
        if (i >= 0 && i <= 9 && navioDiagonal1[i] >= 0 && navioDiagonal1[i] <= 9)
        {
            if (tabuleiro[i][navioDiagonal1[i]] == 0)
            {
                tabuleiro[i][navioDiagonal1[i]] = 3;
            }
            else
            {
                printf("Sobreposição detectada em navioDiagonal1[%d]: posição [%d][%d]\n", i, i, navioDiagonal1[i]);
            }
        }
        else
        {
            printf("Coordenadas inválidas para navioDiagonal1[%d]: [%d][%d]\n", i, i, navioDiagonal1[i]);
        }
    }

    // Adiciona navioDiagonal2
    for (int i = 0; i <= 2; i++)
    {
        if (navioDiagonal2[i] >= 0 && navioDiagonal2[i] <= 9 && i >= 0 && i <= 9)
        {
            if (tabuleiro[navioDiagonal2[i]][i] == 0)
            {
                tabuleiro[navioDiagonal2[i]][i] = 3;
            }
            else
            {
                printf("Sobreposição detectada em navioDiagonal2[%d]: posição [%d][%d]\n", i, navioDiagonal2[i], i);
            }
        }
        else
        {
            printf("Coordenadas inválidas para navioDiagonal2[%d]: [%d][%d]\n", i, navioDiagonal2[i], i);
        }
    }

    // Imprime o tabuleiro final com todos os navios
    printf("\nTabuleiro com todos os navios adicionados:\n");
    for (int y = 0; y <= 9; y++)
    {
        for (int x = 0; x <= 9; x++)
        {
            printf(" %d ", tabuleiro[y][x]);
        }
        printf("\n");
    }

    return 0;
}


// Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.

// Nível Mestre - Habilidades Especiais com Matrizes
// Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
// Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
// Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

// Exemplos de exibição das habilidades:
// Exemplo para habilidade em cone:
// 0 0 1 0 0
// 0 1 1 1 0
// 1 1 1 1 1

// Exemplo para habilidade em octaedro:
// 0 0 1 0 0
// 0 1 1 1 0
// 0 0 1 0 0

// Exemplo para habilidade em cruz:
// 0 0 1 0 0
// 1 1 1 1 1
// 0 0 1 0 0