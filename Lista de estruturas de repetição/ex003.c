#include <stdio.h>

/*3. Elaborar um programa que apresente no final o somatório dos valores pares existentes entre
1 e 500 */

int main(){
    int cont=0;

    for(int i = 0; i < 501; i++){
        if(i > 0 && i % 2 == 0)
            cont = cont + i;
    }
    printf("O somário dos valores pares entre 0 a 500 e %d", cont);

    return 0;
}
