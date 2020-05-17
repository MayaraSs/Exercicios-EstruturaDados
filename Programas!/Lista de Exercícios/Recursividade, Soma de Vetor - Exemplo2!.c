/*Dado um vetor v[0..n-1] de numeros inteiros, determinar a soma dos elementos positivos de v.*/
#include <stdio.h>
#include <stdlib.h>

int soma_pos_rec (int v[], int n);

int main(){
    int soma_pos;
    int v[100];
    int n = 4;
    int i;

    for (i = 0; i < n; i++)
        scanf ("%d", &v[i]);

    soma_pos = soma_pos_rec (v, n);

    printf ("A soma dos pos. eh: %d\n", soma_pos);

    return 0;
}
int soma_pos_rec (int v[], int n){
    int y;

    /* base da recursão*/
    if (n == 1)
        if (v[0] > 0) return v[0];
        else return 0;

    else {
        y = soma_pos_rec (v, n - 1);
        if (v[n - 1] > 0)
         return y + v[n - 1];
        else return y;

        };
}
