#include <stdio.h>
#include <stdlib.h>

int main() {




}

void HeapSort (int V[], int m) {

    /* Contrução do max-heap */
    t = 1;

    while (t != m) {
        t = Inserir (V, t, v[t+1]);
    }

     /* Ordenação */

     while (t >= 2){
        V[t] <-> V[1];
        Heapfica (V, t-1);
        t = t-1;
     }
}

void Heapfica (int V[], int im) {

    p = 1;

    m = IndMax (V, m, p, p*2, p*2 + 1)

    while (p != im){
        V[p] <-> V[im];
        p = im;
        im = IndMax (V, m, p, p*2, p*2+1)
    }
}

void Inserir (int V[], int n, int x){}



