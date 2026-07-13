#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

/* 8. Crie uma função que recebe uma string e um caractere, e apague todas as ocorrências desses
caractere na string */

void f(char *s1, char s2);

int main(){
    char string[50], ca;
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
    puts("");

    f(string,ca);

    printf("Frase sem a letra %c:\n",ca);
    puts(string);

    return 0;

}

void f(char *s1, char s2){
    int j=0;
    for(int i = 0; s1[i] != '\0'; i++){
        if(s1[i] != s2){
            s1[j] = s1[i];
            j++;
        }
    }
    s1[j] = '\0';
}
