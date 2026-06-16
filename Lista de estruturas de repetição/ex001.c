#include <stdio.h>

/*
1. Exibir a soma dos números positivos no intervalo de um a cem
*/

int main(){
    int ac=0;

    for(int i = 1; i < 100; i++){
        ac = ac + i;
    }
    printf("%d",ac);
    return 0;
}
