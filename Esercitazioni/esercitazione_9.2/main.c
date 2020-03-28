#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 4
#define M 40
int nuovo_prodotto(char a[][M+1], float b[]);
int main()
{
    char lista[N][M+1];
    float price[N];
    int i, j, scelta, ret, pos, ct=1;
    char linea[50];

    for(i=0;i<N;i++)
        price[i]=-2;

    do
    {
     printf("Scegli un'opzione digitando il rispettivo numero:\n");
     printf("1) Inserisci un nuovo prodotto.\n");
     printf("2) Stampa listino attuale.\n");
     printf("3) Esci dal programma.\n");
     gets(linea);
     sscanf(linea,"%d", &scelta);

     switch(scelta)
     {
     case 1:
        ret = nuovo_prodotto(lista, price);
        if(ret==2)
            printf("Lista piena!\n");
        if(ret == 0)
            printf("Valore inserito correttamente.\n");
        if(ret==1)
            printf("Valore gia' inserito!\n");
        break;
     case 2:
        printf("Lista attuale:\n");

        for(i=0;i<N && ct;i++)
        {
            if(price[i]==-2)
            {
                pos=i;
                ct=0;
            }
        }
        if(pos!=0)
        {
            for(i=0;i<pos;i++)
            {
                printf("%s %2f Euro", lista[i], price[i]);
                printf("\n");
            }
        }
        else
            printf("Lista vuota!\n");

        break;

     default:
        if(scelta>3)
        printf("Inserimento non corretto, riprova.\n");

     }
    }while(scelta!=3);


    return 0;
}
int nuovo_prodotto(char a[][M+1], float b[])
{
    char linea[50];
    char nome;
    int i,j, pos, flag=1, ct=1;
    if(b[N-1]==-2)
    {
       for(i=0;i<N && ct;i++)
       {
           if(b[i]==-2)
           {
            pos=i;
            ct=0;
           }
       }
       printf("Inserisci il nome del prodotto: ");
       gets(linea);
       for(i=0;i<pos && flag;i++)
       {
         if(strcmp(linea, a[i])==0)
         {
             flag=0;
         }

       }
       if(flag==1)
       {
           sscanf(linea,"%s", a[pos]);
           printf("\n");
           printf("Inserisci il costo: ");
           gets(linea);
           sscanf(linea,"%f", &b[pos]);
           return 0;
       }
       else
        return 1;


    }
    else
        return 2;
}
