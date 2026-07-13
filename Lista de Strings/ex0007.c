#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

/* 7. Crie uma função que recebe uma string e um caractere, e retorne o número de vezes que esse
caractere aparece na string */

int f(char *s1, char s2);

int main(){
    char string[50], ca;
    int cont;
    setlocale(LC_ALL,"");

    printf("Digite uma frase: ");
    fgets(string,50,stdin);
    size_t len = strlen(string);
    if(string[len-1] == '\n')
        string[len-1] = '\0';
    else
        while(getchar() != '\n');

    printf("Digite uma letra: ");
    scanf("%c",&ca);

    system("clear");

    cont=f(string,ca);

    printf("O caracter %c apareceu %d vezes na frase:\n%s",ca,cont,string);
}

int f(char *s1, char s2){
    int contador=0;
    for(int i = 0; s1[i] != '\0'; i++){
        if(*(s1+i) == s2)
            contador++;
    }
    return contador;
}
