#include <stdio.h>
#include <stdlib.h>
#define N 4
#include <math.h>

int main(int argc, char* argv[])
{
    float x[N];
    float y[N];
    int i;
    char ch;
    float lunghezza=0.0;
    float min=0.0;
    if(argc==2)
    {
        for(i=0;i<N;i++)
        {
            printf("Inserisci la coordinata x nel vattore: ");
            scanf("%f", &x[i]);
            printf("Inserisci la coordinata y nel vattore: ");
            scanf("%f", &y[i]);
        }

        if(argv[1][0]=='-')
        {
            ch=argv[1][1];

            switch(ch)
            {
          case 'm':
              for(i=0;i<N-1;i++)
              {
                  lunghezza+=sqrt(pow((x[i+1]-x[i]),2)+pow((y[i+1]-y[i]),2));
              }
              printf("Lunghezza percorso: %f", lunghezza);
            break;
          case 'a':
              min = sqrt(pow((x[1]-x[0]),2)+pow((y[1]-y[0]),2));
              for(i=1;i<N-1;i++)
              {
                  if(min>(sqrt(pow((x[i+1]-x[i]),2)+pow((y[i+1]-y[i]),2))));
                  {
                      min=sqrt(pow((x[i+1]-x[i]),2)+pow((y[i+1]-y[i]),2));
                  }
              }
              printf("Minima distanza: %f", min);
            break;
          default:
            printf("Parametro errato, inserire -a o -m!");
            }
        }
        else
            printf("Errore parametro!");
    }
    else
        printf("Parametri errati, inserire -a o -m");



    return 0;

   /* int j=0;
    for(i=2;i<7;i++)
    {
        sscanf(argv[i], "%d,%d", &x[j], y[j]);
        j++;
    }*/
}
