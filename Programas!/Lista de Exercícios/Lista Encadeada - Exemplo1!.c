#include <stdio.h>
#include <stdlib.h>

struct cel {
    int conteudo;
    struct cel*seg;  };
typedef struct cel celula;

void Imprimir (celula *lst);
void Inserir (celula *p, int y);

int main ( ) {

    int i;
    celula * lst;
    celula c;
    lst = &c;
    lst -> seg = NULL;

    for (i = 64; i >= 1; i = i/2)

    Inserir (lst, i);
    Imprimir (lst);

    return 0;
}

void Inserir (celula *lst, int y) {

    celula * p, * nova;

    nova = (celula *) malloc(sizeof(celula));

    nova -> conteudo = y;

    nova -> seg = NULL;

    p = lst;

    if (p == NULL){
        lst = nova;
    }
    else {
        while (p -> seg != NULL) {
            p = p -> seg; }
        p -> seg = nova;
    }
}

void Imprimir (celula *lst) {

    celula * p;
    p = lst->seg;

    while (p != NULL)
    {
        printf ("\n %d", p->conteudo);
        p = p->seg;
    }
}

