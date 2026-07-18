#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

/* 4. Crie um método chamado aleatório que sorteie uma determinada quantidade de números de acordo
com um argumento. O usuário deve informar a quantidade de números a ser gerada e a faixa de
números válidos para o sorteio, por exemplo: se o usuário informar os argumentos 4 e 100
(aleatório(4,100)), devem ser gerados quatro números aleatórios entre 1 e 100. */

void ler_int(int *n);
void aleatorio(int *n1, int *n2, int *n3);

int main(){
    int n1, n2, n3;
    setlocale(LC_ALL,"");

    srand(time(NULL));
    printf("Escolha o intervalo do número que deseja: (ex: de 1 até 100)\n");
    printf("de:\n");
    ler_int(&n1);
    printf("até:\n");
    ler_int(&n2);

    printf("Quantos números você quer gerar?\n");
    ler_int(&n3);

    aleatorio(&n1,&n2,&n3);

    return 0;
}

void ler_int(int *n){
    int leitura;
    do{
        leitura = scanf("%d", n);
        while(getchar() != '\n');
        if(leitura != 1){
            printf("Caractere inválido detectado!\n");
        }
    }while(leitura != 1);
    puts("");
}

void aleatorio(int *n1, int *n2, int *n3){
    for(int i = 0; i < *n3; i++){
        printf("%d ",((rand() % (*n2 - *n1 + 1)) + *n1));
//Não sei o que é esse tanto de parenteses, só decore.
    }
}
