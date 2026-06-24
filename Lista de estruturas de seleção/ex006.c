#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

/*6) Faça um programa que receba a altura e o sexo de uma pessoa, calcule e imprima o seu
peso ideal, utilizando as seguintes fórmulas:
• para homens: (72.7 * H) - 58;
• para mulheres: (62.1 * H) – 44.7*/

bool ler_char(char *p);

void ler_altura(float *p){
    printf("Entre com sua altura (1,50, 1,60, 1,70...):\n>");
    scanf("%f",p);
    puts("");
}

float calc(bool v1, float v2);

int main(){
    char sexo;
    float altura;
    setlocale(LC_ALL,"");

    bool s=ler_char(&sexo);
    ler_altura(&altura);
    float peso=calc(s,altura);
    if(s == true)
        printf("Seu peso de mulher ideal é de %.1fKg\n",peso);
    else
        printf("Seu peso de homem ideal é de %.1fKg\n",peso);


    return 0;
}

bool ler_char(char *p){
    do{
        printf("Entre com seu sexo(M ou H)\n>");
        scanf(" %c",p);
        int aux;
        while((aux = getchar()) != '\n' && aux != EOF);
    }while((*p != 'm' && *p != 'M') && (*p != 'h' && *p != 'H'));
    puts("");
    if(*p == 'm' || *p == 'M')
        return true;
    else if(*p == 'h' || *p == 'H')
        return false;
}

float calc(bool v1, float v2){
    float aux;
    if(v1 == false)
        return aux = (72.7 * v2) - 58;
    else
        return aux = (62.1 * v2) - 44.7;
}
