#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define TAM 10

/*Leia um vetor com 10 números de ponto flutuante, ordene os elementos deste vetor, e no
final escreva os elementos do vetor ordenado. */

void lerv(float v[]);
void printv(float v[]);

int main(){
    float v[TAM];

    //Entrada
    lerv(v);

    //Saída
    printv(v);

    return 0;
}

void lerv(float v[]){
    int leitura;
    for(int i = 0; i < TAM; i++){
        do{
            printf("Entre com índice %d:\n", i+1);
            leitura = scanf("%f", &v[i]);
            while(getchar() != '\n');
            if(leitura != 1){
                printf("Inválido!\n");
            }
        }while(leitura != 1);
    }
}

void printv(float v[]){
    float n3 = 0;
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < (TAM - 1); j++){
            if(v[j] >= v[j+1]){
                n3 = v[j+1];
                v[j+1] = v[j];
                v[j] = n3;
            }
        }
    }

    system("clear");

    for(int i = 0; i < TAM; i++){
        printf("%.2f\n", v[i]);
    }
}
