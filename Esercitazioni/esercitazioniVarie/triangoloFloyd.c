#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int v;
    int i = 0;
    int num = 1;
    printf("Inserisci il numero delle righe del triangolo: ");
    scanf("%d", &n);
    v = 1;

    for(i=0;i<=n;i++)
    {
        for(i=0;i<v;i++)
        {
           printf("%2d", num);
           num++;
        }
        printf("\n");
        v++;
    }

    return 0;
}
