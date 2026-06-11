#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*Leia 10 números inteiros e armazene em um vetor v. Crie dois novos vetores v1 e v2. Copie
os valores ímpares de v para v1, e os valores pares de v para v2. Note que cada um dos
vetores v1 e v2 têm no máximo 10 elementos, mas nem todos os elementos são utilizados.
No final escreva os elementos UTILIZADOS de v1 e v2.*/

void lerVet(int vet[], int v1[], int v2[], int *cont1, int *cont2);
void imprimeVet(int vet[], int v1[], int v2[], int cont1, int cont2);

int main(){
    int vet[10];
    int v1[10];
    int v2[10];
    int cont1 = 0;
    int cont2 = 0;
    setlocale(LC_ALL, "");

    lerVet(vet, v1, v2, &cont1, &cont2);
    system("clear");
    imprimeVet(vet, v1, v2, cont1, cont2);

    return 0;
}

void lerVet(int vet[], int v1[], int v2[], int *cont1, int *cont2){
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
        if(vet[i] % 2 != 0){
                v1[*cont1] = vet[i];
                (*cont1)++;
            }else{
                v2[*cont2] = vet[i];
                (*cont2)++;
            }
    }
}

void imprimeVet(int vet[], int v1[], int v2[], int cont1, int cont2){
    printf("\tPrimeiro vetor\n");
    for(int i = 0; i < 10; i++){
        printf("%d ", vet[i]);
    }
    puts("\n");
    printf("\tVetor de impares\n");
    for(int i = 0; i < cont1; i++){
        printf("%d ", v1[i]);
    }
    puts("\n");
    printf("\tVetor de pares\n");
    for(int i = 0; i < cont2; i++){
        printf("%d ", v2[i]);
    }
}
