#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>

/*5) Faça um programa que calcule e imprima o salário reajustado de um funcionário de acordo
com a seguinte regra:
• salários até 300, reajuste de 50%;
• salários maiores que 300, reajuste de 30%.*/

void ler_float(float*p){
    int leitura;
    do{
        leitura=scanf("%f",p);
    }while(*p <= 0 || leitura != 1);
    system("clear");
}

bool calc(float v);

int main(){
    float salario;
    setlocale(LC_ALL,"");
    ler_float(&salario);
    bool v=calc(salario);
    if(v==true)
        printf("Vocẽ tem direito ao reajuste de +50%%\n\nSeu novo salário com o reajuste agora é R$ %.2f",salario*1.5);
    else
        printf("Vocẽ tem direito ao reajuste de +30%%\n\nSeu novo salário com o reajuste agora é R$ %.2f\n\n",salario*1.3);
    return 0;
}

bool calc(float v){
    printf("Seu salário inserido: R$ %.2f\n\n",v);
    if(v <= 300)
        return true;
    else
        return false;
}

