#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para exibir o tabuleiro com numeração
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("    ");
    // Cabeçalho: numeração das colunas
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    printf("   +");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("---");
    }
    printf("+\n");

    // Linhas com numeração lateral
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d |", i); // Numeração da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("|\n");
    }

    printf("   +");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("---");
    }
    printf("+\n");
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Posição inicial dos navios
    int linha1 = 2, coluna1 = 4; // Horizontal
    int linha2 = 5, coluna2 = 7; // Vertical

    // Validação e posicionamento do navio horizontal
    if (coluna1 + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio 1 ultrapassa os limites do tabuleiro.\n");
        return 1;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha1][coluna1 + i] = 3;
    }

    // Validação e posicionamento do navio vertical
    if (linha2 + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio 2 ultrapassa os limites do tabuleiro.\n");
        return 1;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha2 + i][coluna2] != 0) {
            printf("Erro: Sobreposição entre os navios detectada.\n");
            return 1;
        }
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha2 + i][coluna2] = 3;
    }

    // Exibir o tabuleiro com numeração
    exibirTabuleiro(tabuleiro);

    return 0;
}
