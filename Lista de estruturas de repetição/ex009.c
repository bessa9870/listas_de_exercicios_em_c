#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAMANHO 50
/*9. Fazer um programa que leia a nota final de 50 alunos e escreva o total de aprovados. É
considerado aprovado o aluno com nota final maior ou igual a 6. */

int notas(int tam);

int main(){
    setlocale(LC_ALL, "");
    printf("Use vírgula.\n\n");

    int aprovados=notas(TAMANHO);

    printf("%d alunos foram aprovados.",aprovados);

    return 0;
}

int notas(int tam){
    float n;
    int contador=0;
    for(int i = 0; i < tam; i++){
        do{
            printf("Entre com a nota final de aluno %d:\n",i+1);
            scanf("%f",&n);
            while(getchar()!='\n');
            if(n < 0 || n > 10)
                printf("Entre com notas entre 0 a 10.\n");
        }while(n < 0 || n > 10);
        if(n >= 0 && n < 6)
            printf("Aluno reprovado.\n");
        else if(n >= 6 && n <= 10){
            printf("Aluno aprovado.\n");
            contador++;
        }
    }
    system("clear");
    return contador;
}
