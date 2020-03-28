#include <stdio.h>
#include <stdlib.h>
#define K 10

int main()
{
    int vett[K];
    float somma=0.0;
    int i;
    int max,min;
    int scelta;
    int n,n2;

    for(i=0;i<K;i++)
    {
        printf("Inserisci un valore intero ");
        scanf("%d", &vett[i]);
        printf("\n");
    }

    for(i=0;i<K;i++)
    {
        printf("Valore in posizione %d :", i+1);
        printf("%d", vett[i]);
        printf("\n");

    }

    printf ("Scegli un'operazione da fare con il vettore\n");
    printf("Clicca 1 per vedere i valori minimo e massimo, 2 per visualizzare la media:\n ");
    scanf("%d", &scelta);

    switch(scelta)
    {
        case 1:
            max=min=vett[0];
            for(i=1;i<K;i++)
            {
                if(vett[i]>max)
                {
                    max=vett[i];
                    n=i;
                }

                else
                {
                    if(vett[i]<min)
                    {
                        min=vett[i];
                        n2=i;
                    }

                }
            }
            printf("Il minimo e': %d\n", min);
            printf("Si trova in posizione: %d\n", n2+1);
            printf("Il massimo e': %d\n", max);
            printf("Si trova in posizione: %d\n", n+1);
            break;

        case 2:
            for(i=0;i<K;i++)
            {
                somma =somma + vett[i];
            }
            printf("La media e': %f", somma/(i+1));
            break;

        default:
            printf("Inserisci il numero corretto coglione!");
    }

    return 0;
}
