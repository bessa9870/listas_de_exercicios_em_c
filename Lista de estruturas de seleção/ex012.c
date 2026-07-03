#include <stdio.h>
#include <locale.h>

/* 12. Faça um programa que receba três notas de um aluno, calcule e imprima a média
aritmética entre essas três notas e uma mensagem que segue a tabela abaixo:
Média Mensagem
0.0 |__ 5.0 reprovado
5.0 |__ 7.0 exame
7.0 |__| 10.0 aprovado */

void ler_float(float *p){
    int leitura;
    do{
        leitura=scanf("%f",p);
        int c;
        while((c = getchar()) != '\n' && c != EOF);
        if(leitura != 1)
            printf("Entrada inválida\n");
    }while(leitura != 1);
}

void situacao(float *p);

int main(){
    float notas[3], media=0.0;
    setlocale(LC_ALL,"");

    for(int i = 0; i < 3; i++){
        printf("Entre com a nota %d:\n",i+1);
        ler_float((notas + i));
        media = media + notas[i];
    }
    media=media/3;

    situacao(&media);

    return 0;
}

void situacao(float *p){
    if(*p >= 0.0 && *p < 5.0)
        printf("Média       %.1f\nSituação:       Reprovado",*p);
    else if(*p >= 5.0 && *p < 7.0)
        printf("Média       %.1f\nSituação:       Exame",*p);
    else if(*p >= 7.0 && *p <= 10.0)
        printf("Média       %.1f\nSituação:       Aprovado",*p);
    else
        printf("Média       %.1f\nSituação:       Indeterminada",*p);
}
