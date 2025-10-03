#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.

#define LINHA 10
#define COLUNA 10

int main() {
    
    // Navio fixos de tamanho 3.
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};
    int navioDiagonal1[3] = {3, 3, 3};
    int navioDiagonal2[3] = {3, 3, 3};

    // Vetor com letras para o cabeçalho (colunas).
    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // Declaração do tabuleiro com matriz 10x10.
    int tabuleiro [LINHA][COLUNA];

    // Habilidade especial: cone de ataque (3x5).
    int habilidadeCone[3][5] = {
        {0, 0, 5, 0, 0},
        {0, 5, 5, 5, 0},
        {5, 5, 5, 5, 5}
    };

    // Habilidade especial: cruz de ataque (3x5).
    int habilidadeCruz[5][5] = {
        {0, 0, 5, 0, 0},
        {0, 0, 5, 0, 0},
        {5, 5, 5, 5, 5},
        {0, 0, 5, 0, 0},
        {0, 0, 5, 0, 0}
    };

    int habilidadeOctaedro[3][5] = {
        {0, 0, 5, 0, 0},
        {0, 5, 5, 5, 0},
        {0, 0, 5, 0, 0}
    };

    // Coordenadas iniciais dos navios.
    int linhaHorizontal = 9;  //Navio horizontal.
    int colunaHorizontal = 0;
    int linhaVertical = 7;    //Navio vertical.
    int colunaVertical = 9;

    // Coordenadas para navio diagonal 1 (esquerda para direita, cima para baixo).
    int linhaDiagonal1 = 3;
    int colunaDiagonal1 = 7;

    // Coordenadas para navio diagonal 2 (direita para esquerda, cima para baixo).
    int linhaDiagonal2 = 0;
    int colunaDiagonal2 = 9;

    // Coordenadas para habilidades especiais (cone de ataque).
    int linhaCone = 0;
    int colunaCone = 2;

    // Coordenadas para habilidade especial (cruz de ataque).
    int linhaCruz = 4;
    int colunaCruz = 6;

    // Coordenadas para habilidade especial (octaedro de ataque).
    int linhaOctaedro = 6;
    int colunaOctaedro = 1;

    // Loop aninhado para inicializar todas as posições do tabuleiro com 0 (água).
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Validação simples para garantir que os navios caibam no tabuleiro.
    // Posiciona navio horizontal (validando limites e sobreposição).
    if (colunaHorizontal + 3 <= COLUNA) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linhaHorizontal][colunaHorizontal + i] == 0) {
                tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
            }
        }
    }

    // Posiciona navio vertical.
    if (linhaVertical + 3 <= LINHA) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linhaVertical + i][colunaVertical] == 0) {
                tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
            }
            
        }
    }

    // Posiciona navio diagonal principal (Superior esquerdo para inferior direito).
    if (linhaDiagonal1 + 3 <= LINHA && colunaDiagonal1 + 3 <= COLUNA) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linhaDiagonal1 + i][colunaDiagonal1 + i] == 0) {
                tabuleiro[linhaDiagonal1 + i][colunaDiagonal1 + i] = navioDiagonal1[i];
            }
        }
    }

    // Posiciona navio diagonal secundário (Superior direito para inferior esquerdo).
    if (linhaDiagonal2 + 3 <= LINHA && colunaDiagonal2 - 2 >= 0) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linhaDiagonal2 + i][colunaDiagonal2 - i] == 0) {
                tabuleiro[linhaDiagonal2 + i][colunaDiagonal2 - i] = navioDiagonal2[i];
            }
        }
    }

    // Define o cone de ataque (habilidade especial).
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (habilidadeCone[i][j] != 0) {
                int lin = linhaCone + i;
                int col = colunaCone + j - 2; // Centraliza o cone na coluna inicial.
                if (lin < LINHA && col >= 0 && col < COLUNA) {
                    tabuleiro[lin][col] = habilidadeCone[i][j];
                }
            }
        }
    }

    // Define a cruz de ataque (habilidade especial).
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (habilidadeCruz[i][j] != 0) {
                int lin = linhaCruz + i;
                int col = colunaCruz + j - 2; // Centraliza a cruz na coluna inicial.
                if (lin < LINHA && col >= 0 && col < COLUNA) {
                    tabuleiro[lin][col] = habilidadeCruz[i][j];
                }
            }
        }
    }

    // Define o octaedro de ataque (habilidade especial).
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (habilidadeOctaedro[i][j] != 0) {
                int lin = linhaOctaedro + i;
                int col = colunaOctaedro + j - 2; // Centraliza a cruz na coluna inicial.
                if (lin < LINHA && col >= 0 && col < COLUNA) {
                    tabuleiro[lin][col] = habilidadeOctaedro[i][j];
                }
            }
        }
    }

    // Exibição do tabuleiro.
    printf("   "); // Espaço para alinhar cabeçalho.
    for (int j = 0; j < COLUNA; j++) {
        printf("%c ", letras[j]);
    }

    printf("\n");
    
    for (int i = 0; i < LINHA; i++) {
        printf("%2d ", i); // Numeração das linhas.
        for (int j = 0; j < COLUNA; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
    
}
