#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/*18. Qualquer número natural de quatro algarismos pode ser dividido em duas dezenas pelos seus
dois primeiro e dois últimos dígitos. Exemplo: 1456 : 14 e 56. Construa um algoritmo que
imprima todos os números de quatro algarismos cuja raiz quadrada seja a soma das dezenas
formadas pela divisão acima. Exemplo: raiz de 9801 = 99 = 98 + 01. */
void calc();

int main(){
    setlocale(LC_ALL,"");
    calc();

    return 0;
}

void calc(){
    int frente=0,costa=0;
    for(int i = 1000; i <= 9999; i++){
        frente = i/100;
        costa = i%100;
        if((frente + costa) == sqrt(i))
        printf("%d\n",i);
    }
}
