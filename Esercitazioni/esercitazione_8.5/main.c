#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 10
#define MAX 3
#define LEN 20+1

int main()
{
   /* char p[N+1];
    char prod;
    int prodd;
    char nome1, nome2, nome3;
    int prezzo1;
    int prezzo2;
    int prezzo3;
    int costo;
    int i=0;

    do
    {
        printf("Inserisci il prodotto numero %d con Nome e Prezzo separati da uno spazio: ", i+1);
        if(gets(p)==NULL)
            printf("Errore di scrittura\n");
        else
        {
            if(i==0)
            sscanf(p, "%c %d", &nome1, &prezzo1);
            else if(i==1)
            sscanf(p, "%c %d", &nome2, &prezzo2);
            else if(i==2)
            sscanf(p, "%c %d", &nome3, &prezzo3);

            i++;
        }

    }while(i<3);

    do
    {
    printf("Inserisci il nome del prodotto che vuoi comprare: ");
    gets(p);
    sscanf(p,"%c", &prod);
    printf("Inserisci la quantita' del prodotto che vuoi comprare: ");
    gets(p);
    sscanf(p,"%d", &prodd);
    printf("\n");

        if(prod==nome1)
            printf("Costo totale: %d\n", prodd*prezzo1);
        else if(prod==nome2)
            printf("Costo totale: %d\n", prodd*prezzo2);
        else if(prod==nome3)
            printf("Costo totale: %d\n", prodd*prezzo3);
        else
            printf("Prodotto non trovato, provi a reinserire.\n");

    }while((prod==nome1 && prod!=nome2 && prod!=nome3) || (prod!=nome1 && prod==nome2 && prod!=nome3) || (prod!=nome1 && prod!=nome2 && prod==nome3));*/

    int i;
    char prod[MAX][LEN];
    float prezzi[MAX];
    char key[LEN];
    int qta;
    int trovato =0;

    for(i=0;i<MAX;i++)
    {
        printf("Inserisci nome e prezzo prodotto %d", i+1);
        scanf("%s %f", prod[i], &prezzi[i]);
    }

    do
    {
        printf("Inserisci nome da cercare e quantita': ");
        scanf("%s %d", key, &qta);

        for(i=0;i<MAX && strcmp(key, prod[i]);i++);

       if(i!=MAX)
       {
            trovato = 1;
            printf("Costo totale %s: %f\n", prod[i], qta*prezzi[i]);
       }
        else
        {
            printf("Prodotto non trovato");
        }



    }while(!trovato);
    return 0;
}
