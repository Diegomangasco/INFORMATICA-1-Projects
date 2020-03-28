#include <stdio.h>
#include <stdlib.h>
#define MAX 255

int main()
{
    char str[MAX+1];
    int i;
    int j;
    printf("Inserisci il testo:\n");

    gets(str);

    for(i=0;i<strlen(str)-1;i++)
    {
        if(tolower(str[i]) == 'c' && tolower(str[i+1])=='h')
        {
            if(isupper(str[i]))
                str[i]='K';
            else
                str[i]='k';
        }

    for(j=i+1; j<strlen(str); j++)
        str[j]=str[j+1];
    }


for(i=0;i<strlen(str)-1;i++)
{
    if(tolower(str[i]) == tolower(str[i+1]))
    {
        for(j=i+1; j<strlen(str); j++)
            str[j]=str[j+1];
    }
}




    puts(str);

    return 0;
}
