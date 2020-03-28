#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
#define M 3

typedef struct val{
int numero;
int volte;
} valori;

int main(int argc, char *argv[])
{
    FILE *fp;
    int i,j,t;
    char linea[80];
    valori vettore[N*M];
    int v1,v2,v3;

    if(argc!=2)
    {
        fprintf(stderr, "Errore nel numero dei parametri");
        fprintf(stderr, "Uso corretto: esame.exe file_numeri.txt");
        exit(1);
    }
    if((fp=fopen(argv[1],"r"))==NULL)
    {
        fprintf(stderr, "Errore nell'apertura del file");
        exit(2);
    }

    i=0;

    while(fgets(linea, 50, fp)!=NULL)
    {
        j=0;
        t=1;
        sscanf (linea, "%d %d %d", &v1, &v2, &v3);
        if(!i)
        {
            vettore[i].numero=v1;
            vettore[i].volte ++;
            i++;

            if(v2==vettore[i-1].numero)
                vettore[i-1].volte++;
            else
            {
                vettore[i].numero=v2;
                vettore[i].volte++;
                i++;
            }

            if(i==1)
            {
                if(v3==vettore[i-1].numero)
                    vettore[i-1].volte++;
                else{
                    vettore[i].numero=v3;
                    vettore[i].volte++;
                    i++;
                }
            }else if(i==2)
            {
                if(v3==vettore[i-1].numero)
                    vettore[i-1].volte++;
                else if(v3==vettore[i-2].numero)
                    vettore[i-2].volte++;

                else{
                    vettore[i].numero=v3;
                    vettore[i].volte++;
                    i++;
                }
            }

        }else
        {

            for(j=0;j<i && t;j++)
            {
                if(v1==vettore[j].numero){
                    vettore[j].volte++;
                    t=0;
                }

            }
            if(t)
            {
                i++;
                vettore[i].numero=v1;
                vettore[i].volte++;
            }

            for(j=0;j<i && t;j++)
            {
                if(v2==vettore[j].numero){
                    vettore[j].volte++;
                    t=0;
                }

            }
            if(t)
            {
                i++;
                vettore[i].numero=v2;
                vettore[i].volte++;
            }

            for(j=0;j<i && t;j++)
            {
                if(v3==vettore[j].numero){
                    vettore[j].volte++;
                    t=0;
                }

            }
            if(t)
            {
                i++;
                vettore[i].numero=v3;
                vettore[i].volte++;
            }


        }
    }

    for(j=0;j<i;j++)
        fprintf(stdout, "%d: %d\n", vettore[j].numero, vettore[j].volte);




    return 0;
}
