#include <stdio.h>
#include <stdlib.h>
#define N 6

int main()
{
    int i;
    int x[N];
    int j;
    char s[80];
    int tmp;

    for(i=0;i<N;i++)
    {
        printf("Inseirsci un valore: ");
        gets(s);
        sscanf(s,"%d",&x[i]);

        for(j=i;j>=0 && x[j-1]>x[j]; j--)
        {
            tmp = x[j];
            x[j]=x[j-1];
            x[j-1]= tmp;
        }


    }

    printf("\n");

    for(i=0;i<N;i++)
        printf("%d ", x[i]);


    return 0;
}
