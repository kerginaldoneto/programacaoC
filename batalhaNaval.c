#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_NAVIO 3
#define AGUA 0

// Função para exibir o tabuleiro com numeração
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("    ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%2d ", j);
    }
    printf("\n   +");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("---");
    }
    printf("+\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d |", i);
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

// Função auxiliar para verificar se a posição está livre e dentro dos limites
int podeColocar(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    return tabuleiro[linha][coluna] == 0;
}

// Posiciona navio horizontal (↔)
int posicionarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
        return 0;

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (!podeColocar(tabuleiro, linha, coluna + i))
            return 0;
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = VALOR_NAVIO;
    }
    return 1;
}

// Posiciona navio vertical (↕)
int posicionarVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
        return 0;

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (!podeColocar(tabuleiro, linha + i, coluna))
            return 0;
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = VALOR_NAVIO;
    }
    return 1;
}

// Posiciona navio diagonal principal (↘)
int posicionarDiagonalPrincipal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
        return 0;

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (!podeColocar(tabuleiro, linha + i, coluna + i))
            return 0;
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = VALOR_NAVIO;
    }
    return 1;
}

// Posiciona navio diagonal secundária (↙)
int posicionarDiagonalSecundaria(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna - TAMANHO_NAVIO + 1 < 0)
        return 0;

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (!podeColocar(tabuleiro, linha + i, coluna - i))
            return 0;
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = VALOR_NAVIO;
    }
    return 1;
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Posicionamento dos 4 navios:
    if (!posicionarHorizontal(tabuleiro, 0, 0))
        printf("Erro ao posicionar navio horizontal.\n");

    if (!posicionarVertical(tabuleiro, 2, 5))
        printf("Erro ao posicionar navio vertical.\n");

    if (!posicionarDiagonalPrincipal(tabuleiro, 5, 1))
        printf("Erro ao posicionar navio diagonal ↘.\n");

    if (!posicionarDiagonalSecundaria(tabuleiro, 6, 8))
        printf("Erro ao posicionar navio diagonal ↙.\n");

    // Exibir o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
