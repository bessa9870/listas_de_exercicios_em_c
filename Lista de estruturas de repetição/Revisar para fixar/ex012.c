#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*12. Fazer um programa para achar a série de Fibonacci dos n primeiros termos: 1 1 2 3 5 8... */

void fib(int n);

int main(){
    int n;
    setlocale(LC_ALL, "");

    printf("Quantos termos quer ver?\n>");
    scanf("%d",&n);

    fib(n);

    return 0;
}

void fib(int n){
    system("clear");
    int proximo_termo=0, termo_anterior=1, termo_anteanterior=0;
    for(int i = 0; i < n; i++){
        printf("%d ",termo_anterior);

        proximo_termo = termo_anterior + termo_anteanterior;
        termo_anteanterior = termo_anterior;
        termo_anterior = proximo_termo;
    }
    puts("");
}
