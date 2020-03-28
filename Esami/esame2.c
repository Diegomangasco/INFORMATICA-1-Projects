#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5
typedef struct operai{
    int matricola;
    int ttot;
    int hh;
    int mm;
    int s;
}operai;
int main(int argc, char *argv[])
{
    FILE *fp;
    int i=0, j, hh, mm, s, mat, entr, sportello,ct=1;
    operai lista[N];
    char linea[80];

    for(j=0;j<N;j++)
        lista[j].ttot=0;


    if(argc!=3)
    {
        fprintf(stderr, "Errore nel numero dei parametri");
        fprintf(stderr, "Uso corretto: esame.exe dati.txt -v o -m");
        exit(1);
    }

    fp=fopen(argv[2], "r");

    if(fp==NULL)
    {
        fprintf(stderr, "Errore nell'apertura del file");
        exit(2);
    }

    while(fgets(linea, 40, fp)!=NULL)
    {
        sscanf(linea,"%d %d %d %d:%d:%d", &sportello, &mat, &entr, &hh, &mm, &s);

        if(!i)
        {
            lista[i].matricola=mat;
            lista[i].hh=hh;
            lista[i].mm=mm;
            lista[i].s=s;
            i++;
        }else{

        for(j=0;j<i&&ct;j++)
        {
            if(mat == lista[i].matricola)
            {
                if(entr)
                {
                    lista[i].hh=hh;
                    lista[i].mm=mm;
                    lista[i].s=s;
                }else{

                    lista[i].ttot+=((hh*3600)+(mm*60)+s)-((lista[i].hh*60)+(lista[i].mm*60)+(lista[i].s));
                    lista[i].hh=hh;
                    lista[i].mm=mm;
                    lista[i].s=s;
                }

                ct=0;
            }

        }
        if(ct)
        {
            i++;
            lista[i].matricola=mat;
            lista[i].hh=hh;
            lista[i].mm=mm;
            lista[i].s=s;
        }

        }
    }

    switch(argv[3][1])
    {
    case 'v':
        for(j=0;j<i;j++)
        {
            fprintf(stdout, "Operaio: %d Ore di permanenza: %f\n", lista[i].matricola, (float)lista[i].ttot/3600);
        }
        break;
    case 'm':
        for(j=0;j<i;j++)
        {
            fprintf(stdout, "Operaio: %d Ultima uscita: %d:%d:%d\n", lista[i].matricola, lista[i].hh, lista[i].mm, lista[i].s);
        }
        break;
    default:
        fprintf(stderr, "Parametro sbagliato, inserire -v o -m");
        exit(3);
    }

    fclose(fp);


    return 0;
}
