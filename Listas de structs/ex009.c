#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define tamanho_nome 31

/* 9. Faça um programa que armazene em um registro de dados (estrutura composta) os
dados de um funcionário de uma empresa, compostos de : Nome, Idade, Sexo (M/F ) ,
CPF, Data de Nascimento, Código do Setor onde trabalha ( 0 - 99 ) , Cargo que ocupa
( string de ate 30 caracteres) e Salario. Os dados devem ser digitados pelo usuário,
armazenados na estrutura e exibidos na tela. */

typedef struct{
    int dia, mes, ano;
}Nascimento;

typedef struct{
    char nome[tamanho_nome];
    int idade;
    char sexo;
    unsigned long long int cpf;
    Nascimento nascimento;
    int codigo;
    char cargo[tamanho_nome];
    float salario;
}Funcionario;

void limpar_buffer();
void ler_int(int *ptr);
void ler_float(float *ptr);
void ler_string(char *s, int tam);
void ler_char(char *ptr);
void ler_cpf(long long int *ptr);
void ler_struct(Funcionario *ptr);
void imprimir_struct(Funcionario *ptr);

int main(){
    Funcionario funcionario, *ptr = &funcionario;
    setlocale(LC_ALL,"");

    ler_struct(ptr);
    imprimir_struct(ptr);

    return 0;
}

void limpar_buffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void ler_int(int *ptr){
    int leitura;
    do{
        leitura=scanf("%d",ptr);
        limpar_buffer();
        if(leitura != 1 || *ptr < 0)
            printf("Entrada inválida, tente novamente.\n");
    }while(leitura != 1 || *ptr < 0);
}

void ler_float(float *ptr){
    int leitura;
    do{
        leitura=scanf("%f",ptr);
        limpar_buffer();
        if(leitura != 1 || *ptr < 0)
            printf("Entrada inválida, tente novamente.\n");
    }while(leitura != 1 || *ptr < 0);
}

void ler_string(char *s, int tam){
    fgets(s,tam,stdin);
    size_t len = strlen(s);
    if(s[len-1] == '\n')
        s[len-1] = '\0';
    else
        limpar_buffer();
}

void ler_char(char *ptr){
    int leitura;
    do{
        leitura=scanf("%c",ptr);
        limpar_buffer();
        if(leitura != 1 || *ptr != 'M' && *ptr != 'F' && *ptr != 'm' && *ptr != 'f')
            printf("Entrada inválida, tente novamente.\n");
    }while(leitura != 1 || *ptr != 'M' && *ptr != 'F' && *ptr != 'm' && *ptr != 'f');
}

void ler_cpf(long long int *ptr){
    int leitura;
    do{
        leitura=scanf("%llu",ptr);
        limpar_buffer();
        if(leitura != 1)
            printf("Entrada inválida, tente novamente.\n");
    }while(leitura != 1);
}

void ler_struct(Funcionario *ptr){
    printf("Dados de funcionário\n\n");
    printf("Nome: ");
    ler_string(ptr->nome,tamanho_nome);
    printf("Idade: ");
    ler_int(&ptr->idade);
    printf("Sexo: ");
    ler_char(&ptr->sexo);
    printf("CPF(apenas números): ");
    ler_cpf(&ptr->cpf);
    printf("Data de nascimento\n Dia: ");
    ler_int(&ptr->nascimento.dia);
    printf(" Mês: ");
    ler_int(&ptr->nascimento.mes);
    printf(" Amo: ");
    ler_int(&ptr->nascimento.ano);
    printf("Código: ");
    ler_int(&ptr->codigo);
    printf("Cargo: ");
    ler_string(ptr->cargo,tamanho_nome);
    printf("Salário(ex:R$ 1000,00): R$");
    ler_float(&ptr->salario);
    system("clear");
}

void imprimir_struct(Funcionario *ptr){
    printf("Dados de funcionário\n\n");
    printf("Nome:                   %s\n",ptr->nome);
    printf("Idade:                  %d\n",ptr->idade);
    printf("Sexo:                   %c\n",ptr->sexo);
    printf("CPF(apenas números):    %llu\n",ptr->cpf);
    printf("Data de nascimento:     %d/%d/%d\n",ptr->nascimento.dia,ptr->nascimento.mes,ptr->nascimento.ano);
    printf("Código:                 %d\n",ptr->codigo);
    printf("Cargo:                  %s\n",ptr->cargo);
    printf("Salário:                R$%.2f\n",ptr->salario);
}
