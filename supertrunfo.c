#include <stdio.h>

int main() {
    // Variáveis primeira carta
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidadePopulacional1;
    float pibPerCapita1;
    float superPoder1;
    
    // Variáveis segunda carta
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidadePopulacional2;
    float pibPerCapita2;
    float superPoder2;
    
    // Variáveis para comparação
    int vencedorPopulacao;
    int vencedorArea;
    int vencedorPIB;
    int vencedorPontosTuristicos;
    int vencedorDensidade;
    int vencedorPIBPerCapita;
    int vencedorSuperPoder;
    
    // Instruções para o usuário
    printf("=== SUPER TRUNFO - CADASTRO DE CARTAS ===\n");
    printf("Você irá cadastrar os dados de 2 cartas.\n\n");
    
    // Leitura dos dados da primeira carta
    printf("--- CARTA 1 ---\n");
    printf("Digite o estado (letra de A a H): ");
    scanf(" %c", &estado1);
    
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
    superPoder1 = (float)populacao1 + area1 + (pib1 * 1000000000.0f) + (float)pontosTuristicos1 + pibPerCapita1 + (1.0f / densidadePopulacional1);
    
    printf("\n");
    
    // Leitura dos dados da segunda carta
    printf("--- CARTA 2 ---\n");
    printf("Digite o estado (letra de A a H): ");
    scanf(" %c", &estado2);
    
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
    superPoder2 = (float)populacao2 + area2 + (pib2 * 1000000000.0f) + (float)pontosTuristicos2 + pibPerCapita2 + (1.0f / densidadePopulacional2);
    
    // Comparações entre as cartas
    vencedorPopulacao = (populacao1 > populacao2);
    vencedorArea = (area1 > area2);
    vencedorPIB = (pib1 > pib2);
    vencedorPontosTuristicos = (pontosTuristicos1 > pontosTuristicos2);
    vencedorDensidade = (densidadePopulacional1 < densidadePopulacional2); // Menor densidade vence
    vencedorPIBPerCapita = (pibPerCapita1 > pibPerCapita2);
    vencedorSuperPoder = (superPoder1 > superPoder2);
    
    // Exibição dos dados cadastrados
    printf("\n\n=== CARTAS CADASTRADAS ===\n\n");
    
    // Exibição da primeira carta
    printf("Carta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);
    
    printf("\n");
    
    // Exibição da segunda carta
    printf("Carta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);
    
    // Resultado das comparações
    printf("\n\n=== COMPARAÇÃO DE CARTAS ===\n\n");
    printf("População: Carta %d venceu (%d)\n", 2 - vencedorPopulacao, vencedorPopulacao);
    printf("Área: Carta %d venceu (%d)\n", 2 - vencedorArea, vencedorArea);
    printf("PIB: Carta %d venceu (%d)\n", 2 - vencedorPIB, vencedorPIB);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", 2 - vencedorPontosTuristicos, vencedorPontosTuristicos);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", 2 - vencedorDensidade, vencedorDensidade);
    printf("PIB per Capita: Carta %d venceu (%d)\n", 2 - vencedorPIBPerCapita, vencedorPIBPerCapita);
    printf("Super Poder: Carta %d venceu (%d)\n", 2 - vencedorSuperPoder, vencedorSuperPoder);
    
    return 0;
}