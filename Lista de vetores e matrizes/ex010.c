#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*Ler uma sequência de nos. reais e determinar o maior elemento
desta sequência. A sequência termina quando for digitado o no. Zero. */

void lerN(int *n);
void lerVet(float vet[], int n, float *maior);

int main(){
    int n;
    float maior = 0;
    setlocale(LC_ALL, "");

    //Ler o tamanho
    lerN(&n);
    float vet[n];

    lerVet(vet, n, &maior);


    return 0;
}

void lerN(int *n){
    int leitura;
    do{
        printf("Quantos números vai declarar?\n");
        leitura = scanf("%d", n);
        while(getchar() != '\n');
        if(*n <= 0){
            printf("\nNúmero inválido! Presssione Enter para tentar novamente.\n");
            while(getchar() != '\n');
            system("clear");
        }else if(leitura != 1){
            printf("\nCaractere inválido! Pressione Enter para tentar novamente.\n");
            while(getchar() != '\n');
            system("clear");
        }
    }while(leitura != 1 || *n <= 0);
}


void lerVet(float vet[], int n, float *maior){
    int leitura;
    for(int i = 0; i < n; i++){
        do{
            printf("Entre com o ndice %d:\n", i+1);
            leitura = scanf("%f", &vet[i]);
            if(leitura != 1){
                printf("\nInválido!\n");
                while(getchar() != '\n');
                }
        }while(leitura != 1);
        if(vet[i] == 0){
            break;
        }else{
            if(i == 0){
                *maior = vet[i];
            }else{
                if(vet[i] >= *maior){
                    *maior = vet[i];
                }
            }
        }

    }
        puts("");

    if(*maior == 0){
        printf("\nPrograma encerrado.");
    }else
        printf("O maior número da sequeência é %.2f\n\nPprograma encerrado.", *maior);
}

