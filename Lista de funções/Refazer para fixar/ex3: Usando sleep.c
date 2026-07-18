#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <unistd.h> //biblioteca do sleep

/*3. Crie um aplicativo que faça a contagem regressiva de um número inteiro informado pelo usuário. O
usuário deve informar também o espaço de tempo entre cada contagem (em segundos). Controle o
tempo com um método tempo() contido em outra classe. Crie uma nova função para esse método do
tempo() ou aproveite do exemplo 3. */

void ler(int *n);
void contagem(int *n1, int *n2);
void tempo(int *n);

int main(){
    int n1, n2;

    printf("Entre com o número para contagem regressiva.\n");
    ler(&n1);

    printf("Entre com o intervalo em segundos.\n");
    ler(&n2);
    printf("Iniciando contagem...\n");
    sleep(1);

    system("clear");

    printf("Contagem regressiva(Não digite nada)\n");
    contagem(&n1,&n2);

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

void contagem(int *n1, int *n2){
    for(int i = *n1; i >= 0; i--){
        printf("%d\n",i);
        tempo(n2);
    }
    printf("\nFim da contagem.\n");
}

void tempo(int *n){
    sleep(*n);
}
