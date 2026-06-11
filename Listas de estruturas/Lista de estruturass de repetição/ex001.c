#include <stdio.h>
#include <locale.h>

/*1. Exibir a soma dos números positivos no intervalo
 de um a cem */

int main(){
    int soma = 0;
    setlocale(LC_ALL, "");

    printf("Soma dos números inteiros de 1 a 100:\n");

    for(int i = 1; i <= 100; i++){
        soma = soma + i;
    }

    printf("%d", soma);

    return 0;
}
