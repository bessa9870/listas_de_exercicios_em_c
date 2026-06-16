#include <stdio.h>

/*
2. Exibir o produto dos números inteiros positivos no intervalo de um a cem
*/

int main(){
    long long int acumulador=1;
    for(int i = 1; i <= 100; i++){
        acumulador = acumulador * i;
    }
    printf("%e",acumulador);
    return 0;
}
