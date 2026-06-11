#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define TAMANHO 10

/*17. Peça ao usuário para digitar dez valores numéricos e ordene por ordem crescente estes
valores, guardando-os num vetor. Ordene o valor assim que ele for digitado. Mostre ao final
os valores em ordem. */
void entrada(float v[]);
void saida(float v[]);
int main(){
    float v[TAMANHO];
    setlocale(LC_ALL, "");

    entrada(v);
    saida(v);

    return 0;
}
void entrada(float v[]){
    int leitura;
    for(int i = 0; i < TAMANHO; i++){
        float n;
        do{
            printf("Entre com índice %d:\n", i+1);
            leitura = scanf("%f", &v[i]);
            while(getchar() != '\n');
            if(leitura != 1){
                printf("Caractere inválido!\n");
            }
        }while(leitura != 1);
        for(int j = i; j > 0; j--){
            if(v[j] <= v[j - 1]){
                n = v[j - 1];
                v[j - 1] = v[j];
                v[j] = n;
            }
        }
    }
    system("clear");
}

void saida(float v[]){
    for(int i = 0; i < TAMANHO; i++){
        printf("%f\n", v[i]);
    }
}
