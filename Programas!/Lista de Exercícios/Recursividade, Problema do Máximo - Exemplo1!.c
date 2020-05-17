/* o problema do maximo:
dado um vetor v[0...n-1] de numeros inteiros, determinar o valor de um elemento minimo em v.
*/
#include <stdio.h>
#include <stdlib.h>

int minimo_rec (int v[], int n);

int main (){

    int vi[100];
    int n, i, ind_mim;

    printf("Entrar com o tamanho da sequencia: ");
    scanf("%d", &n);
    printf("Entrar com uma sequencia de numeros int: ");

    for (i = 0; i < n; i++)
        scanf ("%d", &vi[i]);

    ind_min = minimo_rec() (vi, n);

    printf ("\n%d\n", vi[ind_min]);
    system("pause");


    return 0;
    }

int minimo_rec (int v[], int n) {

    int ind_min;

    if (n == 1)
        return 0;
    else {
        ind_min = minimo_rec (v, n - 1);
        if (v[ind_min] > v[n - 1])
            ind_min = n - 1;
        return ind_min;
    }
}
