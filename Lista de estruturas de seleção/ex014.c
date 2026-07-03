#include <stdio.h>
#include <locale.h>

/* 14. Faça um programa que receba o código correspondente ao cargo de um funcionário e
imprima seu cargo e o percentual de aumento ao qual este funcionário tem direito seguindo
a tabela:
Código Cargo Percentual
1 Escriturário 50,00%
2 Secretário 35,00%
3 Caixa 20,00%
4 Gerente 10,00%
5 Diretor Não tem aumento */

void ler_int(int *p);

void percentual(int *p);

int main(){
    int cod;
    setlocale(LC_ALL,"");

    printf("Entre com o código do seu cargo:\n");
    ler_int(&cod);
    percentual(&cod);

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

void percentual(int *p){
    switch(*p){
        case 1:
            printf("Seu cargo:\Escriturário\nAumento:\t50,00%%");
            break;
        case 2:
            printf("Seu cargo:\tSecretário\nAumento:\t35,00%%");
            break;
        case 3:
            printf("Seu cargo:\tCaixa\nAumento:\t20,00%%");
            break;
        case 4:
            printf("Seu cargo:\tGerente\nAumento:\t10,00%%");
            break;
        case 5:
            printf("Seu cargo:\tDiretor\nAumento:\tSem aumento");
            break;
        default:
            printf("Código indefinido.\n");
            break;
    }
}
