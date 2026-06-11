#include <stdio.h>
#include <locale.h>

/*Faça um programa que receba uma frase, conte
e imprima o número de palavras desta frase. */

int main(){
    int tamanho = 100;
    char string[tamanho];
    int sentinela = 0;
    int contador = 0;
    setlocale(LC_ALL, "");

    printf("Entre com uma frase:\n");
    fgets(string, sizeof(string), stdin);

    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] == ' ' || string[i] == '\t' || string[i] == '\n'){
            if(sentinela == 1){
                sentinela = 0;
                contador++;
            }
        }else{
                sentinela = 1;  //Evita que ele conte não-letra
        }
    }

    printf("\nSua frase:\n");
    puts(string);
    printf("Temos %d palavras nessa frase", contador);

    return 0;
}
