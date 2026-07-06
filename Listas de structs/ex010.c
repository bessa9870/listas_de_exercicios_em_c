#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define _nome 50
#define vetor 10

/* 10. Faça um programa que leia os dados de 10 alunos (Nome, matricula, Media Final) ,
armazenando em um vetor. Uma vez lidos os dados, divida estes dados em 2 novos
vetores, o vetor dos aprovados e o vetor dos reprovados, considerando a media mínima
para a aprovação como sendo 5.0. Exibir na tela os dados do vetor de aprovados,
seguido dos dados do vetor de reprovados. */

typedef struct{
    char nome[_nome];
    int matricula;
    float nota_final;
}Alunos;

void limpar_buffer();
void ler_int(int *p);
void ler_float(float *p);
void ler_string(char string[], int tam);
void ler_struct(Alunos *alunos, int tam);
void situacao(Alunos *alunos, Alunos *aprovados, Alunos *reprovados, int tam, int *j, int *k);
void imprimir_struct(Alunos *aprovados, Alunos *reprovados, int *j, int *k);

int main(){
    Alunos alunos[vetor];
    Alunos aprovados[vetor],reprovados[vetor];
    int j=0, k=0;
    setlocale(LC_ALL,"");

    ler_struct(alunos,vetor);
    situacao(alunos,aprovados,reprovados,vetor,&j,&k);
    imprimir_struct(aprovados,reprovados,&j,&k);

    return 0;
}

void limpar_buffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void ler_int(int *p){
    int leitura;
    do{
        leitura=scanf("%d",p);
        limpar_buffer();
        if(leitura != 1)
            printf("Entrada inválida\n");
    }while(leitura != 1);
}

void ler_float(float *p){
    int leitura;
    do{
        leitura=scanf("%f",p);
        limpar_buffer();
        if(leitura != 1 || *p < 0 || *p > 10)
            printf("Entrada inválida\n");
    }while(leitura != 1 || *p < 0 || *p > 10);
}

void ler_string(char string[], int tam){
    fgets(string,tam,stdin);
    size_t len = strlen(string);
    if(string[len-1] == '\n')
        string[len-1] = '\0';
    else
        limpar_buffer();
}

void ler_struct(Alunos *alunos, int tam){
    for(int i = 0; i < tam; i++){
        printf("Aluno %d:\n\n",i+1);
        printf("Nome: ");
        ler_string((alunos+i)->nome,_nome);
        printf("ID de matricula: ");
        ler_int(&(alunos+i)->matricula);
        printf("Nota final: ");
        ler_float(&(alunos+i)->nota_final);
        system("clear");
    }
}

void situacao(Alunos *alunos, Alunos *aprovados, Alunos *reprovados, int tam, int *j, int *k){
    for(int i = 0; i < tam; i++){
        if((alunos+i)->nota_final >= 5){
            aprovados[*j] = *(alunos+i);
            (*j)++;
        }else{
            reprovados[*k] = *(alunos+i);
            (*k)++;
        }
    }
}

void imprimir_struct(Alunos *aprovados, Alunos *reprovados, int *j, int *k){
    printf("Alunos aprovados\n\n-----------------------\n");
    for(int i = 0; i < *j; i++){
        printf("Nome:   %s\n",aprovados[i].nome);
        printf("ID:     %d\n",aprovados[i].matricula);
        printf("Média:  %.1f",aprovados[i].nota_final);
        printf("\n-----------------------\n");
    }
    printf("\nAlunos reprovados\n\n-----------------------\n");
    for(int i = 0; i < *k; i++){
        printf("Nome:   %s\n",reprovados[i].nome);
        printf("ID:     %d\n",reprovados[i].matricula);
        printf("Média:  %.1f",reprovados[i].nota_final);
        printf("\n-----------------------\n");
    }
}
