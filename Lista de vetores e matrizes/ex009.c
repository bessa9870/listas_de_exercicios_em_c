#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/* Faça um programa que leia um vetor de cinco posições para números reais e, depois, um
código inteiro. Se o código for zero, finalize o programa; se for 1, mostre o vetor na ordem
direta; se for 2, mostre o vetor na ordem inversa. Caso, o código for diferente de 1 e 2
escreva uma mensagem falando que o código é inválido. */

void lerVet(float vet[5]);
void menu(int *opcao, float vet[]);

int main(){
    float vet[5];
    int opcao;
    setlocale(LC_ALL, "");

    lerVet(vet);

    system("clear");
    menu(&opcao, vet);


    return 0;
}

void lerVet(float vet[5]){
    int leitura;
    for(int i = 0; i < 5; i++){
        do{
            printf("Entre com índice %d:\n", i + 1);
            leitura = scanf("%f", &vet[i]);
            if(leitura != 1){
                printf("Inválido\n");
                while(getchar() != '\n');
            }
        }while(leitura != 1);
    }
    puts("");
}
void menu(int *opcao, float vet[5]){
    do{
        printf("--------------------------------------------------------\n");
        printf("\tOopções de saída\n\n1. Vetor da esquerda à direita.\n2. Vetor da direita à esquerda.\n0. Para sair.\n\nDigite a opção:");
        scanf("%d", opcao);     //Vai deixar um \n no buffer
        switch(*opcao){
            case 0:
                system("clear");
                printf("\nPrograma encerrado.");
                break;
            case 1:
                puts("");
                for(int i = 0; i < 5; i++){
                    printf("[%.2f] ", vet[i]);
                }
                puts("");
                printf("Presssione Enter para continuar");
                while (getchar() != '\n');  //Vai limpar o buffer do primeiro scanf;
                while (getchar() != '\n');
                system("clear");
                break;
            case 2:
                puts("");
                for(int i = 4; i > (0 - 1); i--){
                    printf("[%.2f] ", vet[i]);
                }
                puts("");
                printf("Presssione Enter para continuar");
                while (getchar() != '\n');  //Vai limpar o buffer
                while (getchar() != '\n');;
                system("clear");
                break;
            default:
                printf("Inválido!\n");
                while(getchar() != '\n');
                break;
        }
    }while(*opcao != 0);
}
