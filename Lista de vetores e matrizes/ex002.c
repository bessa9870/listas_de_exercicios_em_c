#include <stdio.h>
#include <locale.h>
/*Escreva um programa que leia n números inteiros no intervalo [0,50] e os armazene em um
vetor estaticamente alocado com 100 posições. Preencha um segundo vetor, também
alocado estaticamente, apenas com os números ímpares do primeiro vetor. Imprima os dois
vetores, 10 elementos por linha */
int main(){
    int tam = 100;
    int n;
    int num;
    int vet1[tam];
    int vet2[tam];
    int in = 0; //Intervalo
    int im = 0; //Impar
    setlocale(LC_ALL, "");

    do{
        printf("Quantos números vai declarar?\n");
        scanf("%d", &n);
    }while(n <= 0 || n > 100);

    puts("");

    while(in < n){
        printf("Entre com n %d\n", in+ 1);
        scanf("%d", &num);
        if(num >= 0 && num <= 50){
            vet1[in] = num;
            in++;
            if(num % 2 != 0){
                vet2[im] = num;
                im++;
            }
        }
    }

    printf("\nNúmeros de 0 a 50\n");
    for(int i = 0; i < in; i++){
        printf("%d ", vet1[i]);
        if((i + 1) % 10 == 0){
            puts("");
        }
    }

    printf("\nNúmeros impares\n");
    for(int i = 0; i < im; i++){
        printf("%d ", vet2[i]);
        if((i + 1) % 10 == 0){
            puts("");
        }
    }
    return 0;
}

