#include<stdio.h>
#include<stdlib.h>
/* Josiel Pereira - 13104299 - Tecnologias da Informação e Comunicação - TIC */

/* Protipo das funções */
int bemFormada( char s[]); /* Função vista em aula e alterada por mim para tratar expressões que contenham números e chavez.*/
char *infixaParaPosfixa( char inf[]); /* Função vista em aula e alterada por mim, para tratar chavez ({}) */
int main () {
char c[30];
char *p,*v;
int t=0;
int res;
int i=0;
float x=0,y=0;
float *f;
float A; float B; float C;
printf ("Entre com uma expressao:  Ex: (A+B) use letras e nao numeros, os valores serao determinados mais tarde por voce!\n" );
scanf ("%s",c);
printf ("Digite os valores para A,B e C:");
scanf("%f",&A);
scanf("%f",&B);
scanf("%f",&C);
printf ("%s\n",c);
f = (float*) malloc (30 * sizeof (float));
p = (char *) malloc (30 * sizeof (char));
v = (char*) malloc  (30 * sizeof (char));
res = bemFormada (c);
if ( res != 0) {
       printf ("\nMal formada\n");
       printf ("Entre com uma expressao bem formada para a operação ser efetuada!!!");
}
else printf ("\nBem formada\n"); {
p = infixaParaPosfixa (c);
printf ("Expressao convertida para notacao polonesa: %s",p);
x = 0;
t = 0;

      while (p[i]!='\0') { /* Visita toda as posição do vetor de character que contém a expressão em notação polonesa */
      if ((p[i] != '+') && (p[i] != '-')&& (p[i]!='*') && (p[i]!= '/') && (p[i] != ' ')) { /* Caso não for nem um sinal para efetuar operação e nem um espaço em braco, o programa irá empihar o valor. */
      /*if (p[++i] != ' ') while (p[++i]!= ' '|| p[++i]!= '\0') v[l++] = p[i++]; f[t++] = atof(v); printf("\n%f\n",f[t++]); i++;*/
      if (p[i] == 'A' || p[i] == 'a') f[t++] = A;
      if (p[i]==  'B' || p[i] == 'b') f[t++] = B;
      if (p[i] == 'C' || p[i] == 'c') f[t++] = C;
     /* f[t++] = (p[i] - '0');  Transforma o valor que está em character para float */
      }
       else /* Nesse senão será efetuado as operações, será desimpilhado dois valores sendo guardados em x e y, e após será feito as operação depedendo do sinal */
        {
         switch (p[i]) {
         case '+':
            x = f[--t];
            y = f[--t];
            x = x + y;
            f[t++] = x;
            break;

         case '-':
            x = f[t--];
            y = f[t--];
            x = abs (x - y);
            f[t++] = x;
           break;
         case '*':
            x = f[--t];
            y = f[--t];
            x = x * y;
            f[t++] = x;
         break;
         case '/':
            x = f[--t];
            y = f[--t];
            x = (y / x) ;
            f[t++] = x;
         break;
        default:  /* Serve para tratar os espaços em bracos, não faz nada. */
        break;
         }

            }
            i++;
         }
printf ("\n Resultado da expressao: %.9f", x); /* Imprime na tela o resultado da expressão na tela com precição de 9 casas como pedido */
}
return 0;
}
int bemFormada( char s[])
{
   char *pilha; int t;
   int n, i;
    n = 20;
    t = 0;
    pilha = (char*) malloc ( n * sizeof (char));

   for (i = 0; s[i] != '\0'; ++i) {

      switch (s[i]) {
           case '(':  pilha[++t] = s[i];
                    break;
           case '{': pilha[++t] = s[i];
                    break;
           case '[': pilha[++t] = s[i];
                    break;
           case ')': if (t != 0 && pilha[t-1] == '(')
                      --t;
                   else return 0;
                   break;
           case ']': if (t != 0 && pilha[t-1] == '[')
                      --t;
                   else return 0;
                   break;
           case '}': if (t != 0 && pilha[t-1] == '{')
                      --t;
                   else return 0;
                   break;

         default:  break;
      }
   }
   if(!(t==0)) return 0;
   else return 1;

}
char *infixaParaPosfixa( char inf[]) {
  char *posf;
   char *pi; int t;
   int n, i, j;
   n = 20;
   posf = malloc( n * sizeof (char));
   pi = malloc ( n * sizeof (char));
   t = 0;
   pi[t++] = inf[0];
   for (j = 0, i = 1;inf[i] != '\0'; ++i) {
      switch (inf[i]) {
         char x;
         case '(': pi[t++] = inf[i];
                   break;
         case ')': while (1) {
                      x = pi[--t];
                      if (x == '(') break;
                      posf[j++] = x;
                   }
                   break;
         case '[': pi[t++] = inf[i];
                   break;
         case ']': while (1) {
                      x = pi[--t];
                      if (x == '[') break;
                      posf[j++] = x;
                   }
                   break;
         case '{': pi[t++] = inf[i];
                   break;
         case '}': while (1) {
                      x = pi[--t];
                      if (x == '{') break;
                      posf[j++] = x;
                   }
                   break;

         case '+':
         case '-': while (1) {
                      x = pi[t-1];
                      if (x == '(') break;
                      --t;
                      posf[j++] = x;
                   }
                   pi[t++] = inf[i];
                   break;
         case '*':
         case '/': while (1) {
                      x = pi[t-1];
                      if (x == '(' || x == '+' || x == '-')
                         break;
                      --t;
                      posf[j++] = x;
                   }
                   pi[t++] = inf[i];
                   break;
         default:  posf[j++] = inf[i];
      }
   }
   free( pi);
   posf[j] = '\0';
   return posf;
}
