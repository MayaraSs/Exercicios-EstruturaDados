#include <stdio.h>
#include <stdlib.h>
#define N 100

int Inserir (int v[], int n, int k, int y);
int Buscar (int v[], int n, int x);
int Remover (int v[], int n, int k);
void Imprimir (int v[], int n);

int main ()
{
    int v[N];
    int n = 0;
    int i, j;

    for(i = 64; i >= 1; i = i/2){
        n = Inserir(v, n, 0, i); }

    j = Buscar (v, n, 32);

    printf ("Indice de %d: %d. \n", 32, j);

    Imprimir(v, n);

    return 0;
}

int Inserir (int v[], int n, int k, int y)
{
    int j;

    for(j = n; j > k; j--)

    v[j] = v[j-1];
    v[k] = y;

    return n+1;
}

int Buscar (int v[], int n, int x)
{
    int k;

    k = n-1;

    while (k >= 0 && v[k] != x)
        k = k-1;

    return k;
}

int Remover (int v[], int n, int k)
{
    int j;

  for(j = k; j < n-1; j++)
   { v[j] = v[j+1]; }

   return n-1;
}

void Imprimir (int v[], int n)
{
    int j;

    for(j = 0; j < n; j++){
        printf("%d ", v[j]); }
}
