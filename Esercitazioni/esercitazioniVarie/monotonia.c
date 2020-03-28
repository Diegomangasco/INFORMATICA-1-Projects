#include <stdio.h>
#include <stdlib.h>
#define N 10

int main()
{
    int vett[N]={0};
    int i;
    int ctrl = 0;
    int scelta;

    printf("Per controllare la monotonia crescente premere 1, per contorllare quella decrescente premere 2\n");
    scanf("%d", &scelta);

    switch(scelta)
    {
        case 1:
         printf("Inserisci il primo valore del vettore: ");
         scanf("%d", &vett[0]);

            for(i=1;i<N && !ctrl;i++)
            {
                printf("Inserisci un valore: ");
                scanf("%d", &vett[i]);

            if(vett[i-1]>=vett[i])
                ctrl = 1;
            }
            for(i=0;i<N;i++)
                printf("%d ", vett[i]);
            break;

        case 2:
         printf("Inserisci il primo valore del vettore: ");
         scanf("%d", &vett[0]);

            for(i=1;i<N && !ctrl;i++)
            {
                printf("Inserisci un valore: ");
                scanf("%d", &vett[i]);

                if(vett[i-1]<=vett[i])
                    ctrl = 1;
            }
            for(i=0;i<N;i++)
                printf("%d ", vett[i]);

            break;

        default:
            printf("No!");

    }





    return 0;
}
