#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*11. Fazer um algoritmo para achar o fatorial de um número N */

int fat(int n);

int main(){
    int n, r;
    setlocale(LC_ALL, "");

    printf("Entre com n!\n>");
    scanf("%d",&n);

    r = fat(n);

    printf("%d\n",r);

    return 0;
}
int fat(int n){
    int acumulador=1;
    system("clear");
    for(int i = 1; i <= n; i++){
        acumulador = acumulador*i;
    }
    printf("O fatorial de %d é: ",n);
    return acumulador;
}
