#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 20

typedef struct bus{
    int numero;
    int linea;
    int cx;
    int cy;
    int tempo;
}bus;

typedef struct ora{
int ora;
int minuti;
int secondi;
}ora;
int secondamano(int s, int w[]);

int main(int argc, char *argv[])
{
    bus a[N];
    ora h[2];
    char linea[50];
    char b;
    int i=0, j, t, p;
    int ct = 1;
    float dist = 0.0;
    int usato[20] = {0};

    FILE *fp;




    if(argc!=3)
    {
        fprintf(stderr, "Errore nel numero paramteri\n");
        fprintf(stderr, "Uso corretto: bus.txt -d oppure -v");
        exit(1);
    }

    fp=fopen(argv[1], "r");

    if(fp==NULL)
    {
        fprintf(stderr, "File vuoto!\n");
        exit(2);
    }

    if(argv[2][1]=='d')
        b='d';
    else if(argv[2][1]=='v')
        b='v';
    else
    {
        fprintf(stderr, "Nome flag errato, inserire d o v");
        exit(3);
    }

    while(fgets(linea, 25, fp)!=NULL)
    {
        sscanf(linea, "%d %d %d %d %d", &a[i].numero, &a[i].linea, &a[i].cx, &a[i].cy, &a[i].tempo);
        i++;
    }

    switch(b)
    {
    case 'd':
        for(t=0;t<i;t++)
        {
            p=t;
            if(secondamano(a[p].numero, usato))
            {
                usato [t]=a[p].numero;
                /*dist=sqrt(pow(((float)(a[p].cx)),2)+ pow(((float)(a[p].cy)),2));*/

                for(j=1;j<i && ct;j++)
                {
                    if(a[p].numero==a[j].numero)
                    {
                        dist+=sqrt(pow((float)(a[j].cx-a[p].cx),2)+pow((float)(a[j].cy-a[p].cy),2));
                        p=j;
                    }
                }
                    h[0].minuti = a[t].tempo/60;
                    h[0].secondi = a[t].tempo%60;
                    h[0].ora = h[0].minuti/60;
                    h[1].minuti = a[p].tempo/60;
                    h[1].secondi = a[p].tempo%60;
                    h[1].ora = h[1].minuti/60;
                    fprintf(stdout, "%d: %f - Prima misura: %d:%d:%d - Ultima misura: %d:%d:%d", a[p].numero, dist, h[0].ora, h[0].minuti, h[0].secondi, h[1].ora, h[1].minuti, h[1].secondi);
                    fprintf(stdout, "\n");
            }
            }


        break;
    default:

        break;
    }


    return 0;
}
int secondamano(int s, int w[])
{
    int i=0;
    int ct=0;
    for(i=0;i<20 &&!ct;i++)
    {
        if(w[i]==s)
            ct=1;

    }
    if(ct==0)
        return 1;
    else
        return 0;
}


