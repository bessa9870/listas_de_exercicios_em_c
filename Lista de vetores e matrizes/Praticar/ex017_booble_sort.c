#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define tamanho 10

/* 17. Peça ao usuário para digitar dez valores numéricos e ordene por ordem crescente estes
valores, guardando-os num vetor. Ordene o valor assim que ele for digitado. Mostre ao final
os valores em ordem. */

void ler_int(int *p);
void limpar_buffer();
void ler_vet(int *p, int tam);
void imprimir_vet(int *p, int tam);

int main(){
    int vetor[tamanho];
    setlocale(LC_ALL,"");

    ler_vet(vetor, tamanho);
    imprimir_vet(vetor, tamanho);

    return 0;
}

void imprimir_vet(int *p, int tam){
    for(int i = 0; i < tam; i++){
        printf("%d\n",*(p+i));
    }
}

void ler_vet(int *p, int tam){
    for(int i = 0; i < tam; i++){
        printf("Índice %d: ",i+1);
        ler_int(p+i);
        printf("%d\n",p[i]);
            for(int j = 0; j < i; j++){
                int aux=0;
                if(p[i] < p[j]){
                    aux = p[j];
                    p[j] = p[i];
                    p[i] = aux;
                }
            }
    }
    system("clear");
}

void limpar_buffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void ler_int(int *p){
    int leitura;
    do{
        leitura = scanf("%d", p);
        limpar_buffer();
        if(leitura != 1){
            printf("Entrada inválida\n");
        }
    }while(leitura != 1);
}
