#include <stdio.h>

int main() {
    // Variáveis para controlar o número de casas a serem movidas
    int casas_torre = 5;      // Torre move 5 casas para a direita
    int casas_bispo = 5;      // Bispo move 5 casas na diagonal (cima-direita)
    int casas_rainha = 8;     // Rainha move 8 casas para a esquerda
    
    // Variáveis de controle para os loops
    int i, contador_while, contador_do_while;
    
    printf("=== SIMULADOR DE MOVIMENTO DE PEÇAS DE XADREZ ===\n\n");
    
    // TORRE - Movimento horizontal para a direita usando estrutura FOR
    printf("TORRE - Movendo 5 casas para a direita:\n");
    for (i = 1; i <= casas_torre; i++) {
        printf("Direita\n");
    }
    printf("Torre completou o movimento!\n\n");
    
    // BISPO - Movimento diagonal (cima-direita) usando estrutura WHILE
    printf("BISPO - Movendo 5 casas na diagonal (cima-direita):\n");
    contador_while = 1;
    while (contador_while <= casas_bispo) {
        printf("Cima Direita\n");
        contador_while++;
    }
    printf("Bispo completou o movimento!\n\n");
    
    // RAINHA - Movimento horizontal para a esquerda usando estrutura DO-WHILE
    printf("RAINHA - Movendo 8 casas para a esquerda:\n");
    contador_do_while = 1;
    do {
        printf("Esquerda\n");
        contador_do_while++;
    } while (contador_do_while <= casas_rainha);
    printf("Rainha completou o movimento!\n\n");
    
    printf("=== SIMULAÇÃO CONCLUÍDA ===\n");
    
    return 0;
}