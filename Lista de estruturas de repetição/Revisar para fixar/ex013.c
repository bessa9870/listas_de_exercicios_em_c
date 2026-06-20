#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*13. Fazer um programa para achar a série de Bergamacci dos n primeiros termos: 1 1 1 1 3 5
9 17 ... */

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
    int proximo_termo=0, termo_anterior=1, termo_ante_anterior=1, termo_ante_ante_anterior=1;
    for(int i = 0; i < n; i++){
        if(i < 4)
            printf("1 ");
        else{
            proximo_termo = termo_anterior + termo_ante_anterior + termo_ante_ante_anterior;
            termo_ante_ante_anterior = termo_ante_anterior;
            termo_ante_anterior= termo_anterior;
            termo_anterior = proximo_termo;
            printf("%d ",termo_anterior);
        }
    }
    puts("");
}
