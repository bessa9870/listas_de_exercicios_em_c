#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/* 6. Construa uma estrutura aluno com nome, numero de matrıcula e curso. Leia do usuário
a informação de 5 alunos, armazene em vetor dessa estrutura e imprima os dados na
tela. */

typedef struct{
    char nome[50];
    int id;
    char nome_do_curso[50];
}Alunos;

void ler_struct(Alunos *ptr, int tam);
void limpar_buffer();
void ler_string(char string[], int tam);
void ler_int(int *ptr);
void imprimir_struct(Alunos *aluno, int tam);

int main(){
    Alunos aluno[5];
    setlocale(LC_ALL,"");

    ler_struct(aluno,5);
    imprimir_struct(aluno,5);

    return 0;
}

void ler_struct(Alunos *ptr, int tam){
    for(int i = 0; i < tam; i++){
        printf("Aluno %d\n\n",i+1);
        printf("Nome: ");
        ler_string((ptr + i)->nome,50);
        printf("ID: ");
        ler_int(&(ptr+i)->id);
        printf("Nome do curso: ");
        ler_string(ptr[i].nome_do_curso,50);
        system("clear");
    }
}

void ler_string(char string[], int tam){
    fgets(string,tam,stdin);
    size_t len = strlen(string);
    if(string[len-1]=='\n')
        string[len-1] = '\0';
    else
        limpar_buffer();
}

void ler_int(int *ptr){
    int leitura;
    do{
        leitura=scanf("%d",ptr);
        limpar_buffer();
        if(leitura != 1)
            printf("Inválido, tente novamente.\n");
    }while(leitura != 1);
}

void limpar_buffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void imprimir_struct(Alunos *aluno, int tam){
    for(int i = 0; i < tam; i++){
        printf("---------------------------\nAluno %d\n\n",i+1);
        printf("Nome:           %s\n",aluno[i].nome);
        printf("ID:             %d\n",aluno[i].id);
        printf("Nome do curso:  %s\n",aluno[i].nome_do_curso);
    }
}
