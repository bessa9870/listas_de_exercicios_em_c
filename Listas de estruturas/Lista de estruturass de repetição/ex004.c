#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*Entrar com dois valores via teclado, onde o segundo deverá ser maior que o primeiro. Caso
contrário solicitar novamente apenas o segundo valor. */

int main(){
    int v1, v2;
    setlocale(LC_ALL, "");

    printf("Entre com dois valores, o segundo sendo maior que o primeiro\n\n\nPressione Enter para começar");
    while(getchar() != '\n');
    system("clear");

    int leitura;
    do{
        printf("Entre com o valor 1:\n");
        leitura = scanf("%d", &v1);
        while(getchar() != '\n');
        if(leitura != 1){
            printf("Valor inválido!. Pressione Enter para continuar\n");
            while(getchar() != '\n');
            system("clear");
        }
    }while(leitura != 1);

    int leitura2;
    do{
        printf("Entre com o valor 2:\n");
        leitura2 = scanf("%d", &v2);
        while(getchar() != '\n');
        if(leitura2 != 1){
            printf("Valor inválido!\n");
        }else if(v2 <= v1){
            printf("Entre com um valor maior que o anterior\n");
        }
    }while(leitura2 != 1 || v2 <= v1);

    printf("Fim");

    return 0;
}
