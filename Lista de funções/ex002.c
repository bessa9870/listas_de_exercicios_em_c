#include <stdio.h>
#include <locale.h>

/*2. Crie um aplicativo que receba uma temperatura qualquer em Farenheit e apresente seu correspondente
em Celsius por meio de um método. Para o cálculo utilize a seguinte fórmula: Celsius = 5.0/9.0*(f-32)*/
void ler(float *n);
float conversao(float n);

int main(){
    float n, nii;
    setlocale(LC_ALL, "");

    ler(&n);

    nii = conversao(n);

    printf("A temperatura convertida em celsius é %.1fºC", nii);

    return 0;
}

void ler(float *n){
    int leitura;
    do{
        printf("Entre com a temperatura em farenheit:\n");
        leitura = scanf("%f", n);
        while(getchar() != '\n');
        if(leitura != 1){
            printf("Caractere inválido detectado!\n");
        }
    }while(leitura != 1);

    puts("");
}

float conversao(float n){
    float a;
    //5.0/9.0*(f-32)
    return a = 5.0 / 9.0 * (n - 32);
}
