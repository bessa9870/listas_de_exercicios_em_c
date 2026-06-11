#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

/*1. Crie um aplicativo que receba o raio de uma esfera (do tipo double) e chame o método volumeEsfera
para calcular e exibir o volume da esfera na tela. Para cálculo do volume deve ser usada a fórmula:
volume = (4.0/3.0)*pi*raio2.*/

double ler(double n);
void volumeEsfera(double n);

int main(){
    double n;
    setlocale(LC_ALL, "");

    //Entrada
    n = ler(n);

    //Saída
    volumeEsfera(n);
    return 0;
}

double ler(double n){
    printf("Vamos calcular o volume de uma esfera usando o raio\n");
    int leitura;
    do{
        printf("Entre com o raio:\n");
        leitura = scanf("%lf", &n);
        while(getchar() != '\n');
        if(leitura != 1){
            printf("Entrada inválida!\n");
        }
    }while(leitura != 1);
    puts("");
    return n;
}

void volumeEsfera(double n){
    double pi = 3.141592653589793;
    double n2 = (4.0 / 3.0) * pi * pow(n, 2);

    printf("O volume da esfera é: %.2lf", n2);
}
