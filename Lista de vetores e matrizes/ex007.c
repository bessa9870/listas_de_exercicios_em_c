#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*Faça um programa que receba do usuário dois arrays, A e B, com 10 números inteiros cada.
Crie um novo array C calculando C = A - B. Mostre na tela os dados do array C. */

void lerVet(int vet[], int tam);
void lerVetC(int vetA[], int vetB[], int vetC[], int tam);

int main(){
    int tam = 10;
    int vetA[tam];
    int vetB[tam];
    int vetC[tam];
    setlocale(LC_ALL, "");

    printf("Vetor A\n");
    lerVet(vetA, tam);

    system("clear");
    printf("Vetor B\n");
    lerVet(vetB, tam);

    system("clear");
    printf("Vetor C\n");
    lerVetC(vetA, vetB, vetC, tam);

    return 0;
}
void lerVet(int vet[], int tam){
int leitura;
    for(int i = 0; i < tam; i++){
        do{
            printf("Entre com n %d:\n", i+1);
            leitura = scanf("%d", &vet[i]);
            if(leitura != 1){
                printf("\nEntrada inválida\n");
                while(getchar() != '\n');
            }
        }while(leitura != 1);
    }
}

void lerVetC(int vetA[], int vetB[], int vetC[], int tam){
    for(int i =0; i < tam; i++){
        vetC[i] = vetA[i] - vetB[i];
        printf("%d\n", vetC[i]);
    }
}
