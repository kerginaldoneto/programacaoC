#include <stdio.h>

int main(){
    float nota1, nota2 , nota3;
    float media;

    printf("Insira sua primeira nota: ", nota1);
    scanf("%f", &nota1);

    printf("Insira sua segunda nota: ", nota2);
    scanf("%f", &nota2);

    printf("Insira sua terceira nota: ", nota3);
    scanf("%f", &nota3);

    media = (nota1 + nota2 + nota3) / 3;

    printf("A sua média é: %.1f", media);



    return 0;
}