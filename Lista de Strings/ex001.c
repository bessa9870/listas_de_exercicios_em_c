#include <stdio.h>

/* 1. Exibir na tela os caracteres da tabela de códigos ASCII (American Standard Code for Information
Interchange). */

void tabela();

int main(){
    tabela();

    return 0;
}

void tabela(){
    for(int i = 32; i < 127; i++){
        printf("%c ",i);
    }
}
