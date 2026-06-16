#include <stdio.h>
#include <stdlib.h>

typedef struct Ponto{
    int y,x;
}Ponto;

void ler_int(int *p);

void quadrado(Ponto v1,Ponto v2,Ponto v3);
int main(){
    Ponto v1,v2,v3;

    //Vértice inferior esquerda.
    v1.x=0;
    v1.y=0;
    //Vértice superior direita.
    v2.x=5;
    v2.y=5;
    //Lendo o ponto.
    printf("Entre com o eixo x(horizontal):\n");
    ler_int(&v3.x);
    printf("Entre com o eixo y(vertical):\n");
    ler_int(&v3.y);
    //Verificando sse o ponto está dentro do retângulo.
    quadrado(v1,v2,v3);
}
void ler_int(int *p){
    int leitura;
    do{
        leitura = scanf("%d",p);
        int c;
        while((c = getchar()) != '\n' && c != EOF);
    }while(leitura != 1);
}
void quadrado(Ponto v1,Ponto v2,Ponto v3){
    if(v3.x >= v1.x && v3.x <= v2.x && v3.y >= v1.y && v3.y <= v2.y)
        printf("O ponto está DENTRO do retângulo.\n");
    else
        printf("O ponto está FORA do retângulo.\n");

    printf("\n\nPressione ENTER para encerrar.");
    while(getchar() != '\n');
    return;
}

