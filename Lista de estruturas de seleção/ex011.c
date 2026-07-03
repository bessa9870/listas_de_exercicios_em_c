#include <stdio.h>
#include <locale.h>

/* 11. Faça um programa que receba dois números e imprima o menor dos dois. */

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

int funcao(int *p1, int *p2){
    if(*p1 < *p2)
        return *p1;
    else
        return *p2;
}

int main(){
    int p1,p2,*ptr1=&p1,*ptr2=&p2,menor;

    printf("Entre com um número qualquer:\n");
    ler_int(ptr1);
    printf("Entre com um número qualquer:\n");
    ler_int(ptr2);

    menor=funcao(ptr1, ptr2);

    printf("O menor é %d",menor);

    return 0;
}
