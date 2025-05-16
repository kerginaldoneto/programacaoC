#include <stdio.h>

int main() {
    // Variáveis para a primeira carta
    char estado1[3];
    char codigo1[4];
    char nomeCidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidadePopulacional1;
    float pibPerCapita1;
    
    // Variáveis para a segunda carta
    char estado2[3];
    char codigo2[4];
    char nomeCidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidadePopulacional2;
    float pibPerCapita2;
    
    // Variáveis para o menu e comparação
    int opcao;
    int resultado; // 1 se carta1 venceu, 2 se carta2 venceu, 0 se empate
    
    // Instruções para o usuário
    printf("=== SUPER TRUNFO - COMPARAÇÃO DE CARTAS ===\n");
    printf("Você irá cadastrar os dados de 2 cartas e depois compará-las.\n\n");
    
    // CADASTRO DA PRIMEIRA CARTA
    printf("--- CARTA 1 ---\n");
    printf("Digite o estado: ");
    scanf("%s", estado1);
    
    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", codigo1);
    
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nomeCidade1);
    
    printf("Digite a população: ");
    scanf("%lu", &populacao1);
    
    printf("Digite a área em km²: ");
    scanf("%f", &area1);
    
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);
    
    // Cálculos da primeira carta
    densidadePopulacional1 = (float)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000.0f) / (float)populacao1;
    
    printf("\n");
    
    // CADASTRO DA SEGUNDA CARTA
    printf("--- CARTA 2 ---\n");
    printf("Digite o estado: ");
    scanf("%s", estado2);
    
    printf("Digite o código da carta (ex: B02): ");
    scanf("%s", codigo2);
    
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nomeCidade2);
    
    printf("Digite a população: ");
    scanf("%lu", &populacao2);
    
    printf("Digite a área em km²: ");
    scanf("%f", &area2);
    
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);
    
    // Cálculos da segunda carta
    densidadePopulacional2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0f) / (float)populacao2;
    
    // EXIBIÇÃO DOS DADOS CADASTRADOS
    printf("\n=== CARTAS CADASTRADAS ===\n\n");
    
    printf("Carta 1 - %s (%s)\n", nomeCidade1, estado1);
    printf("  Estado: %s\n", estado1);
    printf("  Código: %s\n", codigo1);
    printf("  População: %lu hab\n", populacao1);
    printf("  Área: %.2f km²\n", area1);
    printf("  PIB: R$ %.2f bilhões\n", pib1);
    printf("  Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("  Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1);
    printf("  PIB per Capita: R$ %.2f\n", pibPerCapita1);
    
    printf("\nCarta 2 - %s (%s)\n", nomeCidade2, estado2);
    printf("  Estado: %s\n", estado2);
    printf("  Código: %s\n", codigo2);
    printf("  População: %lu hab\n", populacao2);
    printf("  Área: %.2f km²\n", area2);
    printf("  PIB: R$ %.2f bilhões\n", pib2);
    printf("  Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("  Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
    printf("  PIB per Capita: R$ %.2f\n", pibPerCapita2);
    
    // MENU INTERATIVO PARA ESCOLHA DO ATRIBUTO
    printf("\n=== MENU DE COMPARAÇÃO ===\n");
    printf("Escolha o atributo para comparar as cartas:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Populacional (menor vence!)\n");
    printf("6 - PIB per Capita\n");
    printf("\nDigite sua opção (1-6): ");
    scanf("%d", &opcao);
    
    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
    
    // SWITCH PARA PROCESSAR A ESCOLHA DO USUÁRIO
    switch(opcao) {
        case 1: // População
            printf("Atributo escolhido: População\n\n");
            printf("Carta 1 - %s: %lu habitantes\n", nomeCidade1, populacao1);
            printf("Carta 2 - %s: %lu habitantes\n", nomeCidade2, populacao2);
            
            if (populacao1 > populacao2) {
                resultado = 1;
            } else if (populacao2 > populacao1) {
                resultado = 2;
            } else {
                resultado = 0;
            }
            break;
            
        case 2: // Área
            printf("Atributo escolhido: Área\n\n");
            printf("Carta 1 - %s: %.2f km²\n", nomeCidade1, area1);
            printf("Carta 2 - %s: %.2f km²\n", nomeCidade2, area2);
            
            if (area1 > area2) {
                resultado = 1;
            } else if (area2 > area1) {
                resultado = 2;
            } else {
                resultado = 0;
            }
            break;
            
        case 3: // PIB
            printf("Atributo escolhido: PIB\n\n");
            printf("Carta 1 - %s: R$ %.2f bilhões\n", nomeCidade1, pib1);
            printf("Carta 2 - %s: R$ %.2f bilhões\n", nomeCidade2, pib2);
            
            if (pib1 > pib2) {
                resultado = 1;
            } else if (pib2 > pib1) {
                resultado = 2;
            } else {
                resultado = 0;
            }
            break;
            
        case 4: // Pontos Turísticos
            printf("Atributo escolhido: Número de Pontos Turísticos\n\n");
            printf("Carta 1 - %s: %d pontos turísticos\n", nomeCidade1, pontosTuristicos1);
            printf("Carta 2 - %s: %d pontos turísticos\n", nomeCidade2, pontosTuristicos2);
            
            if (pontosTuristicos1 > pontosTuristicos2) {
                resultado = 1;
            } else if (pontosTuristicos2 > pontosTuristicos1) {
                resultado = 2;
            } else {
                resultado = 0;
            }
            break;
            
        case 5: // Densidade Populacional (menor vence)
            printf("Atributo escolhido: Densidade Populacional (menor valor vence!)\n\n");
            printf("Carta 1 - %s: %.2f hab/km²\n", nomeCidade1, densidadePopulacional1);
            printf("Carta 2 - %s: %.2f hab/km²\n", nomeCidade2, densidadePopulacional2);
            
            // REGRA INVERTIDA: menor densidade vence
            if (densidadePopulacional1 < densidadePopulacional2) {
                resultado = 1;
            } else if (densidadePopulacional2 < densidadePopulacional1) {
                resultado = 2;
            } else {
                resultado = 0;
            }
            break;
            
        case 6: // PIB per Capita
            printf("Atributo escolhido: PIB per Capita\n\n");
            printf("Carta 1 - %s: R$ %.2f\n", nomeCidade1, pibPerCapita1);
            printf("Carta 2 - %s: R$ %.2f\n", nomeCidade2, pibPerCapita2);
            
            if (pibPerCapita1 > pibPerCapita2) {
                resultado = 1;
            } else if (pibPerCapita2 > pibPerCapita1) {
                resultado = 2;
            } else {
                resultado = 0;
            }
            break;
            
        default:
            printf("Opção inválida! Por favor, escolha um número entre 1 e 6.\n");
            return 0;
    }
    
    // EXIBIÇÃO DO RESULTADO FINAL
    printf("\n");
    if (resultado == 1) {
        printf("Resultado: Carta 1 (%s) VENCEU! 🏆\n", nomeCidade1);
    } else if (resultado == 2) {
        printf("Resultado: Carta 2 (%s) VENCEU! 🏆\n", nomeCidade2);
    } else {
        printf("Resultado: EMPATE! 🤝\n");
    }
    
    printf("\n--- FIM DO JOGO ---\n");
    
    return 0;
}