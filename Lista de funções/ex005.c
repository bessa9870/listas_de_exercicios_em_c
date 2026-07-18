#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define tam_vet 100

#define RESET       "\x1b[0m"
#define VERMELHO    "\x1b[31m"
#define VERDE       "\x1b[32m"
#define AMARELO     "\x1b[33m"
#define CIANO       "\033[36m"

/* 5. Construa uma função que, a partir de um vetor de 100 inteiros, possibilite:
 a digitação dos valores no vetor;
 imprimir o valor do somatório de seus itens;
 imprimir a média dos valores fornecidos;
 substituir por zero todos os valores negativos;
 substituir por zero todos os valores repetidos (maiores que zero);
 Criar um menu para acessar os itens anteriores */

void ler_int(int *p);
void limpar_buffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}
void ler_vet(int *p);
void menu(int *p);
void somatorio(int *p);
void media(int *p);
void negativo(int *p);
void repeticao(int *p);

int main(){
    int vet[tam_vet];
    setlocale(LC_ALL,"");

    ler_vet(vet);
    menu(vet);

    return 0;
}

void ler_int(int *p){
    int leitura;
    do{
        leitura = scanf("%d", p);
        limpar_buffer();
        if(leitura != 1){
            printf("%sCaractere inválido detectado!%s\n",VERMELHO,RESET);
        }
    }while(leitura != 1);
}

void ler_vet(int *p){
    for(int i = 0; i < tam_vet; i++){
        printf("%sPreencha o índice %d:%s ",CIANO,i+1,RESET);
        ler_int(&p[i]);
    }
    printf("\n\n%sPressione %sEnter%s para continuar%s\n",CIANO,VERDE,CIANO,RESET);
    limpar_buffer();
    system("clear");
}

void menu(int *p){
    int opcao;
    do{
        printf("%sMENU DE OPÇÕES%s\n",VERDE,RESET);
        printf("%s1.Imprimir somatório\n",CIANO);
        printf("2.Imprimir média\n");
        printf("3.Substituir por zero todos os valores negativos\n");
        printf("4.Substituir por zero todos os valores repetidos (maiores que zero)\n%s",RESET);
        printf("%s5.Sair%s\n\n",VERMELHO,RESET);

        printf("%sDigite o número da opção desejada: %s",VERDE,RESET);
        ler_int(&opcao);
        system("clear");
        switch(opcao){
            case 1:
                printf("%s1.Imprimir somatório%s\n\n",CIANO,RESET);
                somatorio(p);
                break;
            case 2:
                printf("%s2.Imprimir média%s\n\n",CIANO,RESET);
                media(p);
                break;
            case 3:
                printf("%s3.Substituir por zero todos os valores negativos%s\n\n",CIANO,RESET);
                negativo(p);
                break;
            case 4:
                printf("%s4.Substituir por zero todos os valores repetidos (maiores que zero)\n\n%s",CIANO,RESET);
                repeticao(p);
                break;
            case 5:
                printf("%sPrograma encerrado.%s",VERDE,RESET);
                break;
            default:
                printf("%sEssa opção não existe.%s",VERMELHO,RESET);
                printf("\n\n%sPressione %sEnter%s para continuar%s\n",CIANO,VERDE,CIANO,RESET);
                limpar_buffer();
                system("clear");
                break;
        }
    }while(opcao != 5);
}

void somatorio(int *p){
    int acumulador=0;
    for(int i = 0; i < tam_vet; i++){
        acumulador = acumulador + p[i];
    }
    printf("%sO somatório do vetor é de %d%s\n",AMARELO,acumulador,RESET);
    printf("\n\n%sPressione %sEnter%s para continuar%s\n",CIANO,VERDE,CIANO,RESET);
    limpar_buffer();
    system("clear");
}

void media(int *p){
    int acumulador=0;
    float media=0;
    for(int i = 0; i < tam_vet; i++){
        acumulador = acumulador + p[i];
    }
    media = (float)acumulador / tam_vet;
    printf("%sA média do vetor é de %.1f%s\n",AMARELO,media,RESET);
    printf("\n\n%sPressione %sEnter%s para continuar%s\n",CIANO,VERDE,CIANO,RESET);
    limpar_buffer();
    system("clear");
}

void negativo(int *p){
    int contador=0;
    for(int i = 0; i < tam_vet; i++){
        if(p[i] >= 0)
            continue;
        else{
            p[i] = 0;
            contador++;
        }
    }
    if(contador == 0)
        printf("%sNenhum valor negativo para substituir%s\n",VERMELHO,RESET);
    else{
        printf("%sNovo vetor:%s\n",VERDE,RESET);
        for(int i = 0; i < tam_vet; i++){
            printf("%d ",p[i]);
        }
    }
    printf("\n\n%sPressione %sEnter%s para continuar%s\n",CIANO,VERDE,CIANO,RESET);
    limpar_buffer();
    system("clear");
}

void repeticao(int *p){
    int contador=0;
    for(int i = 0; i < tam_vet; i++){ //Pega um elemento
        if(p[i] == 0)
            continue;
        else{
            for(int j = i+1; j < tam_vet; j++){ //Olha pra frente
                if(p[j] == p[i]){ //Se algum da frente for igual ao de trás
                    p[j] = 0;
                    contador++;
                }
            }
        }
    }
    if(contador == 0)
        printf("%sNenhum repetição para substituir%s\n",VERMELHO,RESET);
    else{
        printf("%sNovo vetor:%s\n",VERDE,RESET);
        for(int i = 0; i < tam_vet; i++){
            printf("%d ",p[i]);
        }
    }
    printf("\n\n%sPressione %sEnter%s para continuar%s\n",CIANO,VERDE,CIANO,RESET);
    limpar_buffer();
    system("clear");
}
