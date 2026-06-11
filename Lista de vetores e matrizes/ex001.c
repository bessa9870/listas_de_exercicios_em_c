#include <stdio.h>
#include <locale.h>

/*Escreva um programa que leia 10 números inteiros e
 os armazene em um vetor. Imprima o vetor, o maior
 elemento e a posição que ele se encontra*/

 int main(){
    int tamanho = 10;
    int vet[tamanho];
    int maior = 0;

    for(int i = 0; i < tamanho; i++){
        printf("Entre com o índice %d:\n", i+1);
        scanf("%d", &vet[i]);
        if(vet[i] >= maior){
            maior = vet[i];
        }
    }

    printf("O maior número é %d", maior);

    return 0;
 }
