#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5
void inserimento(int m[][N]);
void stampa(int m[][N]);
void neg(int m[][N]);
int main()
{
    int i,j, mat[N][N];
    inserimento (mat[N][N]);
    stampa (mat[N][N]);
    neg(mat[N][N]);
    return 0;
}
void inserimento(int m[][N])
{
    char linea[50];
    int a,b;
    for(a=0;a<N;a++)
    {
        for(b=0;b<N;b++)
        {
            printf("Inserisci il valore di riga %d e colonna %d ", a+1, b+1);
            gets(linea);
            sscanf(linea,"%d", &m[a][b]);
            printf("\n");
        }

    }
    return;
}
void stampa(int m[][N])
{
    int a,b;
    for(a=0;a<N;a++)
    {
        for(b=0;b<N;b++)
            printf("%2d", m[a][b]);

        printf("\n");
    }
    return;
}
void neg(int m[][N])
{
    int a,b;
    int cont1[N], cont2[N];
    int ct=1;
    for(a=0;a<N;a++)
    {
        for(b=0;b<N && ct;b++)
        {
            if(m[a][b]<0)
                ct=0;
        }
        if(ct!=1)
            cont1[a]=1;
        else
            cont1[a]=0;

    }
    for(a=0;a<N;a++)
    {
        if(cont1[a]==1)
            printf("Valore negativo trovato nella riga %d\n", a+1);
        else
            printf("Riga %d positiva\n", a+1);
    }

    ct=1;
    for(a=0;a<N;a++)
    {
        for(b=0;b<N && ct;b++)
        {
            if(m[b][a]<0)
                ct=0;
        }
        if(ct!=1)
            cont2[a]=1;
        else
            cont2[a]=0;

    }
    for(a=0;a<N;a++)
    {
        if(cont2[a]==1)
            printf("Valore negativo trovato nella colonna %d\n", a+1);
        else
            printf("Colonna %d positiva\n", a+1);
    }
    return;
}
