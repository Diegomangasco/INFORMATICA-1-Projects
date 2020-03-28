#include <stdio.h>
#include <stdlib.h>
#define N 10
int somma (int a, int b);
void fill_array(int x[], int n);

int main()
{
    int x = 5;
    int y = 6;

    int z = somma(x,y);

    int v[N];
    fill_array(v, N);
    return 0;
}
int somma (int a, int b)
{
    int c = a+b;
    return c;
}
void fill_array(int x[], int n)
{
    int i;
    for(i=0;i<n;i++)
        scanf("%d", x[i]);
}
