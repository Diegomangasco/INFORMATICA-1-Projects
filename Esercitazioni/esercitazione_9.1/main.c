#include <stdio.h>
#include <stdlib.h>
#define R 6
#define C 6
#include <string.h>
/*void palude(char mat[][C]);*/

int main()
{

    char matrice[R][C]  = {{'.','.','*','.','.','.'},
                            {'.','*','.','.','.','.'},
                            {'*','.','.','*','.','.'},
                            {'.','.','*','.','*','.'},
                            {'*','*','.','.','.','*'}};
    int i;
    int j;
    int cammino[R];
    int a=0;
    int b=1;
    int flag=1;
    int ct=1;
    int f=0;


   for(i=0;i<R;i++)
   {
       for(j=0;j<C;j++)
       {
        printf("%c", matrice[i][j]);
       }
       printf("\n");
   }

   printf("\n");


    while(f<R && flag)
    {

        for(i=0;i<R && flag;i++)
        {
            if(matrice[i][0]=='*')
            {
                b=i;
                flag = 0;
                f=i;
            }
        }

    if((f!=0)||(f!=R-1))
    {
        for(j=0;j<C-1 && ct;j++)
        {
            if(matrice[b][j+1]=='*')
            {
                cammino[a]=b;
                a++;
            }else if(matrice[b-1][j+1]=='*')
            {
                b=b-1;
                cammino[a]=b;
                a++;
            }
            else if(matrice[b+1][j+1]=='*')
            {
                b=b+1;
                cammino[a]=b;
                a++;
            }
            else
            {
                ct=0;
                a=0;
            }
        }
    }
    else if(f==0)
    {
        for(j=0;j<C-1 && ct ;j++)
        {
            if(matrice[b][j+1]=='*')
            {
                cammino[a]=b;
                a++;
            }else if(matrice[b+1][j+1]=='*')
            {
                b=b+1;
                cammino[a]=b;
                a++;
            }
            else
            {
                ct=0;
                a=0;
            }
        }
    }
    else if(f==R-1)
    {
        for(j=0;j<C-1 && ct;j++)
        {
            if(matrice[b][j+1]=='*')
            {
                cammino[a]=b;
                a++;
            }else if(matrice[b-1][j+1]=='*')
            {
                b=b-1;
                cammino[a]=b;
                a++;
            }
            else
            {
                ct=0;
                a=0;
            }
        }
    }
    if(ct!=0)
        flag = 0;
    }



    if(flag==0)
    {
        printf("Found! ");
        for(i=0;i<R;i++)
            printf("%d ", cammino[i]);
    }
    else
        printf("Percorso non trovato");

}
