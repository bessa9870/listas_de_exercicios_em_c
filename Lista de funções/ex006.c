#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

/* 6. Construa uma função que verifique se um dado número é divisível por outro. Ambos devem ser
fornecidos pelo usuário */

void ler_int(int *p);
bool divisao(int *p1, int *p2);

int main(){
    int n1, n2;
    setlocale(LC_ALL,"");

    printf("Entre com o dividendo: ");
    ler_int(&n1);
    do{
        printf("Entre com o divisor: ");
        ler_int(&n2);
        if(n2 == 0)
            printf("Não existe divisão por zero. Tente novamente.\n");
    }while(n2 == 0);

    bool div=divisao(&n1,&n2);

    puts("");
    if(div == true)
        printf("%d é divisível por %d,",n1,n2);
    else
        printf("%d é não divisível por %d,",n1,n2);

    return 0;
}

void ler_int(int *p){
    int leitura;
    do{
        leitura = scanf("%d", p);
        while(getchar()!= '\n');
        if(leitura != 1){
            printf("Entrada inválida\n");
        }
    }while(leitura != 1);
}

bool divisao(int *p1, int *p2){
    if(*p1 % *p2 == 0)
        return true;
    else
        return false;
}

