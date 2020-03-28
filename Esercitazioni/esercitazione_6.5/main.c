#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 30
#define M 100

int convertitore (int num, int bas);
/*int esp(int ba, int espo);*/

int main()
{

    char s[80];
    int n;
    int base;
    int aldo;

    do
    {
        printf("Inserisci un numero positivo minore di 30: ");
        gets(s);
        sscanf(s,"%d", &n);
        printf("\n");
        printf("Inserisci la base in cui convertire il numero, piu' piccola di esso: ");
        gets(s);
        sscanf(s,"%d", &base);
        printf("\n");

    }while (base>=n || (n<0 && n>30));


    aldo = convertitore (n, base);

    if(aldo==n)
        printf("Il numero %d convertito in base %d, e' palindromo", n, base);
    else
        printf("Il numero %d convertito in base %d, non e' palindromo", n, base);

    return 0;
}
int convertitore (int num, int bas)
{
    int i[M];
    int j=0;
    int prod1 =0;
    int t;
    int jj;

    while ((num/bas)>0)
    {
        i[j] = num%bas;
        num = num/bas;
        j++;

    }

    i[j]=num%bas;

    for(t=0;t<j+1;t++)
        printf("%d", i[t]);

    printf("\n");

    jj=j;

    for(t=0;t<j+1;t++)
    {
        prod1 = prod1 + (i[t]*pow((double)bas, (double)jj));
        jj--;
    }

    return prod1;
}

   /* for (t=0;t<j;t++)
    {
        prod1 = prod1 + (i[t] * pow((double)bas, (double)t));
    }

    cont=0;

    for(t=j;t>=0;t--)
    {
        prod2 = prod2 + (i[t] * pow((double)bas, (double)cont));
        cont++;
    }

    if(prod1==prod2)
        return 1;
    else
        return 0;
}*/
/*int esp(int ba, int espo)
{
    int i=0;
    int pro = 1;

    for(i=0;i<=espo;i++)
        pro = pro * ba;

    return pro;
}*/
