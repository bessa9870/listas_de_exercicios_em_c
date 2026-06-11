#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*3. Crie um aplicativo que faça a contagem regressiva de um número inteiro informado pelo usuário. O
usuário deve informar também o espaço de tempo entre cada contagem (em segundos). Controle o
tempo com um método tempo() contido em outra classe. Crie uma nova função para esse método do
tempo() ou aproveite do exemplo 3. */

void ler(int *n);

int main(){
    int n1, n2;

    printf("Entre com o número para contagem regressiva.\n");
    ler(&n1);

    system("clear");

    printf("Entre com o intervalo em segundos.\n");
    ler(&n2);

    return 0;
}

void ler(int *n){
    int leitura;
    do{
        printf("Digite aqui:\n");
        leitura = scanf("%d", n);
        while(getchar() != '\n');
        if(leitura != 1){
            printf("Caractere inválido detectado!\n");
        }
    }while(leitura != 1);

    puts("");
}
