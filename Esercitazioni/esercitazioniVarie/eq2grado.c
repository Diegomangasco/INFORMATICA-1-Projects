#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b, c;
    int delta;
    float x1, x2;
    printf("Inserisci il valore della variabile a: ");
    scanf("%f", &a);
    printf("Inserisci il valore della variabile b: ");
    scanf("%f", &b);
    printf("Inserisci il valore della variabile c: ");
    scanf("%f", &c);

    delta = (b*b)- 4*(a*c);

    switch (delta)
    {
        case 0:
        x1 = -b/(2*a);
        printf("Il risultato e': ", x1);
        break;

        default:
            if(delta<0)
            {
                printf("L'equazione non ha soluzioni.");
            }
            else{
            x1= ((-b)+delta)/(2*a);
            x2= ((-b)-delta)/(2*a);
            printf("I risultati sono: ", x1,x2);
            }
    }



    return 0;
}
