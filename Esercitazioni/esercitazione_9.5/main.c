#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 9

int main()
{
    char linea[50];
    float max;
    int i,j,k;
    int flag=1;
    int flag2=1;
    int a = 0;
    int riga,colonna;
    float percorso[N] = {0.0};
    float tab[N][N] = { {0.2, 0.2, 0.2, 0.2, 0.3, 0.3, 0.3, 0.3, 0.1},
                        {0.2, 0.3, 0.3, 0.4, 0.5, 0.5, 0.5, 0.5, 0.1},
                        {0.2, 0.3, 0.3, 0.5, 0.5, 0.5, 0.7, 0.7, 0.1},
                        {0.2, 0.4, 0.4, 0.5, 0.7, 0.7, 0.8, 0.7, 0.1},
                        {0.2, 0.4, 0.4, 0.5, 0.7, 0.8, 0.9, 0.8, 0.1},
                        {0.2, 0.4, 0.4, 0.5, 0.7, 0.8, 0.9, 1.4, 0.1},
                        {0.2, 0.4, 0.4, 0.5, 0.7, 0.8, 0.9, 1.2, 0.1},
                        {0.2, 0.4, 0.4, 0.5, 0.7, 0.8, 0.9, 1.1, 0.1},
                        {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1}};
    for(i=0;i<7;i++)
        printf(" ");
    for(i=0;i<N;i++)
        printf(" Co %d ", i+1);
    printf("\n");
    for(i=0;i<N;i++)
    {
        printf("Riga %d: ", i+1);
        for(j=0;j<N;j++)
        {
            printf("%.2f ", tab[i][j]);
        }
        printf("\n");
    }

    printf("Scegli una riga e una colonna di partenza: ");
    gets(linea);
    sscanf(linea,"%d %d", &riga, &colonna);

    max=tab[riga][colonna];
    percorso[a]=max;
    a++;
    k=0;
    j=0;
    while(flag2)
    {
        for(i=-1;i<2; i++)
        {
            if(max<tab[riga-1][colonna-i])
            {
                max = tab[riga-1][colonna-i];
                k=riga-1;
                j=colonna-1;
            }
        }
        for(i=-1;i<2;i++)
        {
            if(max<tab[riga+1][colonna-i])
            {
                max=tab[riga+1][colonna-i];
                k=riga+1;
                j=colonna-i;
            }
        }
        if(max<tab[riga][colonna-1])
        {
            max=tab[riga][colonna-1];
            k=riga;
            j=colonna-1;
        }
        if(max<tab[riga][colonna+1])
        {
            max=tab[riga][colonna+1];
            k=riga;
            j=colonna+1;
        }

        //printf("%.2f\n", max);

        if(max==percorso[a-1])
            flag2=0;
        else
        {
            percorso[a]=max;
            //printf("%.2f\n", percorso[a]);
            a++;
            riga=k;
            colonna=j;
            //printf("%d %d", riga, colonna);
            k=0;
            j=0;
        }
    }

    printf("\n");
    printf("Percorso: ");
    for(i=0;i<a;i++)
    {
        printf("%.2f ",percorso[i]);
    }

    return 0;
}
