#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_NAVIO 3
#define VALOR_HABILIDADE 5
#define TAMANHO_HABILIDADE 5  // Tamanho das matrizes de habilidade (5x5)

// Função para exibir o tabuleiro com numeração e símbolos visuais
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
            // Exibe símbolos diferentes para cada tipo de célula
            if (tabuleiro[i][j] == VALOR_NAVIO) {
                printf(" N ");  // N para navio
            } else if (tabuleiro[i][j] == VALOR_HABILIDADE) {
                printf(" * ");  // * para área de habilidade
            } else {
                printf(" . ");  // . para água
            }
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

// Cria matriz de habilidade em forma de cone (apontando para baixo)
void criarHabilidadeCone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Cone começa pequeno no topo e expande para baixo
            if (j >= i && j < TAMANHO_HABILIDADE - i) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Cria matriz de habilidade em forma de cruz
void criarHabilidadeCruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Cruz tem uma linha horizontal e vertical central
            if (i == centro || j == centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Cria matriz de habilidade em forma de octaedro (losango)
void criarHabilidadeOctaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Octaedro forma um losango (diagonais dentro de um limite)
            int distancia = abs(i - centro) + abs(j - centro);
            if (distancia <= centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Aplica uma habilidade ao tabuleiro na posição especificada
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                     int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], 
                     int linha_centro, int coluna_centro) {
    int offset = TAMANHO_HABILIDADE / 2;
    
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linha_tab = linha_centro - offset + i;
            int coluna_tab = coluna_centro - offset + j;
            
            // Verifica se está dentro dos limites do tabuleiro
            if (linha_tab >= 0 && linha_tab < TAMANHO_TABULEIRO && 
                coluna_tab >= 0 && coluna_tab < TAMANHO_TABULEIRO) {
                // Se a posição na matriz de habilidade for 1, marca no tabuleiro
                if (habilidade[i][j] == 1) {
                    tabuleiro[linha_tab][coluna_tab] = VALOR_HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};
    
    // Matrizes para as habilidades
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    
    // Criar as matrizes de habilidade
    criarHabilidadeCone(cone);
    criarHabilidadeCruz(cruz);
    criarHabilidadeOctaedro(octaedro);

    // Posicionamento dos 4 navios:
    if (!posicionarHorizontal(tabuleiro, 0, 0))
        printf("Erro ao posicionar navio horizontal.\n");

    if (!posicionarVertical(tabuleiro, 2, 5))
        printf("Erro ao posicionar navio vertical.\n");

    if (!posicionarDiagonalPrincipal(tabuleiro, 5, 1))
        printf("Erro ao posicionar navio diagonal ↘.\n");

    if (!posicionarDiagonalSecundaria(tabuleiro, 6, 8))
        printf("Erro ao posicionar navio diagonal ↙.\n");

    // Aplicar habilidades ao tabuleiro
    aplicarHabilidade(tabuleiro, cone, 3, 3);      // Cone no centro superior
    aplicarHabilidade(tabuleiro, cruz, 7, 2);      // Cruz na parte inferior esquerda
    aplicarHabilidade(tabuleiro, octaedro, 5, 7);  // Octaedro na parte direita

    // Exibir o tabuleiro final
    printf("Tabuleiro com navios e áreas de habilidade:\n");
    printf("Legenda: . = Água, N = Navio, * = Área de habilidade\n\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}