#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*4) Faça um programa que receba a idade de uma pessoa e imprima mensagem de maioridade
ou não.*/

void ler_int(int*p){
    scanf("%d",p);
}

void calc(int v);

int main(){
    int idade;
    setlocale(LC_ALL,"");
    ler_int(&idade);
    calc(idade);

    return 0;
}

void calc(int v){
    if(v >= 0 && v < 18)
        printf("Menor de idad.e");
    else if(v >= 18 && v <= 120)
        printf("Maior de idade.");
    else
        printf("Idade inválida.");
    puts("");
}
