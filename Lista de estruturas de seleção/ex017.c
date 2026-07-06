#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* 17) Faça um programa que receba a medida de um ângulo em graus, um número inteiro.
Determine e imprima o quadrante em que se localiza este ângulo. Considere os quadrantes
abaixo:
Ângulo Quadrante
0 |__ 90 1º quadrante
90 |__ 180 2º quadrante
180 |__ 270 3º quadrante
270 |__ 360 4º quadrante
0 __ -90 1º quadrante
-90 |__ -180 2º quadrante
-180 |__ -270 3º quadrante
-270 |__| -360 4º quadrante
Para ângulos maiores que 360 graus, reduza ao intervalo de 0 a 360. */

void limpar_buffer();
void ler_int(int *p);
void quadrante(int *p);

int main(){
    int angulo;
    setlocale(LC_ALL,"");

    printf("Entre com um ângulo: ");
    ler_int(&angulo);

    quadrante(&angulo);

    return 0;
}

void limpar_buffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void ler_int(int *p){
    int leitura;
    do{
        leitura=scanf("%d",p);
        limpar_buffer();
        if(leitura!= 1)
            printf("Entrada inválida.\n");
    }while(leitura != 1);
}

void quadrante(int *p){
    if(*p < 0){
        do{
            *p = *p + 360;  //Eu nem pensei nisso
        }while(*p < 0);
    }else if(*p > 360){
        do{
            *p = *p - 360;
        }while(*p > 360);
    }

    if(*p < 90)  //Seguindo as instruções do enunciado que diz que 90 não entra aqui
        printf("Primeiro quadrante.\n");
    else if(*p < 180)
        printf("Segundo quadrante.\n");
    else if(*p < 270)
        printf("Terceiro quadrante.\n");
    else if(*p <= 360)
        printf("Quarto quadrante.\n");
    else
        printf("Quadrante indefinido.\n");
}
