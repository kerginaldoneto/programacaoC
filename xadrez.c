#include <stdio.h>

// FUNÇÕES RECURSIVAS PARA AS PEÇAS

/**
 * Função recursiva para movimento da Torre
 * Parâmetros: casas_restantes - número de casas ainda a serem movidas
 * Movimento: horizontal para a direita
 */
void mover_torre_recursivo(int casas_restantes) {
    // Caso base: se não há mais casas para mover, encerra a recursão
    if (casas_restantes <= 0) {
        return;
    }
    
    // Imprime o movimento atual
    printf("Direita\n");
    
    // Chamada recursiva com uma casa a menos
    mover_torre_recursivo(casas_restantes - 1);
}

/**
 * Função recursiva para movimento da Rainha
 * Parâmetros: casas_restantes - número de casas ainda a serem movidas
 * Movimento: horizontal para a esquerda
 */
void mover_rainha_recursivo(int casas_restantes) {
    // Caso base: se não há mais casas para mover, encerra a recursão
    if (casas_restantes <= 0) {
        return;
    }
    
    // Imprime o movimento atual
    printf("Esquerda\n");
    
    // Chamada recursiva com uma casa a menos
    mover_rainha_recursivo(casas_restantes - 1);
}

/**
 * Função recursiva para movimento diagonal do Bispo (usado internamente pelos loops)
 * Parâmetros: casas_restantes - número de casas ainda a serem movidas na diagonal
 */
void mover_bispo_diagonal_recursivo(int casas_restantes) {
    // Caso base: se não há mais casas para mover, encerra a recursão
    if (casas_restantes <= 0) {
        return;
    }
    
    // Imprime o movimento diagonal (combinação de vertical e horizontal)
    printf("Cima Direita\n");
    
    // Chamada recursiva com uma casa a menos
    mover_bispo_diagonal_recursivo(casas_restantes - 1);
}

int main() {
    // Constantes para definir o número de casas para cada peça
    const int CASAS_TORRE = 5;        // Torre move 5 casas para a direita
    const int CASAS_RAINHA = 8;       // Rainha move 8 casas para a esquerda
    const int CASAS_BISPO_TOTAL = 5;  // Bispo move 5 casas na diagonal
    const int CASAS_CAVALO_CIMA = 2;  // Cavalo move 2 casas para cima
    const int CASAS_CAVALO_DIREITA = 1; // Cavalo move 1 casa para a direita
    
    // Variáveis de controle para loops complexos
    int i, j, movimento_completo;
    int fase_movimento, casas_movidas;
    
    printf("=== SIMULADOR AVANÇADO DE MOVIMENTO DE PEÇAS DE XADREZ ===\n\n");
    
    // TORRE - Movimento recursivo para a direita
    printf("TORRE - Movendo 5 casas para a direita (RECURSÃO):\n");
    mover_torre_recursivo(CASAS_TORRE);
    printf("Torre completou o movimento recursivo!\n\n");
    
    // BISPO - Movimento com loops aninhados + recursividade
    printf("BISPO - Movendo 5 casas na diagonal (LOOPS ANINHADOS + RECURSÃO):\n");
    
    // Loop externo: controla o movimento vertical (conceptual)
    for (i = 1; i <= 1; i++) {
        printf("Iniciando movimento diagonal:\n");
        
        // Loop interno: controla o movimento horizontal (conceptual)
        for (j = 1; j <= 1; j++) {
            printf("Executando movimento diagonal completo:\n");
            
            // Chamada da função recursiva para executar o movimento diagonal
            mover_bispo_diagonal_recursivo(CASAS_BISPO_TOTAL);
        }
    }
    printf("Bispo completou o movimento com loops aninhados e recursão!\n\n");
    
    // RAINHA - Movimento recursivo para a esquerda
    printf("RAINHA - Movendo 8 casas para a esquerda (RECURSÃO):\n");
    mover_rainha_recursivo(CASAS_RAINHA);
    printf("Rainha completou o movimento recursivo!\n\n");
    
    // CAVALO - Movimento em "L" com loops complexos (cima e direita)
    printf("CAVALO - Movendo em formato 'L' (2 casas para cima, 1 casa para a direita) - LOOPS COMPLEXOS:\n");
    
    // Variáveis para controle complexo do movimento do cavalo
    movimento_completo = 0;  // Flag para controlar se o movimento foi concluído
    fase_movimento = 1;      // Controla a fase atual do movimento (1=vertical, 2=horizontal)
    
    // Loop externo: controla as duas fases do movimento em L
    for (i = 1; i <= 2 && !movimento_completo; i++) {
        
        // Determina a fase atual baseada no valor de i
        if (fase_movimento == 1) {
            printf("Fase 1 - Movimento vertical (para cima):\n");
            casas_movidas = 0;
            
            // Loop interno complexo para movimento vertical
            for (j = 1; j <= CASAS_CAVALO_CIMA; j++) {
                
                // Condição complexa: verifica se deve continuar o movimento
                if (casas_movidas >= CASAS_CAVALO_CIMA) {
                    break; // Sai do loop se já moveu todas as casas necessárias
                }
                
                printf("Cima\n");
                casas_movidas++;
                
                // Continue pode ser usado aqui para pular iterações específicas
                // (mantido como exemplo da estrutura, mas não necessário neste caso)
                if (casas_movidas < CASAS_CAVALO_CIMA) {
                    continue;
                }
            }
            
            fase_movimento = 2; // Muda para a próxima fase
            
        } else if (fase_movimento == 2) {
            printf("Fase 2 - Movimento horizontal (para a direita):\n");
            casas_movidas = 0;
            
            // Loop interno complexo para movimento horizontal
            j = 1;
            while (j <= CASAS_CAVALO_DIREITA && casas_movidas < CASAS_CAVALO_DIREITA) {
                
                printf("Direita\n");
                casas_movidas++;
                j++;
                
                // Verifica se o movimento está completo
                if (casas_movidas >= CASAS_CAVALO_DIREITA) {
                    movimento_completo = 1; // Marca movimento como completo
                    break; // Sai do loop interno
                }
            }
        }
    }
    
    printf("Cavalo completou o movimento em 'L' com loops complexos!\n\n");
    
    printf("=== SIMULAÇÃO AVANÇADA CONCLUÍDA ===\n");
    printf("Técnicas utilizadas:\n");
    printf("- Recursividade (Torre, Bispo, Rainha)\n");
    printf("- Loops aninhados (Bispo)\n");
    printf("- Loops complexos com múltiplas condições (Cavalo)\n");
    printf("- Controle de fluxo com break e continue (Cavalo)\n");
    
    return 0;
}