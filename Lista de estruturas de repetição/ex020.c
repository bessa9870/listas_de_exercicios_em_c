#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>

/*20. Construa um algoritmo que faça a conversão de um número que está na base decimal para
a base binária*/

int ler(int *p){
    printf(">");
    scanf("%d",p);
    return *p;
}

void calc(int n);

int main(){
    int n;
    setlocale(LC_ALL,"");

    ler(&n);
    calc(n);

    return 0;
}

void calc(int n){
    int resto[32],i=0;
    while(n != 0){
        resto[i] = n%2;
        n=n/2;
        i++;
    }
    while(i != 0){
        printf("%d ",resto[i-1]);
        i--;
    }
}
