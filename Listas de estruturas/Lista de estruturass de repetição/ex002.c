#include <stdio.h>
#include <locale.h>

/*Exibir o produto dos números inteiros positivos
 no intervalo de um a cem*/

 int main(){
    double n = 1;
    setlocale(LC_ALL, "");

    printf("Somatório dos números positivos inteiros de 1 a 100:\n");

    for(int i = 1; i <= 100; i++){
        n = n * i;
    }

    printf("%e\n", n);
    return 0;
 }
