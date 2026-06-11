#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/* Leia 10 números inteiros e armazene em um vetor. Em seguida escreva os elementos que
são primos e suas respectivas posições no vetor.*/

void lerVet(int vet[]);
void imprimeVet(int vet[]);

int main(){
    int vet[10];
    setlocale(LC_ALL, "");

    lerVet(vet);
    system("clear");

    imprimeVet(vet);

    return 0;
}

void lerVet(int vet[]){
    int leitura;
    for(int i = 0; i < 10; i++){
        do{
            printf("Entre com o índice %d:\n", i+1);
            leitura = scanf("%d", &vet[i]);
            if(leitura != 1){
                printf("Entrada do ínidce %d inválida.\n", i+1);
                while(getchar() != '\n');
            }
        }while(leitura != 1);
    }
}

void imprimeVet(int vet[]){
    printf("Seu vetor:\n");
    for(int i = 0; i < 10; i++){
        printf("%d\n", vet[i]);
    }

    printf("\n\nImprimindo os índices e seus respectivos números primos\n");
    for(int i = 0; i < 10; i++){
        int div = 0;
        for(int j = 1; j <= vet[i]; j++){
            if(vet[i] % j == 0){
                div++;
            }
        }
        if(div == 2){
            printf("Índice %d: [%d]\n", i+1, vet[i]);
        }
    }
}
