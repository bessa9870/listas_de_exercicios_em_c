#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* 8. No curso de Desenvolvimento de Software, a nota final do estudante é calculada a partir de
3 notas atribuídas respectivamente a um trabalho de laboratório, a uma avaliação semestral
e a um exame final. As notas variam de 0 a 10 e a nota final é média ponderada das 3 notas
mencionadas. A tabela a seguir fornece os pesos das notas:
Laboratório - peso 2
Av. Semestral - peso 3
Exame final - peso 5
Faça um programa que receba as 3 notas do estudante, calcule e imprima a
média final e o conceito desse estudante.
O conceito segue a tabela abaixo:
média final conceito
8.0 |__| 10.0 A
7.0 |__ 8.0 B
6.0 |__ 7.0 C
5.0 |__ 6.0 D
< 5.0 E */

void ler_float(float *nota){
    int leitura;
    do{
        leitura=scanf("%f",nota);
        while(getchar() != '\n');
        if(leitura != 1 || (*nota < 0 || *nota > 10))
            printf("Entrada inválida\n");
    }while(leitura != 1 || (*nota < 0 || *nota > 10));
}

void notas(float *media);

int main(){
    float n1, n2, n3, media=0;
    setlocale(LC_ALL,"");

    printf("\tUse virgula.\n\nPressione Enter para continuar.");
    while(getchar() != '\n');
    system("clear");

    printf("Entre com a nota do trabalho em laboratório: (peso 2)\n");
    ler_float(&n1);
    n1=n1 * 2;
    printf("Entre com o nota da avaliação semestral: (peso 3)\n");
    ler_float(&n2);
    n2=n2 * 3;
    printf("Entre com a nota do exame final: (peso 5)\n");
    ler_float(&n3);
    n3=n3 * 5;

    media = (n1 + n2 + n3) / 10;

    notas(&media);

    return 0;
}

void notas(float *media){
    if(*media >= 10 || *media >= 8)
        printf("Nota A\n");
    else if(*media >= 7)
        printf("Nota B\n");
    else if(*media >= 6)
        printf("Nota C\n");
    else if(*media >= 5)
        printf("Nota D\n");
    else
        printf("Nota E\n");
}
