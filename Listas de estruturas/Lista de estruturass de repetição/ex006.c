#include <stdio.h>
#include <locale.h>

/*Fazer um programa que leia um conjunto de idades de pessoas.
O final do conjunto de valores é conhecido através do valor -1.
Calcule e escreva a idade média deste conjunto */

int main(){
    int idade = 0;
    int acumulador = 0;
    int contador = 0;
    float media = 0.0;

    for(int i = 0; idade != -1 ;i++){
        printf("Entre coo a %d idade:\n", i+1);
        scanf("%d", &idade);
        if(idade != -1){
            acumulador = acumulador + idade;
            contador++;
        }
    }

    if(contador == 0){
        printf("Nenhuma idade válida inserida!");
    }else{
        media = (float)acumulador / contador;
        printf("Média = %f", media);
    }
    return 0;
}

