#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 4

int main(int argc, char* argv[])
{
    int i, j=0;
    int a = atoi(argv[3]);
    int cont[N] = {0};
    int flag = 1;
    int count=0;
    if(argc==4)
    {
        File* fp;
        fp=fopen("argv[1]","r");
        if(fp==NULL)
        {
            fprintf(stderr,"File vuoto");
            exit(1);
        }
        else
        {
            while(fgets(linea, 4, fp)!=NULL)
            {
                j++;
               for(i=0;i<N-1;i++)
               {
                   if(argv[2]==linea[i])
                        cont[i]=1;

               }

               for(i=0;i<N-1 && flag;i++)
               {
                   if(cont[i]==cont[i+1])
                   {
                       count++;
                    if(count==(a-1))
                        flag=0;
                   }
                   else
                    count = 0;
               }

               if(flag==0)
                fprintf(stdout,"Sequenza trovata alla riga %d", j);

            }
        }
    }
    else
    {
        fprintf(stderr, "Numero parametri errato");
        exit(2);
    }

    return 0;
}
