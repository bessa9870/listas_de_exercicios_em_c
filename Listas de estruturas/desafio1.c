#include <stdio.h>

//Desafio 01 — Bubble Sort com Ponteiros

void bubbleSort(int *arr, int n);

int main(){
    int array[5]={1,4,7,8,2};
    bubbleSort(array,5);

    for(int i = 0; i < 5; i++)
        printf("%d\n", *(array+i));

    return 0;
}
void bubbleSort(int *arr, int n){
    for(int i = 0; i < (n-1); i++){
        for(int j = 0; j < (n-i-1); j++){
            if(*(arr + j) >= *(arr +(j+1))){ //Nesse caso seria 0 + 0 >= 0 + (0+1); eu acho
                int temp = *(arr + (j+1));
                *(arr +(j+1)) = *(arr +j);
                *(arr +j) = temp;
            }
        }
    }
}

//Não gostei de fazer desse jeito, prefiro meus cochetes
