#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

int main()
{
    char o1[N+1];
    char o2[N+1];
    char result [27+1];
    int t1,t2;
    int h1, h2, m1, m2;
    printf("Inserisci il primo orario nel formato hh:mm: ");
    scanf("%s", &o1);

    if(sscanf(o1,"%d:%d", &h1, &m1)!=2 || (h1<0 || h1>23 || m1<0 || m1>59))
    {
        printf("Errore di scrittura");
        return -1;
    }

    printf("Inserisci il secondo orario nel formato hh:mm: ");
    scanf("%s", &o2);

    if(sscanf(o2,"%d:%d", &h2, &m2)!=2 || (h2<0 || h2>23 || m2<0 || m2>59))
    {
        printf("Errore di scrittura");
        return -1;
    }

    t1 = h1*60 + m1;
    t2 = h2*60 + m2;

    if(t1<t2)
    {
        sprintf(result, "Intervallo_calcolato:%d", (t2-t1));
        puts(result);
    }
    else
        printf("Buona giornata pirlino");

    return 0;
}
