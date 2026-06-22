#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>

/*17. Fazer um algoritmo para verificar se um número lido é número perfeito. Número perfeito é
aquele que é igual a soma dos seus divisores. Por exemplo: 6 = 1 + 2 + 3*/

int ler(int *p){
    scanf("%d",p);
    return *p;
}

void calc(int v);

int main(){
    int v;
    setlocale(LC_ALL,"");
    setlocale(LC_ALL,"");
    ler(&v);
    calc(v);
    return 0;
}

void calc(int v){
    int acumulador=0;
    for(int i = 1; i < v; i++){
        if(v % i == 0){
            acumulador = acumulador + i;
            if(acumulador > v)
                break;
        }
    }
    if(acumulador == v)
        printf("%d é um número perfeito",v);
    else
        printf("%d não é um número perfeito.",v);
}
