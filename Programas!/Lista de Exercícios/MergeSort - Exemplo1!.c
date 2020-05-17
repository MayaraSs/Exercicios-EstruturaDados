#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MergeSort(int V[], int inicio, int fim);
void Intercala (int V[], int inicio, int meio, int fim);
void Copia (int V, int inicio, int fim, int W[], k);

int main() {

    int V[10], inicio, fim, meio;

    MergeSort(V, inicio, fim);
    Intercala (V, inicio, meio, fim);

}

void MergeSort(int V[], int inicio, int fim) {

    int meio;

    if (inicio < fim) {
        meio = inicio + (fim/2);
    }

    MergeSort(V, inicio, meio);
    MergeSort(V, meio+1, fim);
    Intercala(V, inicio, meio, fim);
}

void Intercala (int V[], int inicio, int meio, int fim){

    int W[10];
    int i = inicio;
    int j = (meio+1);
    int k = 0;

    while(i <= meio && j <= fim){
        if (V[i] <= V[j]){
            W[k++] = V[i++];
        }
        else {
            W[k++] = V[j++];
        }
    }

    while (i <= meio){
        W[k++] = V[i++];
    }

    while (j <= fim){
        W[k++] = V[j++];
    }

    Copia(V, inicio, fim, W, k);
}

void Copia (int V, int inicio, int fim, int W[], k) {

}
