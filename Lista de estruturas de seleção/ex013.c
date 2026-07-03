#include <stdio.h>
#include <locale.h>

/* 13. Faça um programa que receba a idade de uma pessoa e classifique-a seguindo o critério
a seguir:
idade Classificação
0 a 2 anos Recém-nascido
3 a 11 anos criança
12 a 19 anos adolescente
20 a 55 anos adulto
Acima de 55 anos idoso */

void ler_int(int *p);

void classificacao(int *p);

int main(){
    int idade;
    setlocale(LC_ALL,"");

    printf("Entre com uma idade:\n");
    ler_int(&idade);
    classificacao(&idade);

    return 0;
}

void ler_int(int *p){
    int leitura;
    do{
        leitura=scanf("%d",p);
        int c;
        while((c = getchar()) != '\n' && c != EOF);
        if(leitura != 1 || *p < 0)
            printf("Entrada inválida\n");
    }while(leitura != 1 || *p < 0);
}

void classificacao(int *p){
    if(*p <= 2)
        printf("Recém-nascido\n");
    else if(*p <= 11)
        printf("Criança\n");
    else if(*p <= 19)
        printf("Adolescente\n");    //Não tem pré-adolescente?
    else if(*p <= 55)
        printf("Adulto\n");
    else if(*p <= 120)
        printf("Idoso\n");
    else        //Colocar uma armadilha para caçar vampiras
        printf("Vampiro\n");
}
