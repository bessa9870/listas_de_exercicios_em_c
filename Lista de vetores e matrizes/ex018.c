#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define tamanho 5

/* 18. Faça um programa que leia dez conjuntos de dois valores, o primeiro representando o
número do aluno e o segundo representando a sua altura em metros. Encontre o aluno mais
baixo e o mais alto. Mostre o número do aluno mais baixo e do mais alto, juntamente com
suaas alturas */

void limpar_buffer();
void ler_float(float *p);
void ler_int(int *p);
void ler_vet(int *p1, int *maior1, int *menor1, float *p2, float *maior2, float *menor2, int tam);
int main(){
    int vet1[tamanho], maior1, menor1;
    float vet2[tamanho], maior2, menor2;
    setlocale(LC_ALL,"");

    ler_vet(vet1, &maior1, &menor1, vet2, &maior2, &menor2, tamanho);
    printf("O mais alto:\nNúmero\t%d\nAltura\t%.2f",maior1,maior2);
    puts("----------------------------------");
    printf("\nO mais baixo:\nNúmero\t%d\nAltura\t%.2f",menor1,menor2);

    return 0;
}

void limpar_buffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void ler_float(float*p){
    int leitura;
    do{
        leitura = scanf("%f", p);
        limpar_buffer();
        if(leitura != 1){
            printf("Entrada inválida\n");
        }
    }while(leitura != 1);
}

void ler_int(int*p){
    int leitura;
    do{
        leitura = scanf("%d", p);
        limpar_buffer();
        if(leitura != 1){
            printf("Entrada inválida\n");
        }
    }while(leitura != 1);
}

void ler_vet(int *p1, int *maior1, int *menor1, float *p2, float *maior2, float *menor2, int tam){
    for(int i = 0; i < tam; i++){
        printf("Dados do aluno %d\n\n",i+1);
        printf("Número da aluno: ");
        ler_int(p1+i);
        printf("Altura em metros: ");
        ler_float(p2+i);
        puts("----------------------------------");
        if(i == 0){
            *maior1 = *p1;
            *menor1 = *p1;
            *maior2 = *p2;
            *menor2 = *p2;
        }else{
            if(p2[i] > *maior2){   //Se a altura for maior
                *maior2 = p2[i];   //Guarda a altura
                *maior1 = p1[i];   //Guarda o número
            }else{
            if(p2[i] <= *menor2){
            *menor2 = p2[i];
            *menor1 = p1[i];
            }
        }
    }
    system("clear");
}
