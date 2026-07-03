#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* 9. Faça um programa que receba o preço de um produto e o seu código de orígem e imprima
a sua procedência. A procedência obedece a seguinte tabela:
Código Procedência
1 Sul
2 Norte
3 Leste
4 Oeste
5 ou 6 Nordeste
7.8 ou 9 Sudeste
10 até 20 Centro-Oeste
21 até 30 Nordeste */

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

int main(){
    int codigo;
    setlocale(LC_ALL,"");

    printf("Entre com o código do produto: \n");
    ler_int(&codigo);

    if(codigo == 1)
        printf("Procedência:    Sul\n");
    else if(codigo == 2)
        printf("Procedência:    Norte\n");
    else if(codigo == 3)
        printf("Procedência:    Leste\n");
    else if(codigo == 4)
        printf("Procedência:    Oeste\n");
    else if(codigo == 5 || codigo == 6)
        printf("Procedência:    Nordeste\n");
    else if(codigo >= 7 && codigo <= 9)
        printf("Procedência:    Sudeste\n");
    else if(codigo >= 10 && codigo <= 20)
        printf("Procedência:    Centro-oeste\n");
    else if(codigo > 20 && codigo <= 30)
        printf("Procedência:    Nordeste\n");
    else
        printf("Procedência:    indeterminada\n");
    return 0;
}
