#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int opcao;
    int soma_1, soma_2, resultado = 0;
    int rodando = 1;
    double num, raiz = 0;
    setlocale(LC_ALL, "");

    for(;rodando == 1;){

        printf("Pressione Enter");
        system("clear");
        getchar();

        printf("==================MENU==================");
        puts("");

        printf("1. Somar\n2. Raiz quadrada\n3. Sair\n");
        printf("Digite uma opcao:\n");
        scanf("%d", &opcao);

        switch(opcao){

            case 1:
                printf("==================SOMA==================\n");
                printf("Entre com um numero:\n");
                scanf("%d", &soma_1);

                printf("Entre com outro numero:\n");
                scanf("%d", &soma_2);

                resultado = soma_1 + soma_2;
                printf("Resultado da soma: %d", resultado);
                puts("\n");
                break;

            case 2:
                printf("==================RAIZ QUADRADA==================\n");
                printf("Entre com um numero:\n");
                scanf("%lf", &num);
                raiz = sqrt(num);

                printf("A raiz desse numero e: %lf\n", raiz);
                break;

            case 3:
                rodando = 0;
                break;

            default:
                printf("Inválido!\n");
        }
    }

    return 0;
}
