#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

// Função para imprimir o tabuleiro com caracteres representando os valores
void imprimirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO])
{
    printf("\n=== TABULEIRO ===\n\n");
    for (int y = 0; y < TAM_TABULEIRO; y++)
    {
        for (int x = 0; x < TAM_TABULEIRO; x++)
        {
            if (tabuleiro[y][x] == 0)
                printf(" 0 ");  // água
            else if (tabuleiro[y][x] == 3)
                printf(" 3 ");  // navio
            else if (tabuleiro[y][x] == 5)
                printf(" 1 ");  // habilidade
        }
        printf("\n");
    }
}

// Função para aplicar uma matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origemY, int origemX)
{
    for (int i = 0; i < TAM_HABILIDADE; i++)
    {
        for (int j = 0; j < TAM_HABILIDADE; j++)
        {
            if (habilidade[i][j] == 1)
            {
                int y = origemY - TAM_HABILIDADE / 2 + i;
                int x = origemX - TAM_HABILIDADE / 2 + j;

                // Verifica se está dentro do tabuleiro
                if (y >= 0 && y < TAM_TABULEIRO && x >= 0 && x < TAM_TABULEIRO)
                {
                    if (tabuleiro[y][x] == 0)
                        tabuleiro[y][x] = 5;
                }
            }
        }
    }
}

// Função para construir matriz Cone (triângulo apontando para baixo)
void construirCone(int cone[TAM_HABILIDADE][TAM_HABILIDADE])
{
    for (int i = 0; i < TAM_HABILIDADE; i++)
    {
        for (int j = 0; j < TAM_HABILIDADE; j++)
        {
            if (i >= j - TAM_HABILIDADE / 2 && i >= TAM_HABILIDADE / 2 - j)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
}

// Função para construir matriz Cruz
void construirCruz(int cruz[TAM_HABILIDADE][TAM_HABILIDADE])
{
    for (int i = 0; i < TAM_HABILIDADE; i++)
    {
        for (int j = 0; j < TAM_HABILIDADE; j++)
        {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
}

// Função para construir matriz Octaedro (losango)
void construirOctaedro(int octaedro[TAM_HABILIDADE][TAM_HABILIDADE])
{
    for (int i = 0; i < TAM_HABILIDADE; i++)
    {
        for (int j = 0; j < TAM_HABILIDADE; j++)
        {
            if (abs(i - TAM_HABILIDADE / 2) + abs(j - TAM_HABILIDADE / 2) <= TAM_HABILIDADE / 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }
}

int main()
{
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa o tabuleiro com água (0)
    for (int y = 0; y < TAM_TABULEIRO; y++)
    {
        for (int x = 0; x < TAM_TABULEIRO; x++)
        {
            tabuleiro[y][x] = 0;
        }
    }

    // Adiciona alguns navios (valor 3)
    int navioX[3] = {3, 4, 5};
    for (int i = 0; i < 3; i++)
    {
        tabuleiro[3][navioX[i]] = 3;
        tabuleiro[navioX[i]][4] = 3;
    }

    // Construção das habilidades
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    // Aplica as habilidades ao tabuleiro
    aplicarHabilidade(tabuleiro, cone, 6, 2);      // Cone no ponto (6, 2)
    aplicarHabilidade(tabuleiro, cruz, 5, 5);      // Cruz no ponto (5, 5)
    aplicarHabilidade(tabuleiro, octaedro, 3, 7);  // Octaedro no ponto (3, 7)

    // Imprime o resultado final
    imprimirTabuleiro(tabuleiro);

    return 0;
}
