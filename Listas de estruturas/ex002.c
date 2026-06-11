#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#define LEN 50
#define FONE 20
#define tamanho 5

/* Utilizando estrutura, fazer um programa em C que permita a entrada de nome,
endereço e telefone de 5 pessoas e os imprima em ordem alfabética. */
struct local{
    char rua[LEN];
    int numero;
};

struct cadastro{
    char nome[LEN];
    struct local endereco;
    char fone[FONE];
};

void ler_cad(struct cadastro pessoa[]);
void ordenar_struct(struct cadastro pessoa[]);
void imprimir_struct(struct cadastro pessoa[]);

int main(){
    struct cadastro pessoa[tamanho];
    setlocale(LC_ALL, "");

    ler_cad(pessoa);
    ordenar_struct(pessoa);
    imprimir_struct(pessoa);

    return 0;
}

void ler_cad(struct cadastro pessoa[]){
    for(int i = 0; i < tamanho; i++){
        int leitura = 1;    //Validação de números
        int j;  //Validação de strings
        int c;  //Validação para arquivos .txt
        printf("--------------Preenchendo cadastro--------------\n");
        printf("--Nome:");   //Sem usar size_t
        fgets(pessoa[i].nome,LEN,stdin);

        for(j = 0; (pessoa[i].nome[j] != '\n' && pessoa[i].nome[j]!= '\0'); j++);

        if(pessoa[i].nome[j] == '\n'){
            pessoa[i].nome[j] = '\0';
        }else{
            while((c = getchar()) != '\n' && c != EOF);
        }

        printf("--Endereço:\n-Rua:");   //Sem usar size_t
        fgets(pessoa[i].endereco.rua,LEN,stdin);

        for(j = 0; (pessoa[i].endereco.rua[j] != '\n' && pessoa[i].endereco.rua[j] != '\0'); j++);

        if(pessoa[i].endereco.rua[j] == '\n'){
            pessoa[i].endereco.rua[j] = '\0';
        }else{
            while((c = getchar()) != '\n' && c != EOF);
        }

        do{
            printf("-Número:");
            leitura = scanf("%d", &pessoa[i].endereco.numero);
            while(getchar() != '\n');
            if(leitura != 1){
                printf("Número inválido. Tente novamente.\n");
            }
        }while(leitura != 1);

        printf("--Telefone:");     //Usando size_t
        fgets(pessoa[i].fone,FONE,stdin);

        size_t lengh = strlen(pessoa[i].fone);
        if(lengh > 0 && pessoa[i].fone[lengh-1] == '\n'){
            pessoa[i].fone[lengh -1] = '\0';
        }else{
            while((c = getchar()) != '\n' && c != EOF);
        }
        puts("");
    }
}

void ordenar_struct(struct cadastro pessoa[]){
    struct cadastro auxiliar;
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho - 1; j++){
            if(strcmp(pessoa[j].nome, pessoa[j+1].nome) > 0){
                    auxiliar = pessoa[j+1];
                    pessoa[j+1] = pessoa[j];
                    pessoa[j] = auxiliar;
            }
        }
    }
}

void imprimir_struct(struct cadastro pessoa[]){
    for(int k = 0; k < tamanho; k++){
        printf("----------------------------------------------------------\n\tCadastro %d\n--Nome:", k+1);
        puts(pessoa[k].nome);
        printf("--Endereço\n-Rua:");
        puts(pessoa[k].endereco.rua);
        printf("-Número da casa:%d\n", pessoa[k].endereco.numero);
        printf(" Número de telefone:");
        puts(pessoa[k].fone);
        puts("");
    }
}
