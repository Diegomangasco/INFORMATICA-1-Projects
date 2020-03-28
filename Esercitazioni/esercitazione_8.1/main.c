#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 49

int main()
{
    char linea[N +1];
    char linea2[N+1];
    int j;
    int lung;
    int lung1;
    int alpha=0;
    int num=0;
    int i;
    if(scanf("%s", linea)==EOF)
    {
        printf("Errore in lettura\n");
        return -1;
    }
    else
    {
        lung = strlen(linea);
        printf("Lunghezza frase inserita: %d\n", lung);

        for(i=0;i<lung;i++)
        {
            if(isdigit(linea[i]))
                num++;

            else if(isalpha(linea[i]))
                    alpha++;
        }
        printf("Caratteri numerici: %d\n", num);
        printf("Caratteri alfabetici: %d\n", alpha);

    }
    printf("\n");
    if (scanf("%s", linea2)==EOF)
    {
        printf("Errore di lettura\n");
        return -1;
    }
    else
    {
        lung1 = strlen(linea2);
        int flag=1;
        for(i=0;i<lung && flag==1;i++)
        {
         flag = 0;

                for(j=0;j<lung1 && flag==0;j++)
                {
                    if(linea[i+j]!=linea2[j])
                        flag=1;
                }

        }
        if(flag==0)
            printf("Parola contenuta.");
        else
            printf("Parola non contenuta.");
    }
    return 0;
}
