#include <stdio.h>

//Desafio 02 — strlen próprio

size_t meu_strlen(const char *s);

int main(){
    char s[]="Minha string.";

    printf("%zu sem contar o indice do \\0", meu_strlen(s));

    return 0;
}

size_t meu_strlen(const char *s){
    const char *l = s;
    while(*s != '\0'){
        s++;
    }
    return s-l;
}

//Tmbm não gostei, prefiro o strlen padrão
