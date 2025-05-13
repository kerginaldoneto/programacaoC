#include <stdio.h>

struct Carta {
    char estado;
    char codigo[4];
    char nomeCidade[100];
    unsigned long int populacao;
    float area;
    float pib; // em bilhões
    int pontosTuristicos;
};

int main() {
    struct Carta carta1, carta2;
    float densidade1, densidade2;
    float pibPerCapita1, pibPerCapita2;
    float superPoder1, superPoder2;

    // ===== Leitura da Carta 1 =====
    printf("Cadastro da Carta 1\n");
    printf("Estado: "); scanf(" %c", &carta1.estado);
    printf("Código: "); scanf("%s", carta1.codigo);
    printf("Nome da Cidade: "); scanf(" %[^\n]", carta1.nomeCidade);
    printf("População: "); scanf("%lu", &carta1.populacao);
    printf("Área (km²): "); scanf("%f", &carta1.area);
    printf("PIB (bilhões): "); scanf("%f", &carta1.pib);
    printf("Pontos Turísticos: "); scanf("%d", &carta1.pontosTuristicos);

    // ===== Leitura da Carta 2 =====
    printf("\nCadastro da Carta 2\n");
    printf("Estado: "); scanf(" %c", &carta2.estado);
    printf("Código: "); scanf("%s", carta2.codigo);
    printf("Nome da Cidade: "); scanf(" %[^\n]", carta2.nomeCidade);
    printf("População: "); scanf("%lu", &carta2.populacao);
    printf("Área (km²): "); scanf("%f", &carta2.area);
    printf("PIB (bilhões): "); scanf("%f", &carta2.pib);
    printf("Pontos Turísticos: "); scanf("%d", &carta2.pontosTuristicos);

    // ===== Cálculos =====
    densidade1 = carta1.populacao / carta1.area;
    pibPerCapita1 = (carta1.pib * 1000000000.0f) / carta1.populacao;

    densidade2 = carta2.populacao / carta2.area;
    pibPerCapita2 = (carta2.pib * 1000000000.0f) / carta2.populacao;

    superPoder1 = (float)carta1.populacao + carta1.area + carta1.pib + carta1.pontosTuristicos + pibPerCapita1 + (1.0f / densidade1);
    superPoder2 = (float)carta2.populacao + carta2.area + carta2.pib + carta2.pontosTuristicos + pibPerCapita2 + (1.0f / densidade2);

    // ===== Exibição dos Dados =====
    printf("\nCarta 1:\n");
    printf("Estado: %c | Código: %s | Cidade: %s\n", carta1.estado, carta1.codigo, carta1.nomeCidade);
    printf("População: %lu | Área: %.2f km² | PIB: %.2f bilhões | Pontos Turísticos: %d\n",
           carta1.populacao, carta1.area, carta1.pib, carta1.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km² | PIB per Capita: %.2f reais\n", densidade1, pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);

    printf("\nCarta 2:\n");
    printf("Estado: %c | Código: %s | Cidade: %s\n", carta2.estado, carta2.codigo, carta2.nomeCidade);
    printf("População: %lu | Área: %.2f km² | PIB: %.2f bilhões | Pontos Turísticos: %d\n",
           carta2.populacao, carta2.area, carta2.pib, carta2.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km² | PIB per Capita: %.2f reais\n", densidade2, pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);

    // ===== Comparações =====
    printf("\nComparação de Cartas:\n");
    printf("População: Carta 1 venceu (%d)\n", carta1.populacao > carta2.populacao);
    printf("Área: Carta 1 venceu (%d)\n", carta1.area > carta2.area);
    printf("PIB: Carta 1 venceu (%d)\n", carta1.pib > carta2.pib);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", carta1.pontosTuristicos > carta2.pontosTuristicos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", densidade1 < densidade2); // menor vence
    printf("PIB per Capita: Carta 1 venceu (%d)\n", pibPerCapita1 > pibPerCapita2);
    printf("Super Poder: Carta 1 venceu (%d)\n", superPoder1 > superPoder2);

    return 0;
}
