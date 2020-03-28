#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define K 10


void funz(int x[], int y, int dim);

int main()
{
    int i;
    char s[80];
    int a[K];
    int n;

    for(i=0;i<K;i++)
    {
        printf("Inserisci un valore: ");
        gets(s);
        sscanf(s,"%d",&a[i]);
    }

    printf("\n");

    printf("Inserisci il valore per cui moltiplicare il vettore: ");
    gets(s);
    sscanf(s,"%d", &n);

    printf("\n");

    funz(a,n,K);

    for(i=0;i<K;i++)
    {
        printf("Risultato numero %d: %d", i+1, a[i]);
        printf("\n");
    }


    return 0;
}

void funz(int x [], int y, int dim)
{
    int i;
    for(i=0;i<dim;i++)
        x[i]=x[i]*y;

}
