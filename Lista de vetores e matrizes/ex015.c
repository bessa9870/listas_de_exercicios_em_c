#include <stdio.h>
#include <locale.h>
#include <stdio.h>
#define TAMANHO 10

/*Leia um vetor com 20 números inteiros. Escreva os elementos do vetor eliminando
elementos repetidos. */

void leitura(int v[]);
void saida(int v[]);

int main(){
    int v[TAMANHO];
    setlocale(LC_ALL, "");

    //Entrada
    leitura(v);

    //Saída
    saida(v);

    return 0;
}

void leitura(int v[]){
    for(int i = 0; i < TAMANHO; i++){
        int leitura = 0;
        do{
            printf("Entre com índice %d:\n", i+1);
            leitura = scanf("%d", &v[i]);
            while(getchar() != '\n');
            if(leitura != 1){
                printf("Entrada inválida!\n");
            }
        }while(leitura != 1);
    }
    puts("");
}

void saida(int v[]){
    for(int i = 0; i < TAMANHO; i++){
        int n = 0;
        for(int j = 0; j < i; j++){
            if(v[j] == v[i]){
                n = 1;
                break;
            }
        }
        if(n == 1){
            printf("--\n");
        }else{
            printf("%d\n", v[i]);
        }
    }
}
