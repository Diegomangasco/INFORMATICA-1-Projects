#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

int main(int argc, char *argv[])
{

    char linea[50];
    int corx1, corx2, cory1, cory2;
    int matrice[N][N] = {0,0};
    int i, j,k, flag=1, ct =1;



    if(argc!=2)
    {
        fprintf(stderr,"Numero parametri errato, scrittura corretta: temadesame.exe nomefile.txt\n");
        exit(1);
    }

    FILE *fp;
    fp = fopen(argv[1],"r");

    if(fp==NULL)
    {
        fprintf(stderr,"File vuoto!\n");
        exit(2);
    }

    while(fgets(linea,10,fp)!=NULL)
    {
        sscanf(linea, "%d %d %d %d", &corx1, &cory1, &corx2, &cory2);

        if(corx1<0 || corx1>10)
            flag=0;
        else if(corx2<0 || corx2>10)
            flag=0;
        else if(cory1<0 || cory1>10)
            flag=0;
        else if(cory2<0 || cory2>10)
            flag=0;

        if(flag!=1)
        {
            fprintf(stderr,"Parametri errati, controlla che siano compresi tra 0 e 10");
            exit(3);
        }


        for(i=cory1;i<=cory2;i++)
        {
            for(j=corx1;j<=corx2;j++)
                matrice[i][j]=matrice[i][j]+1;

        }

    }

    flag=1;
    for(i=0;i<N && flag;i++)
    {
        for(j=0;j<N;j++)
        {
            if(matrice[i][j]>=2)
                flag=0;
        }
    }

    if(flag==0)
        fprintf(stdout, "I rettangoli hanno almeno una sovrapposizione");
    else
        fprintf(stdout, "I rettangoli non hanno sovrapposizioni");

    fclose(fp);
    return 0;
}
