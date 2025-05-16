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
    
    // Variáveis para comparação
    int vencedor;
    
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
    printf("  População: %lu\n", populacao1);
    printf("  Área: %.2f km²\n", area1);
    printf("  PIB: %.2f bilhões de reais\n", pib1);
    printf("  Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1);
    printf("  PIB per Capita: R$ %.2f\n", pibPerCapita1);
    
    printf("\nCarta 2 - %s (%s)\n", nomeCidade2, estado2);
    printf("  Estado: %s\n", estado2);
    printf("  Código: %s\n", codigo2);
    printf("  População: %lu\n", populacao2);
    printf("  Área: %.2f km²\n", area2);
    printf("  PIB: %.2f bilhões de reais\n", pib2);
    printf("  Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
    printf("  PIB per Capita: R$ %.2f\n", pibPerCapita2);
    
    // COMPARAÇÃO DE UM ATRIBUTO ESCOLHIDO (População)
    // Aqui escolhemos Population como atributo de comparação
    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
    printf("Atributo escolhido: População\n\n");
    
    printf("Carta 1 - %s (%s): %lu habitantes\n", nomeCidade1, estado1, populacao1);
    printf("Carta 2 - %s (%s): %lu habitantes\n", nomeCidade2, estado2, populacao2);
    
    // Determinação do vencedor usando estrutura if-else
    if (populacao1 > populacao2) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", nomeCidade1);
    } else if (populacao2 > populacao1) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", nomeCidade2);
    } else {
        printf("\nResultado: Empate!\n");
    }
    
    return 0;
}