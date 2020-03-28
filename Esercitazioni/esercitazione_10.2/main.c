#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int val1, val2;
    char ch;
    if(argc!=4)
    {
        printf("Errore nel passaggio!");
        exit(1);
    }
    else
    {
        val1 = atoi(argv[1]);
        val2 = atoi(argv[2]);
        ch = argv[3][0];
        switch(ch)
        {
        case 'a':
            printf("Somma: %d", val1 + val2);
            break;
        case 'b':
            printf("Differenza: %d", val1-val2);
            break;
        case 'c':
            printf("Prodotto: %d", val1*val2);
            break;
        case 'd':
            if(val2!=0)
                printf("Quoziente: %.2f", (float)val1/(float)val2);
            else
                printf("Valore 2 errato");
            break;
        default:
            printf("Parametro ch errato!");


        }
    }
    return 0;
}
