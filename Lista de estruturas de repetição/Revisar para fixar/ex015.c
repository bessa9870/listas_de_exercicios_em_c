#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*15. A série de Fetuccine difere da série de Ricci porque o termo de posição par é resultado da
subtração dos dois anteriores. Os termos ímpares continuam sendo o resultado da soma dos
dois elementos anteriores. Imprima os n primeiros termos da série de Fetuccine. */

void calc(int n1,int n2,int n3);
void ler(int *v);
int main(){
    int n1, t1, t2;
    setlocale(LC_ALL, "");

    printf("Quantos termos quer ver?\n>");
    ler(&n1);
    printf("Entre com o primeiro termo:\n>");
    ler(&t1);
    printf("Entre com o segundo termo:\n>");
    ler(&t2);


    calc(n1,t1,t2);

    return 0;
}
void ler(int *v){
    scanf("%d",v);
}
void calc(int n1,int n2,int n3){
    puts("");
    int aux;
    for(int i = 0; i < n1; i++){
        printf("%d ",n2);
        if(i % 2 == 0){
            aux = n2 + n3;
        }else{
            aux = n3 - n2;
        }
            n2 = n3;
            n3 = aux;
    }
}
