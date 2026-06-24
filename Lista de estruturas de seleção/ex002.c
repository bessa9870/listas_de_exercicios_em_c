#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*2) Uma empresa decide dar um aumento de 30% aos funcionários cujo salário é inferiora 500
reais. Escreva um programa que receba o salário de um funcionário e imprima o valor do
salário reajustado ou uma mensagem caso o funcionário não tenha direito ao aumento. */

void ler_float(float*p){
    scanf("%f",p);
}

void calc(float *p);

int main(){
    float salario;
    setlocale(LC_ALL,"");
    calc(&salario);

    return 0;
}

void calc(float *p){
    printf("Entre com o valor do seu salário: \nR$");
    ler_float(p);
    puts("");
    if(*p < 500){
        printf("Você tem direito ao reajuste de salário.\n");
        *p = *p * 1.3;
        printf("Seu novo salário agora é: R$%.2f\n",*p);
    }else{
        printf("Você não tem direito ao reajuste de salário.\n");
    }
}
