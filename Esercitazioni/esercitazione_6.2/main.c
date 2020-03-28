#include <stdio.h>
#include <stdlib.h>
#define N 6
int palindromo_pari (int x[], int n);
int main()
{
    int i;
    int v[N];
    int c =0;

    for(i=0;i<N;i++)
    {
        printf("Inserisci  un valore: ");
        scanf("%d", &v[i]);
    }
    c = palindromo_pari(v, N);

    if(c==1)
        printf("Vettore palindromo");
    else
        printf("Vettore non palindromo");


    return 0;
}
int palindromo_pari(int x[], int n)
{
    int i;
    int j=n-1;
    int ct = 0;


        for(i=0;i<n/2 && !ct;i++)
        {
            if(x[i]==x[j])
            {
                j--;
            }
            else
            {
                ct = 1;
            }

        }


    if (ct==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
