#include <stdio.h>
#include <locale.h>

/*15.A série de Fetuccine difere da série de Ricci porque o termo de posição par é resultado da
subtração dos dois anteriores. Os termos ímpares continuam sendo o resultado da doma dos
dois elementos anteriores. Imprima os n primeiros termos da série de Fetuccine. */

int main(){
    int n;
    int n1, n2, n3 = 0;

    do{
        printf("Entre com n:\n");
        scanf("%d", &n);
        while(getchar() != '\n');
        if(n < 2){
            printf("Inválido. Que seja maior que 1.\nPressione Enter");
            while(getchar() != '\n');
        }
   }while(n < 2);

    printf("Entre com o primeiro termo:\n");
    scanf("%d", &n1);

    printf("Entre com o segundo termo:\n");
    scanf("%d", &n2);

    printf("-------------%d termos-------------\n", n);
    printf("%d\n", n1);
    printf("%d\n", n2);

    for(int i = 3; i <= n; i++){
        if(i % 2 == 0){     //Se o indice for par
            if(n1 > n2){    //Se n1 for maior que n2
                n3 = n1 - n2;
            }else{
                n3 = n2 - n1;   //Se n2 for maior que n1
            }
        }else{      //Se o índice for impar
            n3 = n1 + n2;
        }

        printf("%d\n", n3);
        n1 = n2;
        n2 = n3;

    }


    return 0;
}
