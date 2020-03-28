#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int somma=0;
    int a,b;
    if(argc!=3)
    {
        printf("Errore di passaggio parametri sulla linea di comando!");
        exit(1);
    }
    else{
         a=atoi(argv[1]);
         b=atoi(argv[2]);
        if((a>=-1000 && a<=1000) && (b>=-1000 && b<=1000))
        {
            somma= a+b;
            printf("%d",somma);
        }
        else
            printf("Parametri errati!");
    }
    return 0;
}
