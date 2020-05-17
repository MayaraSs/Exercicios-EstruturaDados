#include <stdio.h>
#include <stdlib.h>
#define MAX 50


int * distancia (int a[][MAX], int n, int o);
void imprime (int d[], int n);


int main (){

	int a[MAX][MAX];
	int n, i, j, o;
	int * d;
	FILE * arq;

	arq=fopen("Matriz - Exemplo1!.txt","r");

	fscanf(arq,"%d ", &n);
	fscanf(arq,"%d ", &o);

	for(i=0; i<n; i++)
		for(j=0;j<n;j++)
			fscanf(arq, "%d ", &a[i][j]);

	d=distancia (a, n, o);
	imprime(d,n);

	fclose(arq);


return 0;
}

int * distancia (int a[][MAX], int n, int o){
	int * f;
	int s, t;
	int * d;
	int x , y;

	d= (int *) malloc (sizeof (int) *n);
	f= (int *) malloc (sizeof (int) *n);

	for( x=0; x<n; x++)
		d[x]=n;

	d[o]=0;
	s=t=0;
	f[t++]=o;

	while(!(s==t)){

		x=f[s++];

		for (y=0;y<n; y++)
			if(a[x][y]==1 && d[y]==n) {
				d[y]=d[x]+1;
				f[t++]=y;
			}

	}
	free (f);
	return d;
}

void imprime ( int d[], int n){
	int i;
	for(i=0;i<n;i++){

		if (d[i]==n)
		printf("+inf ");
		else printf ("%d ", d[i]);
	}

	printf("\n");

}
