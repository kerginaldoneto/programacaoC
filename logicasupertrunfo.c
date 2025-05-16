#include <stdio.h>

int main() {
    // Dados pré-cadastrados da primeira carta - Brasil
    char pais1[] = "Brasil";
    float populacao1 = 214.3; // milhões
    float area1 = 8515767; // km²
    float pib1 = 2126.8; // bilhões USD
    int pontosTuristicos1 = 127;
    float densidadePopulacional1;
    float pibPerCapita1;
    
    // Dados pré-cadastrados da segunda carta - Japão
    char pais2[] = "Japão";
    float populacao2 = 124.3; // milhões
    float area2 = 377975; // km²
    float pib2 = 4230.5; // bilhões USD
    int pontosTuristicos2 = 95;
    float densidadePopulacional2;
    float pibPerCapita2;
    
    // Variáveis para o menu e comparação
    int primeiroAtributo, segundoAtributo;
    float valor1Carta1, valor1Carta2; // valores do primeiro atributo
    float valor2Carta1, valor2Carta2; // valores do segundo atributo
    float soma1, soma2; // soma dos atributos
    int pontosCarta1 = 0, pontosCarta2 = 0; // pontos para cada carta
    char nomeAtributo1[30], nomeAtributo2[30];
    
    // Cálculos dos atributos derivados
    densidadePopulacional1 = populacao1 / area1 * 1000; // hab/km²
    pibPerCapita1 = (pib1 * 1000) / populacao1; // USD per capita
    
    densidadePopulacional2 = populacao2 / area2 * 1000; // hab/km²
    pibPerCapita2 = (pib2 * 1000) / populacao2; // USD per capita
    
    // Cabeçalho
    printf("=== SUPER TRUNFO - COMPARAÇÃO AVANÇADA ===\n");
    printf("Você irá escolher DOIS atributos para comparar as cartas!\n\n");
    
    // Exibir as cartas
    printf("--- CARTA 1: %s ---\n", pais1);
    printf("1. População: %.1f milhões\n", populacao1);
    printf("2. Área: %.0f km²\n", area1);
    printf("3. PIB: %.1f bilhões USD\n", pib1);
    printf("4. Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("5. Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1);
    printf("6. PIB per Capita: %.2f USD\n", pibPerCapita1);
    
    printf("\n--- CARTA 2: %s ---\n", pais2);
    printf("1. População: %.1f milhões\n", populacao2);
    printf("2. Área: %.0f km²\n", area2);
    printf("3. PIB: %.1f bilhões USD\n", pib2);
    printf("4. Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("5. Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
    printf("6. PIB per Capita: %.2f USD\n", pibPerCapita2);
    
    // Primeiro menu - escolha do primeiro atributo
    printf("\n=== ESCOLHA O PRIMEIRO ATRIBUTO ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional (menor vence!)\n");
    printf("6 - PIB per Capita\n");
    printf("\nDigite sua opção (1-6): ");
    scanf("%d", &primeiroAtributo);
    
    // Processar primeiro atributo
    switch(primeiroAtributo) {
        case 1: // População
            valor1Carta1 = populacao1;
            valor1Carta2 = populacao2;
            sprintf(nomeAtributo1, "População (milhões)");
            pontosCarta1 += (populacao1 > populacao2) ? 1 : 0;
            pontosCarta2 += (populacao2 > populacao1) ? 1 : 0;
            break;
            
        case 2: // Área
            valor1Carta1 = area1;
            valor1Carta2 = area2;
            sprintf(nomeAtributo1, "Área (km²)");
            pontosCarta1 += (area1 > area2) ? 1 : 0;
            pontosCarta2 += (area2 > area1) ? 1 : 0;
            break;
            
        case 3: // PIB
            valor1Carta1 = pib1;
            valor1Carta2 = pib2;
            sprintf(nomeAtributo1, "PIB (bilhões USD)");
            pontosCarta1 += (pib1 > pib2) ? 1 : 0;
            pontosCarta2 += (pib2 > pib1) ? 1 : 0;
            break;
            
        case 4: // Pontos Turísticos
            valor1Carta1 = pontosTuristicos1;
            valor1Carta2 = pontosTuristicos2;
            sprintf(nomeAtributo1, "Pontos Turísticos");
            pontosCarta1 += (pontosTuristicos1 > pontosTuristicos2) ? 1 : 0;
            pontosCarta2 += (pontosTuristicos2 > pontosTuristicos1) ? 1 : 0;
            break;
            
        case 5: // Densidade Populacional (menor vence)
            valor1Carta1 = densidadePopulacional1;
            valor1Carta2 = densidadePopulacional2;
            sprintf(nomeAtributo1, "Densidade Pop. (hab/km²)");
            // Regra invertida: menor densidade vence
            pontosCarta1 += (densidadePopulacional1 < densidadePopulacional2) ? 1 : 0;
            pontosCarta2 += (densidadePopulacional2 < densidadePopulacional1) ? 1 : 0;
            break;
            
        case 6: // PIB per Capita
            valor1Carta1 = pibPerCapita1;
            valor1Carta2 = pibPerCapita2;
            sprintf(nomeAtributo1, "PIB per Capita (USD)");
            pontosCarta1 += (pibPerCapita1 > pibPerCapita2) ? 1 : 0;
            pontosCarta2 += (pibPerCapita2 > pibPerCapita1) ? 1 : 0;
            break;
            
        default:
            printf("Opção inválida! Encerrando o programa.\n");
            return 0;
    }
    
    // Segundo menu - escolha do segundo atributo (dinâmico)
    printf("\n=== ESCOLHA O SEGUNDO ATRIBUTO ===\n");
    printf("Obs: Você não pode escolher o mesmo atributo novamente!\n");
    
    // Menu dinâmico - não mostra o atributo já escolhido
    if (primeiroAtributo != 1) printf("1 - População\n");
    if (primeiroAtributo != 2) printf("2 - Área\n");
    if (primeiroAtributo != 3) printf("3 - PIB\n");
    if (primeiroAtributo != 4) printf("4 - Pontos Turísticos\n");
    if (primeiroAtributo != 5) printf("5 - Densidade Populacional (menor vence!)\n");
    if (primeiroAtributo != 6) printf("6 - PIB per Capita\n");
    
    printf("\nDigite sua opção: ");
    scanf("%d", &segundoAtributo);
    
    // Validar se o segundo atributo é diferente do primeiro
    if (segundoAtributo == primeiroAtributo || segundoAtributo < 1 || segundoAtributo > 6) {
        printf("Opção inválida! Você escolheu o mesmo atributo ou uma opção inexistente.\n");
        return 0;
    }
    
    // Processar segundo atributo
    switch(segundoAtributo) {
        case 1: // População
            valor2Carta1 = populacao1;
            valor2Carta2 = populacao2;
            sprintf(nomeAtributo2, "População (milhões)");
            pontosCarta1 += (populacao1 > populacao2) ? 1 : 0;
            pontosCarta2 += (populacao2 > populacao1) ? 1 : 0;
            break;
            
        case 2: // Área
            valor2Carta1 = area1;
            valor2Carta2 = area2;
            sprintf(nomeAtributo2, "Área (km²)");
            pontosCarta1 += (area1 > area2) ? 1 : 0;
            pontosCarta2 += (area2 > area1) ? 1 : 0;
            break;
            
        case 3: // PIB
            valor2Carta1 = pib1;
            valor2Carta2 = pib2;
            sprintf(nomeAtributo2, "PIB (bilhões USD)");
            pontosCarta1 += (pib1 > pib2) ? 1 : 0;
            pontosCarta2 += (pib2 > pib1) ? 1 : 0;
            break;
            
        case 4: // Pontos Turísticos
            valor2Carta1 = pontosTuristicos1;
            valor2Carta2 = pontosTuristicos2;
            sprintf(nomeAtributo2, "Pontos Turísticos");
            pontosCarta1 += (pontosTuristicos1 > pontosTuristicos2) ? 1 : 0;
            pontosCarta2 += (pontosTuristicos2 > pontosTuristicos1) ? 1 : 0;
            break;
            
        case 5: // Densidade Populacional (menor vence)
            valor2Carta1 = densidadePopulacional1;
            valor2Carta2 = densidadePopulacional2;
            sprintf(nomeAtributo2, "Densidade Pop. (hab/km²)");
            // Regra invertida: menor densidade vence
            pontosCarta1 += (densidadePopulacional1 < densidadePopulacional2) ? 1 : 0;
            pontosCarta2 += (densidadePopulacional2 < densidadePopulacional1) ? 1 : 0;
            break;
            
        case 6: // PIB per Capita
            valor2Carta1 = pibPerCapita1;
            valor2Carta2 = pibPerCapita2;
            sprintf(nomeAtributo2, "PIB per Capita (USD)");
            pontosCarta1 += (pibPerCapita1 > pibPerCapita2) ? 1 : 0;
            pontosCarta2 += (pibPerCapita2 > pibPerCapita1) ? 1 : 0;
            break;
    }
    
    // Calcular as somas dos atributos
    soma1 = valor1Carta1 + valor2Carta1;
    soma2 = valor1Carta2 + valor2Carta2;
    
    // Exibir resultado detalhado
    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
    printf("\n--- Detalhamento por Atributo ---\n");
    
    // Primeiro atributo
    printf("\n1º Atributo: %s\n", nomeAtributo1);
    printf("  %s: %.2f\n", pais1, valor1Carta1);
    printf("  %s: %.2f\n", pais2, valor1Carta2);
    if (primeiroAtributo == 5) { // Densidade (menor vence)
        printf("  Vencedor: %s\n", (valor1Carta1 < valor1Carta2) ? pais1 : 
                                  (valor1Carta2 < valor1Carta1) ? pais2 : "Empate");
    } else { // Outros atributos (maior vence)
        printf("  Vencedor: %s\n", (valor1Carta1 > valor1Carta2) ? pais1 : 
                                  (valor1Carta2 > valor1Carta1) ? pais2 : "Empate");
    }
    
    // Segundo atributo
    printf("\n2º Atributo: %s\n", nomeAtributo2);
    printf("  %s: %.2f\n", pais1, valor2Carta1);
    printf("  %s: %.2f\n", pais2, valor2Carta2);
    if (segundoAtributo == 5) { // Densidade (menor vence)
        printf("  Vencedor: %s\n", (valor2Carta1 < valor2Carta2) ? pais1 : 
                                  (valor2Carta2 < valor2Carta1) ? pais2 : "Empate");
    } else { // Outros atributos (maior vence)
        printf("  Vencedor: %s\n", (valor2Carta1 > valor2Carta2) ? pais1 : 
                                  (valor2Carta2 > valor2Carta1) ? pais2 : "Empate");
    }
    
    // Soma dos atributos
    printf("\n--- Soma dos Atributos ---\n");
    printf("  %s: %.2f + %.2f = %.2f\n", pais1, valor1Carta1, valor2Carta1, soma1);
    printf("  %s: %.2f + %.2f = %.2f\n", pais2, valor1Carta2, valor2Carta2, soma2);
    
    // Pontuação por vitórias individuais
    printf("\n--- Pontuação por Vitórias ---\n");
    printf("  %s: %d ponto(s)\n", pais1, pontosCarta1);
    printf("  %s: %d ponto(s)\n", pais2, pontosCarta2);
    
    // Resultado final
    printf("\n=== VENCEDOR FINAL ===\n");
    
    // Critério 1: Quem venceu mais atributos
    if (pontosCarta1 > pontosCarta2) {
        printf("%s VENCE! 🏆\n", pais1);
        printf("Motivo: Venceu %d de 2 atributos!\n", pontosCarta1);
    } else if (pontosCarta2 > pontosCarta1) {
        printf("%s VENCE! 🏆\n", pais2);
        printf("Motivo: Venceu %d de 2 atributos!\n", pontosCarta2);
    } else {
        // Critério 2: Maior soma (em caso de empate nas vitórias)
        if (soma1 > soma2) {
            printf("%s VENCE! 🏆\n", pais1);
            printf("Motivo: Empate nas vitórias, mas tem maior soma total (%.2f > %.2f)!\n", soma1, soma2);
        } else if (soma2 > soma1) {
            printf("%s VENCE! 🏆\n", pais2);
            printf("Motivo: Empate nas vitórias, mas tem maior soma total (%.2f > %.2f)!\n", soma2, soma1);
        } else {
            printf("EMPATE TÉCNICO! 🤝\n");
            printf("As cartas empataram em número de vitórias e na soma total!\n");
        }
    }
    
    printf("\n--- FIM DO JOGO ---\n");
    
    return 0;
}