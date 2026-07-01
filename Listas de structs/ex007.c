#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define tamanho 5

/* 7. Crie uma estrutura representando os alunos do curso de Introdução a Programação de
Computadores. A estrutura deve conter a matrıcula do aluno, nome, nota da primeira
prova, nota da segunda prova e nota da terceira prova.
(a) Permita ao usuário entrar com os dados de 5 alunos.
(b) Encontre o aluno com maior nota da primeira prova.
(c) Encontre o aluno com maior media geral.
(d) Encontre o aluno com menor media geral
(e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para
aprovação. */

typedef struct{
    char nome[51];
    int id;
    float notas[3];
    float media;
}Alunos;

void limpar_buffer();
void ler_string(char string[], int tam);
void ler_int(int *ptr);
void ler_float(float *ptr);

void ler_struct(Alunos *ptr, int tam);
void imprimir_struct(Alunos *aluno, int tam);

int main(){
    Alunos aluno[tamanho];
    setlocale(LC_ALL,"");

    ler_struct(aluno,tamanho);
    imprimir_struct(aluno,tamanho);

    return 0;
}

void limpar_buffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
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

void ler_float(float *ptr){
    int leitura;
    do{
        leitura=scanf("%f",ptr);
        limpar_buffer();
        if(leitura != 1)
            printf("Inválido, tente novamente.\n");
    }while(leitura != 1);
}

void ler_struct(Alunos *ptr, int tam){
    for(int i = 0; i < tam; i++){
        float acumulador=0;
        printf("\tAluno %d\n",i+1);
        printf("Nome: ");
        ler_string((ptr + i)->nome,51);
        printf("ID: ");
        ler_int(&(ptr + i)->id);
        do{
            for(int j = 0; j < 3; j++){
            printf("%dº nota: ",j+1);
            ler_float(&(ptr + i)->notas[j]);
            acumulador = acumulador + (ptr + i)->notas[j];
            }
            ptr[i].media = acumulador/3;
            if(ptr[i].media < 0 || ptr[i].media > 10){
                printf("Média inválida, tente novamente.\n");
                acumulador=0.0;
            }
        }while(ptr[i].media < 0 || ptr[i].media > 10);
        system("clear");
    }
}

void imprimir_struct(Alunos *aluno, int tam){
    float maior=0, menor=10, maior_nota=0;
    int contador =0;
    for(int i = 0; i < tam; i++){
        printf("---------------------------\nAluno %d\n\n",i+1);
        printf("Nome:           %s\n",aluno[i].nome);
        printf("ID:             %d\n",aluno[i].id);
        for(int j = 0; j < 3; j++){
            printf("1º nota:        %.1f\n",aluno[i].notas[j]);
        }
        printf("Média:          %.1f\n",aluno[i].media);
        if(aluno[i].media < 6.0)
            printf("Status:         Reprovado.\n\n");
        else{
            printf("Status:         Aprovado.\n\n");
        }
        contador++;
    }
    if(contador == 1)
        printf("Só um aluno foi adicionado.\n");
    else{
        int guardar;
        for(int i = 0; i < tam; i++){
            if(*(aluno[i].notas) >= maior_nota){
                maior_nota = *(aluno[i].notas);
                guardar = i;
            }
        }
        printf("A maior primeira nota foi %.1f do aluno %d\n",maior_nota,guardar+1);

        int guardar2;
        for(int i = 0; i < tam; i++){
            if(aluno[i].media >= maior){
                maior = aluno[i].media;
                guardar2 = i;
            }
        }
        printf("A maior média foi %.1f do aluno %d\n",maior,guardar2+1);

        int guardar3;
        for(int i = 0; i < tam; i++){
            if(aluno[i].media <= menor){
                menor = aluno[i].media;
                guardar3 = i;
            }
        }
        printf("A menor média foi %.1f do aluno %d\n",menor,guardar3+1);
    }
}
