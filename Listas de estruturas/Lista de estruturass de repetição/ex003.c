#include <stdio.h>
#include <locale.h>

/*laborar um programa que apresente no final o somatório dos
valores pares existentes entre 1 e 500. */

int main(){
    int n = 0;
    setlocale(LC_ALL, "");
    printf("Somatório dos números pares de 1 a 500:\n");

    for(int i = 1; i <= 500; i++){
        if(i % 2 == 0){
            n = n + i;
        }
    }

    printf("%d", n);
    return 0;
}
