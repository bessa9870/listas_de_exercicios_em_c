#include <stdio.h>
#include <locale.h>

#define RESET       "\x1b[0m"
#define AMARELO     "\x1b[33m"

/* 7. Faça uma função que possibilite o arredondamento de um número real para um número inteiro
seguindo os padrões científicos. */

void ler_float(float *p);
void arredondar(float *p);

int main(){
    float n;
    setlocale(LC_ALL,"");
    printf("\t%sUSE VIRGULA.%s\n",AMARELO,RESET);

    printf("Vamos arredondar um número real.\n");
    printf("Digite um número real qualquer:\n");
    ler_float(&n);

    printf("\nNúmero arredondado: ");
    arredondar(&n);

    return 0;
}

void ler_float(float *p){
    int leitura;
    do{
        leitura = scanf("%f", p);
        while(getchar()!= '\n');
        if(leitura != 1){
            printf("Entrada inválida\n");
        }
    }while(leitura != 1);
}

void arredondar(float *p){
    int aux1 = *p;
    float aux2 = *p - aux1;

    if(aux2 > 0.5){
        aux1 = aux1 + 1;
        *p = aux1;
        printf("%.1f",*p);
    }else if(aux2 < 0.5){
        *p = *p - aux2;
        printf("%.1f",*p);
    }
    puts("");
}
