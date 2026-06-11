#include <stdio.h>
#include <locale.h>
/*Leia um vetor de 10 posições. Contar
e escrever quantos valores pares ele possui. */

int main(){
    int tam = 10;
    int vet[tam];
    int acumulador = 0;
    setlocale(LC_ALL, "");

    for(int i = 0; i < tam; i++){
        printf("Entre com n %d:\n", i + 1);
        scanf("%d", &vet[i]);
        if(vet[i] % 2 == 0){
            acumulador++;
        }
    }
    printf("Temos %d números pares nesse array", acumulador);

    return 0;
}
