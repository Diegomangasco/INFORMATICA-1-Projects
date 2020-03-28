#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char*argv[])
{
    FILE *fp;
    int i,j;
    char codice[9];
    int taskok, taskerr;
    int hhi,mmi;
    int hhf, mmf;
    char linea[80];
    int MAX;
    float MIN = 100.0;
    char meglio[9], peggio[9];
    int tempo;




    if(argc!=3)
    {
        fprintf(stderr, "Errore nel numero dei parametri");
        fprintf(stderr, "Uso corretto: esame.exe dati.txt MAX");
        exit(1);
    }

    fp=fopen(argv[1], "r");

    if(fp==NULL)
    {
        fprintf(stderr, "Errore nell'apertura del file");
        exit(2);
    }
    i=0;
    while(fgets(linea, 50, fp)!=NULL)
    {
      sscanf(linea, "%s %d %d %d:%d %d:%d", &codice, &taskok, &taskerr, &hhi, &mmi, &hhf, &mmf);
      if(!i)
      {
          if(argv[2]<=taskok)
          {
              MAX=taskok;
              strcpy(codice, meglio);
              tempo=((hhf*3600)+(mmf*60))-((hhi*3600)+(mmi*60));

          }
          if(MIN>((float)taskerr/((float)taskerr+(float)taskok)))
          {
               MIN = (float)taskerr/((float)taskerr+(float)taskok);
               strcpy(codice, peggio);
          }
          i++;
      }
      else{
        if(MAX<taskok)
        {
            if(tempo<=(((hhf*3600)+(mmf*60))-((hhi*3600)+(mmi*60))))
            {
            MAX=taskok;
            strcpy(codice, meglio);
            tempo=((hhf*3600)+(mmf*60))-((hhi*3600)+(mmi*60));
            }
        }
        else
        {
            if(MIN>((float)taskerr/((float)taskerr+(float)taskok)))
            {
                MIN = (float)taskerr/((float)taskerr+(float)taskok);
                strcpy(codice, peggio);
            }
        }
        i++;
      }


      }

      fprintf(stdout, "Miglior server %s\n", meglio);
      fprintf(stdout, "Peggior server %s\n", peggio);
    }
    return 0;
}
