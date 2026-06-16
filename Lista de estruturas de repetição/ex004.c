#include <stdio.h>

/* 4. Entrar com dois valores via teclado, onde o segundo deverá ser maior que o primeiro. Caso
contrário solicitar novamente apenas o segundo valor*/

void valor(int *v1, int *v2);

int main(){
    int v1, v2;

    valor(&v1, &v2);

    return 0;
}
void valor(int *v1, int *v2){
    printf("Entre com o primeiro valor:\n");
    scanf("%d", v1);
    do{
        printf("Entre com o segundo valor:\n");
        scanf("%d", v2);
        if(*v2 <= *v1)
            printf("O segundo valor deve ser maior que o primeiro!\n");
    }while(*v2 <= *v1);
    printf("Perfeito!");
}
