#include <stdio.h>
#include <stdlib.h>
#define MAX 30

/*n representa o n�mero de rainhas
  que ainda faltam colocar no tabuleiro
  N x N.*/

int rainhas (int n, int N, int T[][MAX]);
void inicializa_tabuleiro (int T[][MAX], int N);
void imprime_tabuleiro (int T[][MAX], int N);

int main ()
{

    int N = 8;
    int n = N;
    int r;

    int T[MAX][MAX];

    inicializa_tabuleiro (T, N);

    r = rainhas (n, N, T);

    if (r == 1) {
        imprime_tabuleiro (T, N); }


    else {
        printf ("Nao eh possivel colocar %d rainhas em um tabuleiro %dX%d", N, N, N);
    }

    return 0;
}

int rainha_ataca (int n, int j, int T[][MAX], int N) {

    int i, k;

    /*verifica coluna*/
    for (i = n + 1; i < N; i++) {
        if (T[i][j] == 1)
            return 1;
    }

    /*verifica diagonal principal*/
    i = n + 1;
    k = j + 1;

    while (i < N && k < N) {
        if (T[i][k] == 1) {
            return 1; }

        i++;
        k++;
    }

    /*verifica diagonal secundaria*/
    i = n + 1;
    k = j - 1;

    while (i < N && k >= 0) {
        if (T[i][k] == 1) {
            return 1; }

        i++;
        k--;
    }

    return 0;
}

int rainhas (int n, int N, int T[][MAX]) {

    int r, j;

    if (n == 0) {
        return 1; }

    else {
        for (j = 0; j < N; j++) {
            T[n - 1][j] = 1;

            if (! rainha_ataca (n - 1, j, T, N)) {
                r = rainhas(n - 1, N, T);

                if (r == 1) {
                    return 1; }

                else {
                    T[n - 1][j] = 0; }
            }

            else {
                T[n - 1][j] = 0; }
        }

        return 0;
    }
}

void inicializa_tabuleiro (int T[][MAX], int N) {

    int i, j;

    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++) {
            T[i][j] = 0; }
    }
}

void imprime_tabuleiro (int T[][MAX], int N) {

    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf ("%d ", T[i][j]); }
            printf ("\n");
    }
}

