#include <stdio.h>

int main() {
    // printf("%d", letras[y]);
    char letras[] = {'A','B','C','D','E','F','G','H','I','J',};
    int tabuleiro[10][10];
    int navio1[3] = {3,4,5};
    int navio2[3] = {7,8,9};
    // Imprime as linhas do tabuleiro + navios
    for (int y = 0; y <= 9; y++) {
        printf(" ");
        printf(" %d ", y + 1 );
        for (int x = 0; x <= 9; x++) {
            printf("");
            if(navio1[0] ==  x && y == 3 || navio1[1] == x && y == 3|| navio1[2] == x && y == 3 || navio2[0] ==  y && x == 3 || navio2[1] == y && x == 3|| navio2[2] == y && x == 3){
                printf(" %d ", tabuleiro[y][x] = 3);
            }else{
                printf(" %d ", tabuleiro[y][x] = 0);
            }
        }
        printf("\n");
    }

    return 0;
}


    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

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