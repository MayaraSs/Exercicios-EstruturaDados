#include <stdio.h>
#include <stdlib.h>

struct cel {
    int conteudo;
    struct cel * seg;
    struct cel * ant;
};

typedef struct cel celula;

void Inserir(celula * p, int x);

void Remover (celula * p);

void Imprimir (celula * lst);

celula * Buscar(celula * lst, int y);

int main ()
{
    int i;
    celula * lst;
    celula c;
    celula * ey;
    lst = &c;
    lst->seg = NULL;
    lst->ant = NULL;

    for (i = 64; i >= 1; i = i/2)
    {
        Inserir(lst, i);
    }

    Imprimir(lst);

    ey = Buscar (lst, 64);

    Remover (ey);

    Imprimir (lst);

    return 0;
}

void Inserir (celula * p, int x)
{
    celula * nova;
    nova = (celula *) malloc(sizeof (celula));
    nova -> conteudo = x;
    nova -> ant = p;
    nova->seg = p->seg;
    p -> seg = nova;
    if (nova-> seg != NULL)
        nova -> seg -> ant = nova;
}

void Imprimir(celula * lst){
    celula * p;
    p = lst->seg;

    while (p != NULL)
    {
        printf ("\n %d", p->conteudo);
        p = p->seg;
    }

}
void Remover (celula * p){

    p->ant->seg = p->seg;

    if (p->seg != NULL)
    {
        p->seg->ant = p->ant;
    }

    free(p);
}

celula * Buscar(celula * lst, int y)
{
    celula * p = lst -> seg;

    while(p != NULL && p->conteudo != y)
    {
        p = p-> seg;
    }

    return p;
}





