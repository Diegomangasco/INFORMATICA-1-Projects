#include <stdio.h>
#include <stdlib.h>
#define N 10
float avgvett(int x[], int *sup);
int upper (int x[], int m);

int main()
{
    int a[N];
    char linea [50];
    int i=0;
    float media;
    int m;
    int sup = 0;
    do
    {
        printf("Inserisci un valore: ");
        gets(linea);
        sscanf (linea,"%d",&a[i]);
        i++;
    }while(i<N);

    printf("\n");

    for(i=0;i<N;i++)
        printf("%d ",a[i]);

    printf("\n");

   printf("%f\n", media = avgvett(a, &sup));

   printf("Dammi un valore limite: ");
   gets(linea);
   sscanf(linea,"%d",&m);
   printf("\n");
   printf("Numeri oltre il valore limite: %d", upper(a, m));
   printf("\n");
   printf("Valori che superano la media: %d", &sup);
   return 0;
}
float avgvett(int x[], int *sup)
{
    float somma = 0;
    int i;
    for(i=0;i<N;i++)
        somma = somma + x[i];

    printf("%d\n", *sup);

    for(i=0;i<N;i++)
    {
        if((somma/N)<=(float)x[i])
            *sup++;

        printf("%d\n", *sup);
    }

    return somma/N;

}
int upper (int x[], int m)
{
    int cont = 0;
    int i;
    for (i=0;i<N;i++)
    {
        if(x[i]>m)
            cont++;
    }
    return cont;
}
