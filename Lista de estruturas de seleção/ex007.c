#include <stdio.h>
#include <locale.h>

/* 7. Faça um programa que receba a idade de um nadador e imprima a sua categoria seguindo
as regras:
categoria idade
infantil A 5 – 7 anos
infantil B 8 – 10 anos
juvenil A 11 – 13 anos
juvenil B 14 – 17 anos
sênior maiores de 18 anos */

void ler_int(int *idade){
    int leitura;
    do{
        printf("Entre com a idade: ");
        leitura=scanf("%d",idade);
        while(getchar() != '\n');
        if(leitura != 1 || *idade < 0)
            printf("Entrada inválida\n");
    }while(leitura != 1 || *idade < 0);
}

void categoria(int idade);

int main(){
    int idade;
    setlocale(LC_ALL,"");

    ler_int(&idade);
    categoria(idade);


    return 0;
}

void categoria(int idade){
    if(idade >= 5 && idade <= 7)
        printf("Infantil A\n");
    else if(idade >= 8 && idade <= 10)
        printf("Infantil B\n");
    else if(idade >= 11 && idade <= 13)
        printf("Juvenil A\n");
    else if(idade >= 14 && idade <= 17)
        printf("Juvenil B\n");
    else if(idade >= 18 && idade <= 50)
        printf("Sênior\n");
    else
        printf("Sem categoria");
}
