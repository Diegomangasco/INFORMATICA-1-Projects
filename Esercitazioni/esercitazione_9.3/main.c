#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char linea[50];
    char loc[50];
    char loca[50];
    int i;
    int num_treni = 0;
    int arrivi=0;

    FILE *fd;
    fd = fopen("treni.txt", "r");

    if(fd==NULL)
    {
        printf("Errore di lettura!");
        exit(1);
    }

    printf("Inserisci la località di destinazione:");
    gets(linea);
    sscanf(linea, "%s", &loca);

    while(fgets(linea,20,fd)!=NULL)
    {
        fscanf(linea,"%s", &loc);
        if(strcmp(loc, loca)==0)
            arrivi++;

    }

    printf("Numero treni in arrivo a %s: %d", loc, arrivi);


    return 0;
}
