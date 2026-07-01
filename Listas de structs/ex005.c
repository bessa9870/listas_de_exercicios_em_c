#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*5. Considerando a estrutura
struct Vetor{
float x;
float y;
float z;
};
para representar um vetor no R 3, implemente um programa que calcule a soma de dois
vetores.*/

typedef struct{
    float x, y, z;
}Vetor;

int main(){
    setlocale(LC_ALL,"");
    Vetor vetores1;
    vetores1.x=1;
    vetores1.y=2;
    vetores1.z=3;

    Vetor vetores2;
    vetores2.x=4;
    vetores2.y=5;
    vetores2.z=6;

    Vetor vetores3;
    vetores3.x = vetores1.x + vetores2.x;
    vetores3.y = vetores1.y + vetores2.y;
    vetores3.z = vetores1.z + vetores2.z;

    printf("%.1f %.1f %.1f",vetores3.x,vetores3.y,vetores3.z);

    return 0;
}
