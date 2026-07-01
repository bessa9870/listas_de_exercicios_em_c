#include <locale.h>
#define LEN 100

/*1. Construa uma declaração de struct em C
que possa acomodar dados provenientes de
uma tabela conforme o exemplo a seguir: */

struct endereco{
    char rua[LEN];
    int numero_casa;
    char bairro[LEN];
    char complemento[LEN];
    char cep[10];    //char por causa do -.
    char cidade[LEN];
    char uf[3];
};

struct cadastro{
    char nome[LEN];
    struct endereco info_local;
    char fone1[3][14];
};


int main(){


    return 0;
}

