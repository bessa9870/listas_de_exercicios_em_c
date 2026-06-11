#include <stdio.h>
#include <locale.h>
/*Leia um vetor de 10 posições e atribua valor 0
 para todos os elementos que possuírem
valores negativos. */

int main(){
    int tam = 10;
    int vet[tam];
    setlocale(LC_ALL, "");

    for(int i = 0; i < tam; i++){
        printf("Entre com n %d\n", i + 1);
        scanf("%d", &vet[i]);
        if(vet[i] < 0){
            vet[i] = 0;
        }
    }

    for(int i = 0; i < tam; i++){
        printf("[%d] ", vet[i]);
    }

    return 0;
}
