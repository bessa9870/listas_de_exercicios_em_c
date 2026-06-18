#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAMANHO 50
/*8. Fazer um programa que leia um conjunto de dados contendo o sexo e a altura de 50 pessoas.
Escreva a altura média das mulheres */

float calc(int tam);

int main(){
    float media;
    setlocale(LC_ALL, "");
    printf("Use vírgula.\n\n");

    media=calc(TAMANHO);
    if(media != 0.0)
    printf("%.2f",media);

    return 0;
}

float calc(int tam){
    char sexo;//eita bixo sexokkjk
    float altura, acumulador=0;
    int contador=0;

    for(int i = 0; i < tam; i++){
        printf("Índice %d:\nQual seu sexo? (M ou F)\n>",i+1);
        scanf("%c",&sexo);
        while(getchar() != '\n');
        printf("Qual sua altura? (1,60, 1,70...?\n>");
        scanf("%f",&altura);
        if(sexo == 'F' || sexo == 'f'){
            acumulador = acumulador + altura;
            contador++;
        }
        while(getchar() !='\n');
        system("clear");
    }
    if(contador == 0){
        printf("Sem mulher sem operação.");
        return 0.0;
    }else{
        printf("A média da altura das %d mulheres nessa pesquisa é: ",contador);
        return acumulador / (contador*1.0);
    }
}
