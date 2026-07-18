#include <stdio.h>
#include <string.h>
#include <locale.h>

/* 9. Crie uma função que mostra os caracteres de uma string são repetidos. */

void repeticao(char *s);

int main(){
    char string[50];
    setlocale(LC_ALL,"");

    printf("Digire um frase: ");
    fgets(string,50,stdin);
    size_t len = strlen(string);
    if(string[len-1] == '\n')
        string[len-1] = '\0';
    else
        while(getchar() != '\n');

    repeticao(string);

    return 0;
}

void repeticao(char *s){
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == ' '){    //Impede que o programa conte espaços em branco
            continue;
        }

        int flag=0;
        for(int k = i-1; k >= 0; k--){  //Impede que o programa conte letras passadas
            if(s[i] == s[k]){
                flag=1;
                break;
            }
        }
        if(flag == 0){  //Conta novas letras repetidas (se houver)
            int contador=0;
            for(int j = i+1; s[j] != '\0'; j++){
                    if(s[i] == s[j])
                        contador++;
                }
            if(contador > 0){
                if(contador == 1)
                    printf("A letra %c tem %d repetição.\n",s[i],contador);
                else
                    printf("A letra %c tem %d repetições.\n",s[i],contador);
            }
        }
    }
}
