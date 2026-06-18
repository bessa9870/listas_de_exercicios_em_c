#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>
/*7. Fazer um programa que leia um conjunto de alturas de pessoas. O final do conjunto de valores
é conhecido através do valor zero. Escreva a menor altura deste conjunto */

float calc();

int main(){
    float menor_altura;
    setlocale(LC_ALL, "");

    menor_altura=calc();

    printf(" %.2f",menor_altura);

    return 0;
}

float calc(){
    float v, menor=0;
    int indice=0;

    do{
        printf("Entre com a %dº altura (exemplo 1,70, 1,74...):\n",indice+1);
        scanf("%f",&v);
        if(indice == 0 && v == 0)//Se encerrar no ínicio
            printf("Você não pode encerrar o programa sem entrar com uma idade válida primeiro.\n");
        else if(v == 0)//Se encerrar depois do ínicio
            break;
        else{//Quando seguir normalmente
            if(indice == 0 || v < menor){
                menor = v;
            }
            indice++;
        }
    }while(true);
    system("clear");
    printf("A menor entre as %d alturas é:",indice);
    return menor;
}
