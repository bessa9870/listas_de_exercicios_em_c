#include <stdio.h>
#include <string.h>
#include <locale.h>

/* 10. Crie uma função que retira todas os caracteres repetidos de uma string. */

void repeticao(char *s);

int main(){
    char string[50];
    setlocale(LC_ALL,"");

    printf("Digite um frase: ");
    fgets(string,50,stdin);
    size_t len = strlen(string);
    if(string[len-1] == '\n')
        string[len-1] = '\0';
    else
        while(getchar() != '\n');

    repeticao(string);

    printf("\n%s",string);

    return 0;
}

void repeticao(char *s){
    int k=0;//Índice da string final
    for(int i = 0; *(s+i)!='\0';i++){//Pega uma letra por rodada

        int flag = 0;
        if(s[i] != ' '){//Ignora os espaços
            for(int j = 0; j < i; j++){//Olha atrás dessaa letra
                if(s[j] != ' ' && s[j] == s[i]){//Verifica se já apareceu
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 0){//Copia em j as que não apareceram
            s[k] = s[i];
            k++;//Incrementa índice j
        }
    }
    s[k] = '\0';//No fim de tudo, delimita a stringx
}

