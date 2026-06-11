#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define TAMANHO 10

/*16. Faça um programa para ler 10 números DIFERENTES a serem armazenados em um vetor.
Os dados deverão ser armazenados no vetor na ordem que forem sendo lidos, sendo que
caso o usuário digite um número que já foi digitado anteriormente, o programa deverá pedir
para ele digitar outro número. Note que cada valor digitado pelo usuário deve ser pesquisado
no vetor, verificando se ele existe entre os números que já foram fornecidos. Exibir na tela o
vetor final que foi digitado. */

void leitura(int v[]);
void saida(int v[]);

int main(){
    int v[TAMANHO];
    setlocale(LC_ALL, "");

    leitura(v);

    saida(v);


    return 0;
}
void leitura(int v[]){
    for(int i = 0; i < TAMANHO; i++){
       int leitura = 0; //Fora do bloco do~while, vartável de escopo ecterno
       int n; //Fora do bloco do~while, vartável de escopo externo

        do{ //Bloco aninhado, escopo interno do bloco for
            n = 0;
            printf("Entre com índice %d:\n", i+1);
            leitura = scanf("%d", &v[i]);
            while(getchar() != '\n');
            if(leitura != 1){  //Se for um caractere inválido
                printf("Entrada inválida!\n");
            }else{  //Se for um número repetido
                for(int j = 0; j < i; j++){
                    if(v[j] == v[i]){
                        n = 1;
                        printf("Número repetido! Entrada inválida!\n");
                        break;
                    }
                }
            }
        }while(leitura != 1 || n != 0);
    }
    system("clear");
}

void saida(int v[]){
    puts("Vetor:\n");
    for(int i = 0; i < TAMANHO; i++){
        printf("%d\n", v[i]);
    }
}
