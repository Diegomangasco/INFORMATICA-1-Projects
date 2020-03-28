#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct cord
{
   int x;
   int y;
}cord;

int main(int argc, char *argv[])
{
    cord n1, n2;
    float dist, min, dist1, dist2;
    char linea[80];
    if(argc!=2)
    {
        fprintf(stderr, "Numero parametri errati!\n");
        fprintf(stderr, "Uso corretto: nomefile.exe '-' 'a' o 'm'");
        exit(1);
    }

    if(argv[1][0]!='-')
    {
        fprintf(stderr, "E' necessario un segno -");
        fprintf(stderr, "Uso corretto: nomefile.exe '-' 'a' o 'm'");
        exit(2);
    }

    fprintf(stdout, "Inserisci le coordinate del primo punto, separate da uno spazio\n");
    fgets(linea, 7, stdin);
    sscanf("%d %d", &n1.x, &n1.y);
    fprintf(stdout, "Inserisci le coordinate del secondo punto, separate da uno spazio\n");
    fgets(linea, 7, stdin);
    sscanf("%d %d", &n2.x, &n2.y);

    if(argv[1][1]=='a')
    {
        dist = sqrt(pow(n1.x-n2.x,2) + pow(n1.y-n2.y,2));
        fprintf(stdout, "Distanza tra i due punti: %f\n", &dist);
    }
    else if(argv[1][1]=='m')
    {
        dist1= sqrt(pow(n1.x,2)+pow(n1.y,2));
        dist2= sqrt(pow(n2.x,2)+pow(n2.y,2));

        if(dist1<dist2)
            fprintf(stdout, "Distanza minima: %f", &dist1);
        else
            fprintf(stdout, "Distanza minima: %f", &dist2);

    }

    return 0;
}
