#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

int controllo_v2(int x[], int n);

int main()
{
    char s[80];
    int i;
    int j;
    int t;
    int v1[N];
    int v2[N];
    int n;
    int temp;

    for(i=0;i<N;i++)
    {
        printf("Inserisci un valore: ");
        gets(s);
        sscanf(s, "%d", &v1[i]);
    }
    printf("\n");

    printf("Il vettore scelto e':\n ");

    for(i=0;i<N;i++)
        printf("%d ", v1[i]);

    printf("\n");

    t=0;

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(v1[i]==v1[j])
            {
              v2[t]=v1[i];
                t++;
            }
        }
    }

    temp = controllo_v2(v2, N);

    for (i=0;i<N;i++)
        printf("%d ", v2[i]);

    printf("\n");

    if(temp!=0)
        printf("Ci sono valori ripetuti piu' volte");
    else
        printf("Non ci sono valori ripetuti più volte");




    return 0;
}
int controllo_v2 (int x[], int n)
{
    int i;
    int j;
    int t;
    for(i=0;i<n-1;i++)
    {
        if(x[i]==x[i+1])
            t++;
    }
    return t;


}
