#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*1) Faça um programa que receba quatro notas de um aluno, calcule e imprima a média aritmética
das notas e a mensagem de aprovado para média superior ou igual a 7.0 ou a mensagem de
reprovado para média inferior a 7.0*/

float ler_float(float*p){
    scanf("%f",p);
    while(getchar() != '\n');
}

float calc(float *p, int tam);

float situacao(float v);

int main(){
    float notas[4], media=0.0;
    setlocale(LC_ALL,"");
    printf("Use vírgula.\n\n");
    printf("A média do aluno é: %.1f\n",media=calc(notas,4));
    situacao(media);

    return 0;
}

float calc(float *p, int tam){
    float acumulador=0;
    for(int i = 0; i < tam; i++){
        do{
            printf("Entre com a nota %d: ",i+1);
            ler_float(p+i);
            if(*(p+i)< 0 || *(p+i) > 10)
                printf("Nota inválida.\n");
            else
                acumulador = acumulador + *(p+i);
        }while(*(p+i) < 0 || *(p+i) > 10);
    }
    puts("");
    return acumulador/tam;
}

float situacao(float v){
    if(v >=0 && v< 7)
        printf("Reprovado.\n");
    else
        printf("Aprovado.\n");
}
