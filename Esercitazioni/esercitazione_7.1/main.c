#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 6
int mio_pow (int a, int b);
int main()
{
    int vbase[N];
    int vesp[N];
    int vris[N];
    char s[80];
    int i;
    int risultato [N];

    for(i=0;i<N;i++)
    {
        printf("Inserisci il valore del vettore delle basi: ");
        gets(s);
        sscanf(s,"%d",&vbase[i]);
    }
    printf("\n");

    for(i=0;i<N;i++)
    {
        printf("Inserisci il valore del vettore degli esponenti: ");
        gets(s);
        sscanf(s,"%d",&vesp[i]);
    }

    printf("\n");

    for(i=0;i<N;i++)
    {
        risultato[i]= mio_pow (vbase[i], vesp[i]);
    }

    for(i=0;i<N;i++)
        printf("%d ", risultato[i]);

    return 0;
}

int mio_pow(int a, int b)
{
    int i;
    int prod = a;
    for(i=0;i<b-1;i++)
        prod = prod*a;

    return prod;

}
