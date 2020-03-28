#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

typedef struct rub
{
    char *nome[20];
    char *cognome[20];
    char *fisso[20];
    char *mobile[20];
}rub;
int main()
{
    rub contatti[N];
    char nome2[21];
    char linea[80];
    int scelta, scelta2;
    int ct=1, i=0, j;
    FILE *fp;


    fp=fopen("rubrica.txt", "r");

    if(fp==NULL)
    {
        fprintf(stderr, "Errore\n");
        exit(1);
    }

    do{
            i=0;

            while(fgets(linea, 80, fp)!=NULL)
            {
                sscanf(linea, "%s %s %s %s", &contatti[i].nome, &contatti[i].cognome, &contatti[i].fisso, &contatti[i].mobile);
                i++;
            }

            fclose (fp);

            fp=fopen("rubrica.txt", "w");

            if(fp==NULL)
            {
                fprintf(stderr, "Errore\n");
                exit(2);
            }



                fprintf(stdout, "1) Aggiungi contatto.\n");
                fprintf(stdout, "2) Stampa rubrica.\n");
                fprintf(stdout, "3) Esci.\n");

                fgets(linea, 5, stdin);
                sscanf(linea,"%d", &scelta);

                switch(scelta)
                {
                case 1:

                    if(i<N){
                        fprintf(stdout, "Inserisci il nome del nuovo contatto: ");
                        fgets(linea, 20, stdin);
                        sscanf(linea, "%s", &contatti[i+1].nome);
                        while(fgets(linea, 80, fp)!=NULL)
                        {
                            sscanf(linea, "%s", &nome2);
                            if(!strcmp(contatti[i+1].nome, nome2))
                                ct=0;

                        }
                        if(ct)
                        {
                            fprintf(stdout, "Inserisci il cognome del nuovo contatto: ");
                            fgets(linea, 20, stdin);
                            sscanf(linea, "%s", &contatti[i+1].cognome);


                            fprintf(stdout, "Inserisci il fisso del nuovo contatto: ");
                            fgets(linea, 20, stdin);
                            sscanf(linea, "%s", &contatti[i+1].fisso);


                            fprintf(stdout, "Inserisci il mobile del nuovo contatto: ");
                            fgets(linea, 20, stdin);
                            sscanf(linea, "%s", &contatti[i+1].mobile);

                            for(j=0;j<i+2;j++)
                            {
                                fprintf(fp,"%s", contatti[j]);
                                fprintf(fp, "\n");
                            }
                        }

                        else
                        {
                            fprintf(stdout, "Nome già inserito, premere 1 per inserire lo stesso, altrimenti premere 0\n");
                            fgets(linea, 4, stdin);
                            sscanf(linea,"%d", &scelta2);

                            if(scelta2)
                            {
                                fprintf(stdout, "Inserisci il cognome del nuovo contatto: ");
                                fgets(linea, 20, stdin);
                                sscanf(linea, "%s", &contatti[i+1].cognome);


                                fprintf(stdout, "Inserisci il fisso del nuovo contatto: ");
                                fgets(linea, 20, stdin);
                                sscanf(linea, "%s", &contatti[i+1].fisso);


                                fprintf(stdout, "Inserisci il mobile del nuovo contatto: ");
                                fgets(linea, 20, stdin);
                                sscanf(linea, "%s", &contatti[i+1].mobile);

                                for(j=0;j<i+2;j++)
                                {
                                    fprintf(fp,"%s", contatti[j]);
                                    fprintf(fp, "\n");
                                }
                            }


                        }


                    }
                    else
                        fprintf(stderr, "Rubrica piena");


                        break;

                case 2:
                    while(fgets(linea, 80, fp))
                    {
                        fprintf(stdout, "%s", linea);
                    }
                    break;

                default:
                    if(scelta!=3)
                        fprintf(stderr,"Errore, inserisci un numero corretto\n");


    }}while(scelta!=3);

    fclose(fp);


    return 0;
}
