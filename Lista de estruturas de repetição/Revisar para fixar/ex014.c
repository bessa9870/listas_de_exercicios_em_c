#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*14. A série de Ricci difere da série de Fibonacci porque os dois primeiros termos podem ser
definidos pelo usuário. Imprima os n primeiros termos da série de Ricci. */

void calc(int n1, int n2, int n3);
void ler(int *v);
int main(){
    int n1, n2, n3;
    setlocale(LC_ALL, "");

    printf("Quantos termos quer?\n>");
    ler(&n3);
    printf("Entre com primeiro termo:\n");
    ler(&n1);
    printf("Entre com segundo termo:\n");
    ler(&n2);

    calc(n1,n2,n3);

    return 0;
}

void ler(int *v){
    scanf("%d",v);
}
void calc(int n1, int n2, int n3){
    int aux;
    system("clear");
    for(int i =0; i < n3; i++){
        printf("%d ",n1);
        aux = n1 + n2;
        n1 = n2;
        n2 = aux;
    }
}
