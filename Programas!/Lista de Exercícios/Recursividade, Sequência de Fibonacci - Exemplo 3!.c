/* sequencia de fibonacci
    fib(n)= o, se n = 0
            1, se n = 1
            fib(n-1)+fib(n-2)
            se n>= 2
            */
#include <stdio.h>
#include <stdlib.h>

int Fib (int n);

int main (){

    int n;

    scanf ("%d", &n);

    printf ("%d", Fib(n));

    return 0;
}

int Fib (int n){
    /* base da recursão*/
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else {
        return Fib (n - 1) + Fib (n - 2);
    }
}
