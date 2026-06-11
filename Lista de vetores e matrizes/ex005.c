#include <stdio.h>
#include <locale.h>
/*Faça um programa para ler a nota da prova de 15 alunos e calcule e imprima a média geral.
Obs.: Tente fazer o programa usando funções, usando uma função para ler as notas e outra
para calcular a média. */

void lerVet(float vet[], int tam, float *acumulador);    //Não preciso usar * porque o nome + [] já aponta para o primeiro índice
float calcular(float acumulador, int tam);
void imprimirVet(float vet[], int tam, float media);

int main(){
    int tam = 5;
    float vet[tam];
    float acumulador = 0.0;
    float media = 0.0;
    setlocale(LC_ALL, "");

    printf("Use vírgula [ , ] para separar décimos\n");
    lerVet(vet, tam, &acumulador);   ////Não preciso usar & porque o nome + [] já aponta para o primeiro índice

    media = calcular(acumulador, tam);

    imprimirVet(vet, tam, media);

    return 0;
}
void lerVet(float vet[], int tam, float *acumulador){    //Não preciso usar * porque o nome + [] já aponta para o primeiro índice
    int leitura;
    for(int i = 0; i < tam; i++){
        do{
            printf("Entre a nota final do aluno %d\n", i + 1);
            leitura = scanf("%f", &vet[i]);
            if(leitura != 1){
                printf("\nNota inválida\n");
                while(getchar() != '\n');    //Limpa o buffer, não me pergunte como, só aceite.
            }else if(vet[i] < 0.0 || vet[i] > 10.0){
                printf("\nNota inálida\n");
            }
        }while(vet[i] < 0.0 || vet[i] > 10.0 || leitura != 1);
        *acumulador = *acumulador + vet[i];
//O laço vai se repetir enquanto vet[i] for menor que zero OU maior que 10 Ou não for um número
    }
}

float calcular(float acumulador, int tam){
    float media = acumulador / tam;
    return media;
}

void imprimirVet(float vet[], int tam, float media){
    for(int i = 0; i < tam; i++){
        printf("Nota aluno %d:\n%.2f\n", i + 1, vet[i]);
    }
    printf("A média geral é %.2f", media);
}
