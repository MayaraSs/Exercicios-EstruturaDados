#include <stdio.h>
#include <stdlib.h>

int conta_rotas (int m , int n);

int main () {

    int m, n, num_rotas;

    m = 5;
    n = 3;

    num_rotas = conta_rotas (m, n);

    printf("Numeros de rotas: %d \n", num_rotas);

    return 0;
}

int conta_rotas(int m , int n) {

    int x, y;

    if(m == 0 || n == 0) {
        return 1;  }

    else {
        x = conta_rotas(m, n-1);
        y = conta_rotas(m-1, n);
        return x + y;
    }
}
