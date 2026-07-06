#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/* 16) Uma companhia de seguros tem três categorias de seguros baseadas na idade e na
ocupação do segurado. Somente pessoas com pelo menos 18 anos e não mais de 70 anos
podem adquirir apólices de seguros. Quanto às classes de ocupações foram definidos três
grupos de risco. A tabela a seguir fornece as categorias em função da caixa de idade e do
grupo de risco:
idade
Grupo de risco
          Baixo Médio Alto
18 a 24     7     8     9
25 a 40     4     5     6
41 a 70     1     2     3
Faça um programa que receba a idade e o grupo de risco (b, m ou a) e
determine e imprima o código do seguro */

void limpar_buffer();
void ler_int(int *p);
void ler_char(char *p);
void risco(int *p1, char *p2);

int main(){
    int idade;
    char grupo;
    setlocale(LC_ALL,"");

    printf("Entre com uma idade: ");
    ler_int(&idade);
    printf("Grupo de risco: ");
    ler_char(&grupo);
    risco(&idade,&grupo);

    return 0;
}

void limpar_buffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void ler_int(int *p){
    int leitura;
    do{
        leitura=scanf("%d",p);
        limpar_buffer();
        if(*p < 0 || leitura!= 1)
            printf("Entrada inválida.\n");
    }while(*p < 0 || leitura != 1);
}

void ler_char(char *p){
    int leitura;
    do{
        leitura=scanf("%c",p);
        limpar_buffer();
        if(leitura != 1 || (*p != 'A' && *p != 'a' && *p != 'M' && *p != 'm' && *p != 'B' && *p != 'b'))
            printf("Entrada inválida.\n");
    }while(leitura != 1 || (*p != 'A' && *p != 'a' && *p != 'M' && *p != 'm' && *p != 'B' && *p != 'b'));
    system("clear");
}

void risco(int *p1, char *p2){
    if(*p1 < 18 || *p1 > 70){
        printf("Sem seguro.\n");
        return;
    }

    if(*p2 == 'a' || *p2 == 'A'){
        printf("Grupo de risco:\tAlto\n");
        if(*p1 <= 24)
            printf("Código:\t9");
        else if(*p1 <= 40)
            printf("Código:\t6");
        else if(*p1 <= 70)
            printf("Código:\t3");
    }else if(*p2 == 'm' || *p2 == 'M'){
        printf("Grupo de risco:\tMédio\n");
        if(*p1 <= 24)
            printf("Código:\t8");
        else if(*p1 <= 40)
            printf("Código:\t5");
        else if(*p1 <= 70)
            printf("Código:\t2");
    }else if(*p2 == 'b' || *p2 == 'B'){
        printf("Grupo de risco:\tBaixo\n");
        if(*p1 <= 24)
            printf("Código:\t7");
        else if(*p1 <= 40)
            printf("Código:\t4");
        else if(*p1 <= 70)
            printf("Código:\t1");
    }

}
