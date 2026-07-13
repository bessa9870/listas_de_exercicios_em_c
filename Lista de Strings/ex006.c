#include <stdio.h>
#include <ctype.h>
#include <locale.h>

/* 6. Crie uma função que transforma todos os caracteres de uma string em minúsculos. */

void f(char *p){
    int i =0;
    while(p[i] != '\0'){
        p[i] = tolower(p[i]);
        i++;
    }
}
int main(){
    char s[] = "TEXTO DE EXEMPLO";
    f(s);
    printf("%s",s);

    return 0;
}
