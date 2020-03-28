#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define PRECISIONE 0.1
double arcoseno (int z1, int z2, int val);
int main()
{
    int a;
    int b;
    int c;
    char s[80];
    double risultato;

    printf("Inserisci i valori dell'intervallo separati da uno spazio: ");
    gets(s);
    sscanf(s, "%d %d", &a, &b);
    printf("\n");
    printf("Inserisci il valore dell'arcoseno: ");
    gets(s);
    sscanf(s, "%d", &c);

    risultato = arcoseno (a, b, c);

    if (risultato == 0.0)
        printf("Valore non calcolabile");
    else
        printf("L'arcoseno di %d e': %f", c, risultato);


    return 0;
}
double arcoseno (int z1, int z2, int val)
{
    double z = ((double)z1+(double)z2)/2;
    double sen = sin(z);

    while ((sen-val)!= PRECISIONE)
    {
        if((sen-val)>0)
            z=(z+(double)z2)/2;
        else
            z=((double)z1+z)/2;

        sen = sin(z);
    }

    if(z>z1 && z<z2)
        return z;
    else
        return 0.0;

}
