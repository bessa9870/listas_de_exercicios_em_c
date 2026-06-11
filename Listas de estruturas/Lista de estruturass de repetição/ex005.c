#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define IDADE 5

/*5. Fazer um programa que leia 20 idades de pessoas. Calcule e
escreva a idade média deste grupo. */
void lervet(int v[], float *media);
int main(){
    int pessoas[IDADE];
    float media = 0.0;

    printf("Calculando a idade média:\n");
    lervet(pessoas, &media);

    printf("\nPressione enter para continuar.");
    while(getchar() != '\n');
    system("clear");

    printf("A média das %d idades é %.2f", IDADE, media / IDADE);

    return 0;
}
void lervet(int v[], float *media){
    int leitura;
    for(int i = 0; i < IDADE; i++){
        do{
            printf("%dº idade:\n", i+1);
            leitura = scanf("%d", &v[i]);
            while(getchar() != '\n');
            if(leitura != 1){
                printf("Inválda\n");
            }else if(v[i] < 0){
                printf("Idada inválida!\n");
            }
        }while(leitura != 1 || v[i] < 0);
        *media = *media + v[i];
    }
}
