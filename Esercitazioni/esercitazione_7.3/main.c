#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define N 80


int main()
{
    int numcar = 0;
    int numalfa = 0;
    int maiusc = 0;
    int dec = 0;
    int spazi = 0;
    char tasto;
    printf("Inserisci caratteri:\n");

    do
    {
        tasto = getchar();
        numcar++;

        if(isalpha(tasto))
            numalfa++;
        else
        {
            if(isupper(tasto))
                maiusc++;
            else
            {
                if(isdigit(tasto))
                    dec++;
                else
                {
                    if(isspace(tasto))
                        spazi++;
                }

            }
        }


    }while(tasto!='\n');




    return 0;
}
