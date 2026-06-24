#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

/*3) Faça um programa que verifique a validade de uma senha fornecida pelo usuário. A senha é
um conjunto de caracteres que são: 'ASDFG'. O programa deve imprimir mensagem de
permissão ou negação de acesso.*/
void comparar_senha(char p[], int tam);

void ler_char(char string[], int tamanho);

int main(){
    char senha[6];
    setlocale(LC_ALL,"");
    comparar_senha(senha,6);
    return 0;
}

void ler_char(char string[], int tamanho){
    size_t len2;
    printf("Entre com sua senha\n>");
    do{
        fgets(string,tamanho,stdin);
        size_t len = strlen(string);
        len2 = len;
        if(len > 0 && string[len - 1] == '\n')
            string[len - 1] = '\0';
        else{
            int c;
            while((c = getchar()) != '\n' && c != EOF);
        }
    }while(len2 == 0);
}


void comparar_senha(char p[], int tam){
    char senha[6] = "ASDFG";
    do{
        system("clear");
        ler_char(p,6);
        if(strcmp(p,senha) == 0){
            printf("Acesso autorizado.\n");
        }else{
            printf("Acesso negado\n\nPressione Enter.");
            int c;
            while((c = getchar()) != '\n' && c != EOF);
        }
    }while(strcmp(p,senha) != 0);
}
