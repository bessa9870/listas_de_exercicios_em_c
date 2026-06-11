#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/* 13. Leia dois vetores de inteiros X e Y, cada um com 5 elementos (assuma que o usuário não
informa elementos repetidos). Calcule e mostre os vetores resultantes em cada caso abaixo:
 Soma entre X e Y: soma de cada elemento de X com o elemento da mesma posição
em Y.
 Produto entre X e Y: multiplicação de cada elemento de X com o elemento da
mesma posição em Y.
 Diferença entre X e Y: todos os elementos de X que não existam em Y.
 Interseção entre X e Y: apenas os elementos que aparecem nos dois vetores.
 União entre X e Y: todos os elementos de X, e todos os elementos de Y que não
estão em X.*/

void lervet(int v[], int tam);
void vet(int v1[], int v2[], int tam);
void somar(int v1[], int v2[], int tam, int soma);
void multipilcar(int v1[], int v2[], int tam, int produto);
void diferenca(int v1[], int v2[], int tam);
void intersecao(int v1[], int v2[], int tam);
void unir(int v1[], int v2[], int tam, int uniao);

int main(){
    int tam=5;
    int x[tam];
    int y[tam];
    int soma;
    int produto;
    int uniao;
    setlocale(LC_ALL, "");

    puts("Lendo vetor 1\n");
    lervet(x, tam);
    puts("Lendo vetor 2\n");
    lervet(y, tam);
    system("clear");
    printf("Vetor 1:\n");
    vet(x, y, tam);
    somar(x, y, tam, soma);
    multipilcar(x, y, tam, produto);
    diferenca(x, y, tam);
    intersecao(x, y, tam);
    unir(x, y, tam, uniao);

    return 0;
}

void lervet(int v[], int tam){
    int leitura;
    for(int i = 0; i < tam; i++){
        do{
            printf("Entre com indíce %d:\n", i+1);
            leitura = scanf("%d", &v[i]);
            while(getchar() != '\n');
            if(leitura != 1){
                printf("\nEntrada Invlida\nPressione Enter para continuar\n");
                while(getchar() != '\n');
                system("clear");
            }
        }while(leitura != 1);
    }
    system("clear");
}

void vet(int v1[], int v2[], int tam){
    printf("Vetor 1\tVetor 2:\n");
    for(int i = 0; i < tam; i++){
        printf("%d\t%d\n", v1[i] ,v2[i]);
    }
    puts("");
}

void somar(int v1[], int v2[], int tam, int soma){
    printf("Soma entre vetores\n");
    for(int i = 0; i < tam; i++){
        soma = 0;
        soma = v1[i] + v2[i];
        printf("%d + %d = %d\n", v1[i], v2[i], soma);
    }
    puts("");
}

void multipilcar(int v1[], int v2[], int tam, int produto){
    printf("Produto dos vetores\n");
    for(int i = 0; i < tam; i++){
        produto = 0;
        produto = v1[i] * v2[i];
        printf("%d x %d = %d\n", v1[i], v2[i], produto);
    }
    puts("");
}

void diferenca(int v1[], int v2[], int tam){
    printf("Todos os elementos de 1 que não estão em 2\n");
    printf("{");
    for(int i = 0; i < tam; i++){
        int cont=0;
        for(int j = 0; j < tam; j++){
            if(v1[i] == v2[j]){
                cont++;
                if(cont > 0){
                    break;
                }
            }
        }
        if(cont == 0){
            printf(" %d ", v1[i]);
        }
    }
    printf("}\n\n");
}

void intersecao(int v1[], int v2[], int tam){
    printf("Todos os elementos que estão em 1 e 2\n");
    printf("{");
    for(int i = 0; i < tam; i++){
        int cont = 0;
        for(int j = 0; j < tam; j++){
            if(v2[i] == v1[j]){
                cont++;
                if(cont > 0){
                    break;
                }
            }
        }
        if(cont > 0){
            printf(" %d ", v2[i]);
        }
    }
    printf("}\n\n");
}


void unir(int v1[], int v2[], int tam, int uniao){
    printf("Elementos de 1 e elementos de 2 que não estam em 1\n{");
     for(int i = 0; i < tam; i++){
        printf(" %d ", v1[i]);
     }
     for(int i = 0; i < tam; i++){
        int cont=0;
        for(int j = 0; j < tam; j++){
            if(v2[i] == v1[j]){
                cont++;
            }
        }
        if(cont == 0){
            printf(" %d ", v2[i]);
        }
    }
    printf("}\n");
}
