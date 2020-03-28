#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 60
#define R 5

int main()
{
    char c[N+1];
    char vett_string[R][N];
    int stat[N];
    int num_words;
    int sum = 0;
    int i;
    if(gets(c)!=NULL)
    {
        num_words = sscanf(c, "%s %s %s %s %s", vett_string[0], vett_string[1], vett_string[2], vett_string[3], vett_string[4]);
        printf("Numero parole inserite: %d\n", num_words);

        for(i=0;i<R;i++)
            stat[i]=0;

        for(i=0;i<num_words;i++)
        {
            sum += strlen(vett_string[i]);
            stat[strlen(vett_string[i])]++;
        }

        printf("Lunghezza media: %.2f\n", (float)sum/(float)num_words);

        for(i=0;i<R;i++)
        {
            if(stat[i]!=0)
            {
                printf("%d parole da %d caratteri", stat[i], i);
            }
        }




    }

    return 0;
}
