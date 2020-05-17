#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int BemFormada ( char s[]);

int main ()
{
    char c [100];

    scanf ("%s", c);

    if (BemFormada(c))
        printf ("Bem-Formada\n");

    else
        printf ("Mal-Formada\n");

    return 0;
}

int BemFormada( char s [])
{
    char* p;
    int t, n, i;

    n = strlen(s);
    p =(char *) malloc (sizeof (char)* n);
    t = 0;

    for (i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '{')
            p[t++] = s[i];

        else if (s[i] == ')')

            if (t != 0 && p[t - 1] == '(')
                t--;

            else
            {   free (p);
                return 0;   }
        else
        {   if (t != 0 && p[t - 1] == '{')
                t--;

            else
            {   free (p);
                return 0;   }
        }
    }

    free (p);

    if (t == 0)
        return 1;

    else
        return 0;
}
