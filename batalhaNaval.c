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
    int navioDiagonal1[3] = {3, 3, 3};
    int navioDiagonal2[3] = {3, 3, 3};

    // Vetor com letras para o cabeçalho (colunas).
    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // Declaração do tabuleiro com matriz 10x10.
    int tabuleiro [10][10];

    // Coordenadas iniciais dos navios.
    int linhaHorizontal = 4;  //Navio horizontal.
    int colunaHorizontal = 1;
    int linhaVertical = 5;    //Navio vertical.
    int colunaVertical = 7;

    // Coordenadas para navio diagonal 1 (esquerda para direita, cima para baixo).
    int linhaDiagonal1 = 0;
    int colunaDiagonal1 = 0;

    // Coordenadas para navio diagonal 2 (direita para esquerda, cima para baixo).
    int linhaDiagonal2 = 0;
    int colunaDiagonal2 = 9;

    // Loop aninhado para inicializar todas as posições do tabuleiro com 0 (água).
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Validação simples para garantir que os navios caibam no tabuleiro.
    // Posiciona navio horizontal (validando limites e sobreposição).
    if (colunaHorizontal + 3 <= colunas) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linhaHorizontal][colunaHorizontal + i] == 0) {
                tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
            }
        }
    }

    // Posiciona navio vertical.
    if (linhaVertical + 3 <= linhas) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linhaVertical + i][colunaVertical] == 0) {
                tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
            }
            
        }
    }

    // Posiciona navio diagonal principal (Superior esquerdo para inferior direito).
    if (linhaDiagonal1 + 3 <= linhas && colunaDiagonal1 + 3 <= colunas) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linhaDiagonal1 + i][colunaDiagonal1 + i] == 0) {
                tabuleiro[linhaDiagonal1 + i][colunaDiagonal1 + i] = navioDiagonal1[i];
            }
        }
    }

    // Posiciona navio diagonal secundário (Superior direito para inferior esquerdo).
    if (linhaDiagonal2 + 3 <= linhas && colunaDiagonal2 - 2 >= 0) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linhaDiagonal2 + i][colunaDiagonal2 - i] == 0) {
                tabuleiro[linhaDiagonal2 + i][colunaDiagonal2 - i] = navioDiagonal2[i];
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
