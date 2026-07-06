#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

#define _tipo 20
#define baralho 52
#define mao 5

/* 11. Escolha um jogo de cartas, baseado em um ”baralho tradicional” ( cada carta tem seu
naipe e seu valor) ou tipo ”super trunfo” ( cada carta possui um conjunto de atributos) .
Implemente a parte de distribuição ( sorteio) de cartas para 2 jogadores, considerando
que cada jogador ira receber 5 cartas. Exiba na tela as cartas que cada um dos
jogadores recebeu */

typedef struct{
    char tipo[_tipo];
    int numero;
    int sorteada;
}Carta;

void baralho_completo(Carta *cartas, int tam);

int main(){
    Carta cartas[baralho], p1[mao], p2[mao];
    setlocale(LC_ALL,"");

    srand(time(NULL));

    baralho_completo(cartas,baralho);

    for(int i = 0; i < mao; i++){
        int indice;
        do{
            indice = rand() % baralho;
        }while(cartas[indice].sorteada == 1);
        p1[i] = cartas[indice];
        cartas[indice].sorteada = 1;
    }

        for(int i = 0; i < mao; i++){
        int indice;
        do{
            indice = rand() % baralho;
        }while(cartas[indice].sorteada == 1);
        p2[i] = cartas[indice];
        cartas[indice].sorteada = 1;
    }

    printf("Mão do jogador 1:\tMão do jogador 2:\n\n");
    for(int i = 0; i < mao; i++){
        printf("%d de %s\t\t",p1[i].numero,p1[i].tipo);
        printf("%d de %s\n",p2[i].numero,p2[i].tipo);
    }

    return 0;
}

void baralho_completo(Carta *cartas, int tam){
    char naipes[4][10] = {"Copas", "Ouros", "Espadas", "Paus"}; //4 palavras de 9 letras
    int k = 0; // Contador para andar de 0 a 51 no vetor de cartas
    for(int i = 0; i < 4; i++) { // Passa pelos 4 naipes
        for(int j = 1; j <= 13; j++) { // Passa pelos 13 números
            strcpy(cartas[k].tipo, naipes[i]);
            cartas[k].numero = j;
            cartas[k].sorteada = 0;
            k++; // Avança para a próxima posição do baralho
        }
    }
}
