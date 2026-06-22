#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/* 19. O número 3025 possui a seguinte característica:
30 + 25 = 55
552 = 3025
Fazer um algoritmo que pesquise e imprima todos os números de quatro dígitos que
apresentam tal característica.*/

void calc();

int main(){
    setlocale(LC_ALL,"");

    calc();

    return 0;
}

void calc(){
    int frente=0,costa=0,soma;
    for(int i = 1000; i <= 9999; i++){
        frente = i/100;
        costa = i%100;
        soma = frente+costa;
        if(soma * soma == i)
            printf("%d\n",i);
    }
}
