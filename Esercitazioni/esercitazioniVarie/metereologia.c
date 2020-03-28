#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILENAME "meteo.dat"
#define N 40

typedef enum {Gennaio = 01, Febbraio=02, Marzo =03, Aprile=04, Maggio=05, Giugno=06, Luglio=07, Agosto=08, Settembre=09, Ottobre=10, Novembre=11, Dicembre=12}mese;

int main(int argc, char* argv[])
{
    float media=0.0, tmax, tmin, tletta;
    int i=0, mese_min, mese_max;
    mese a;
    FILE *fp;
    char mese [3], anno[5], loc[N+1], data[11], linea[80], anno_min[5], anno_max[5];
    char *mesi[]={"Gennaio", "Febbraio", "Marzo", "Aprile", "Maggio", "Giugno", "Luglio", "Agosto", "Settembre", "Ottobre", "Novembre", "Dicembre"};

    if(argc!=2)
    {
        fprintf(stderr, "Errore nel numero di parametri\n");
        fprintf(stderr,"Uso corretto: meteo.exe nome_localita'");
        exit(1);
    }

    if((fp=fopen(FILENAME,"r"))==NULL)
    {
        fprintf(stderr, "Errore nell'apertura del File: %s\n", FILENAME);
        exit(2);
    }
    i=0;
    while(fgets(linea, 80, fp)!=NULL)
    {
       sscanf(linea,"%s %s %f",loc,data,tletta);
       if(!strcmp(argv[1], loc)
       {
           if(!i)
           {
             tmedia = tmax = tmin = tletta;
             mese[0]=data[3];
             mese[1]=data[4];
             mese[2]='\0';
             mese_min = mese_max = atoi(mese);
             strcpy (anno_min, &data[6]);
             strcpy (anno_max, &data[6]);
           }else
           {
             tmedia+=tletta;
             if(tletta<tmin)
             {
                tmin=tletta;
                mese[0]=data[3];
                mese[1]=data[4];
                mese[2]='\0';
                mese_min = atoi(mese);
                strcpy (anno_min, &data[6]);
                strcpy (anno_max, &data[6]);

             }
             else if(tletta>tmax)
             {
                tmax=tletta;
                mese[0]=data[3];
                mese[1]=data[4];
                mese[2]='\0';
                mese_max = atoi(mese);
                strcpy (anno_min, &data[6]);
                strcpy (anno_max, &data[6]);
             }
           i++;
        }

    }
    }

    if(i)
    {
        fprintf(stdout, "Temperatura media a %s: %f\n", &argv[1], tmedia/i);
        fprintf(stdout, "Temperatura massima: %f (%s %s)\n", tmax, mesi[mese_max-1], anno_max);
        fprintf(stdout, "Temperatura minima: %f (%s %s)\n", tmax, mesi[mese_min-1], anno_min);
    }
    else
    {
        fprintf(stdout, "Non ci sono rilevazioni sulla localita' %s", &argv[1]);
    }

    fclose(fp);
    return 0;
}
