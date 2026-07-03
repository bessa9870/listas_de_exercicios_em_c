#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

/* 10. Faça um programa que receba um número, verifique se este número é par ou ímpar e
imprima a mensagem. */

void ler_int(int *p){
    int leitura;
    do{
        leitura=scanf("%d",p);
        int c;
        while((c = getchar()) != '\n' && c != EOF);
        if(leitura != 1)
            printf("Entrada inválida\n");
    }while(leitura != 1);
}

bool verificar(int *n);

int main(){
    int n;
    setlocale(LC_ALL,"");

    printf("Entre com um númmero qualquer:\n");
    ler_int(&n);

    bool v=verificar(&n);

    if(v == true)
        printf("O número é par\n");
    else
        printf("O número é impar\n");

    return 0;
}

bool verificar(int *n){
    if(*n % 2 == 0)
        return true;
    else
        return false;
}
