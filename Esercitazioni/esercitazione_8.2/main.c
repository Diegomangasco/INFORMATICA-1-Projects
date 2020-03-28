#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define N 10

int main()
{
    char linea[N+1];
    int i;
    int lung;
    int parole;
    if(scanf("%s", &linea)==EOF)
    {
        printf("Errore di letture\n");
        return -1;
    }
    else
    {
        lung=strlen(linea);
        for(i=0;i<lung;i++)
        {
            if(islower(linea[i]))
            {
                linea[i]= toupper(linea[i]);
            }
            else if(isalnum(linea[i]))
                linea[i]='_';
            if(isdigit(linea[i]))
                linea[i]='*';
        }
        for(i=1;i<lung-1;i++)
        {
            if(linea[i]=='_' && linea[i-1]!='_')
                parole++;
        }
    }
    return 0;
}
