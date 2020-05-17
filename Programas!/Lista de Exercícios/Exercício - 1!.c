#include <stdio.h>
#include <stdlib.h>

int somavetor(int v[], int n);

int main (){

    int soma;
    int v[10];
    int n = 2;
    int i;

    for (i = 0; i < n; i++){
        printf ("Digite os valor do Vetor: ");
        scanf ("%d", &v[i]);
    }

    soma = somavetor(v, n);

    printf ("A soma dos valores do vetor: %d \n", soma);

    return 0;
}

int somavetor(int v[], int n){

    if (n == 1){
        return v[0];
    }
    else {
        return somavetor(v, n-1) + v[n - 1];
    }
}

