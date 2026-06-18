#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>

/*6. Fazer um programa que leia um conjunto de idades de pessoas. O final do conjunto de valores
é conhecido através do valor -1. Calcule e escreva a idade média deste conjunto */

float calc();

int main(){
    float media;
    setlocale(LC_ALL, "");

    media=calc();

    printf(" %.2f",media);

    return 0;
}

float calc(){
    float v;
    float acumulador=0;
    int indice=0;

    do{
        printf("Entre com a %dº idade:\n",indice+1);
        scanf("%f",&v);
        if(indice == 0 && v == -1)
            printf("Você não pode encerrar o programa sem entrar com uma idade válida primeiro.\n");
        else if(v == -1)
            break;
        else{
            acumulador = acumulador + v;
            indice++;
            }
    }while(true);
    system("clear");
    printf("A média das %d idades é:",indice);
    return acumulador/(indice*1.0);
}
