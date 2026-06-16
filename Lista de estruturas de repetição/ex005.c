#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define TAMANHO 20

/* 5. Fazer um programa que leia 20 idades de pessoas. Calcule e escreva a idade média deste
grupo.*/

void lervet(float *v, int tam);
float calc(float *v, int tam);
void imprimir(float media, int tam);

int main(){
    float pessoas[TAMANHO];
    float media;
    setlocale(LC_ALL, "");

    lervet(pessoas,TAMANHO);
    media = calc(pessoas,TAMANHO);
    imprimir(media,TAMANHO);
}

void lervet(float *v, int tam){
    for(int i = 0; i < TAMANHO; i++){
        printf("Entre com a %dº idade:\n",i+1);
        scanf("%f", (v+i));
    }
    system("clear");
}
float calc(float *v, int tam){
    float media=0;
    for(int i = 0; i < TAMANHO; i++)
        media = media + *(v+i);
    system("clear"); //Acho que se eu usar isso depois do return, não vai funcionar
    return media = media / TAMANHO;
}
void imprimir(float media, int tam){
    printf("A média das %d idades é %.1f",TAMANHO,media);
}
