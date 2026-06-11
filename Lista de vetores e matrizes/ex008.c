#include <stdio.h>
#include <locale.h>

/*Faça um programa que leia um vetor de 10 posições e verifique
se existem valores iguais e os escreva. */

void lerVet(int vet[10]);
void imprimeVet(int vet[10]);

int main(){
    int vet[10];

    lerVet(vet);

    imprimeVet(vet);

    return 0;
}

void lerVet(int vet[10]){
    int leitura;
    for(int i = 0; i < 10; i++){
        do{
            printf("Entre com índice %d\n", i + 1);
            leitura = scanf("%d", &vet[i]);
            if(leitura != 1){
                printf("\nInválido\n");
                while (getchar() != '\n');
            }
        }while(leitura != 1);
    }
}

void imprimeVet(int vet[10]){
    printf("\nNúmeros iguais:\n");
    for(int i = 0; i < 10; i++){
        int repeticao = 0;
        for(int k = 0; k < i; k++){
            if(vet[k] == vet[i]){
                repeticao = 1;
                break;
            }
        }
        if(repeticao == 0){
            for(int j = (i + 1); j < 10; j++){
                if(vet[i] == vet[j]){
                    printf("Índice %d: %d\t Índice %d: %d\n",i + 1, vet[i], j + 1, vet[j]);
                }
            }
        }
    }
}
