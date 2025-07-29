#include <stdio.h>

int main()
{
    int tabuleiro[10][10];
    int navioX[3] = {3, 4, 5};
    int navioY[3] = {7, 8, 9};
    int navioDiagonal1[3] = {7, 8, 9};
    int navioDiagonal2[3] = {9, 8, 7};

    // Imprime o tabuleiro
    printf("Tabuleiro:\n");
    for (int y = 0; y <= 9; y++)
    {
        for (int x = 0; x <= 9; x++)
        {
            tabuleiro[y][x] = 0;
            printf(" %d ", tabuleiro[y][x]);
        }
        printf("\n");
    }
    printf("\n");

    // adiciona os navios X e Y
    for (int i = 0; i <= 2; i++)
    {
        if (navioX[i] >= 0 && navioX[i] <=9)
        {
            tabuleiro[3][navioX[i]] = 3;
        }else{
            printf("as cordenadas do navioX são invalidas \n");
        }

        if(navioY[i] >= 0 && navioY[i] <=9){
            tabuleiro[navioY[i]][4] = 3;
        }else{
            printf("as cordenadas do navioY são invalidas \n");
        }
        
    }

    // Reimprime o tabuleiro com os navios X e Y
    printf("Tabuleiro com navios X e Y adicionados;\n");
    for (int y = 0; y <= 9; y++)
    {
        for (int x = 0; x <= 9; x++)
        {
            printf(" %d ", tabuleiro[y][x]);
        }
        printf("\n");
    }
    printf("\n");

    // Adiciona navios Diagonal 1 e 2
    for (int i = 0; i <= 2; i++)
    {
        if (navioDiagonal1[i] >= 0 && navioDiagonal1[i] <=9)
        {
            tabuleiro[i][navioDiagonal1[i]] = 3;
        }else{
            printf("as cordenadas do navioDiagonal1 são invalidas \n");
        }

        if(navioDiagonal2[i] >= 0 && navioDiagonal2[i] <=9){
            tabuleiro[navioDiagonal2[i]][i] = 3;
        }else{
            printf("as cordenadas do navioDiagonal2 são invalidas \n");
        }
        
        
    }

    // Reimprime o tabuleiro com os navios Diagonal1 e Diagonal2
    printf("Tabuleiro com navios Diagonal1 e Diagonal2 adicionados;\n");
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