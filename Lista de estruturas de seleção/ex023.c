#include <stdio.h>
#include <locale.h>

/*Faça um programa que receba uma frase,
conte e imprima a quantidade de vezes
em que aparece a palavra “aula” */

int main(){
    int tamanho = 100;
    char string[tamanho];
    int contador = 0;

    printf("Entre com uma frase:\n");
    fgets(string, sizeof(string), stdin);

    puts("");

    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] == 'a' || string[i] == 'A'){
        //Se esse indice começar com a 'OU' com A, desça
            if(i == 0 || string[i-1] == ' '){
            //Se esse indice for o 0 'OU' o indice anterior for um espaço, desça
                if(string[i+1] == 'u' && string[i+2] == 'l' && string[i+3] == 'a' && (string[i+4] == ' ' || string[i+4] == '\n' || string[i+4] == '\t')){
                //Se o indice i+1 for un u 'E' o indice 1+2 for um l 'E' (o indice 1+3 for um a 'OU'
                //for um enter 'OU' uma tabulação 'OU' um espaço) desça
                    contador++;
                    //incremente o contador
                }
            }
        }
    }


    printf("Sua frase:\n");
    puts(string);
    printf("A palavra aula apareceu %d vezes na sua frase.", contador);

    return 0;
}
