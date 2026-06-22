#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>
/*16. Fazer um algoritmo para verificar se um número lido é primo ou não. Número primo é aquele
que é divisível por 1 e por ele mesmo*/

int ler(int *p);
void calc(int p);

int main(){
    int n;
    setlocale(LC_ALL,"");

    printf("Digite um número:\n>");
    ler(&n);
    calc(n);

    return 0;
}

int ler(int *p){
    do{
        scanf("%d",p);
        if(*p == 0)
            printf("Entre com um número a partir de 1.\n");
    }while(*p == 0);
    return *p;
}

void calc(int p){
    int  contador=0;
    for(int i = 1; i <= p; i++){
        if(p >0 && p % i == 0){
            contador++;
            if(contador>2)
                break;
        }
    }
    if(contador==2)
        printf("%d é primo.",p);
    else
        printf("%d não é primo.",p);
}
