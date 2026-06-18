#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>

 /*10. Construa um algoritmo que leia um número inteiro N e imprima o mesmo na ordem inversa:
exemplo: dado 23457, a saída será 75432. */

void calc(int n);

int main(){
    int n1=102457;
    printf("Use vírgula.\n\n");
    setlocale(LC_ALL, "");

    printf("Número antes da inversão: %d\n\nNúmero depois da inversão: ",n1);
    calc(n1);

    return 0;
}

void calc(int n){
    int aux;
    do{
        aux=n % 10;
        n = n /10;
        printf("%d",aux);
    }while(n != 0);
    puts("");
}
