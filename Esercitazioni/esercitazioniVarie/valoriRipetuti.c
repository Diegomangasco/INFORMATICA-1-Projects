#include <stdio.h>
#include <stdlib.h>
#define N 10

int main()
{
    int v1 [N]={0};
    int v2 [N]={0};
    int i;
    int n;
    int j=0;
    int t =0;
    int ct = 1;

    for(i=0;i<N && ct;i++)
    {
        printf("Inserisci un valore: ");
        scanf("%d", &v1[i]);
        j++;
        if(v1[i]<0)
            ct=0;
    }

    printf("Il vettore scelto e':\n");

    for(i=0;i<j;i++)
        printf("%d ", v1[i]);

    printf("\n");
    printf("Inserisci il numero da controllare: ");
    scanf("%d", &n);

    for(i=0;i<j;i++)
    {
        if(v1[i]==n)
        {
            v2[t]=i+1;
            t++;
        }
    }

    for(i=0;i<t;i++)
        printf("Doppio trovato in posizione: %d\n", v2[i]);

    return 0;
}
