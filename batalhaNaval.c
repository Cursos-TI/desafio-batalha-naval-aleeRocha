#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.

int main() {
    
    // Tamanho fixo do tabuleiro
    int linhas = 10;
    int colunas = 10;

    // Navio fixos de tamanho 3.
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

    // Vetor com letras para o cabeçalho (colunas).
    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // Declaração do tabuleiro com matriz 10x10.
    int tabuleiro [10][10];

    // Coordenadas iniciais dos navios.
    int linhaHorizontal = 2;  //Navio horizontal.
    int colunaHorizontal = 1;
    int linhaVertical = 5;    //Navio vertical.
    int colunaVertical = 7;

    // Loop aninhado para inicializar todas as posições do tabuleiro com 0 (água).
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            tabuleiro[i][j] = 0;
        }
        
    }

    // Validação simples para garantir que os navios caibam no tabuleiro.
    if (colunaHorizontal + 3 <= colunas) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
        }
    }

    if (linhaVertical + 3 <= linhas) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linhaVertical + i][colunaVertical] == 0) {
                tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
            }
            
        }
        
    }

    // Exibição do tabuleiro.
    printf("   "); // Espaço para alinhar cabeçalho.
    for (int j = 0; j < colunas; j++) {
        printf("%c ", letras[j]);
    }

    printf("\n");
    
    for (int i = 0; i < linhas; i++) {
        printf("%2d ", i); // Numeração das linhas.
        for (int j = 0; j < colunas; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
    
}
