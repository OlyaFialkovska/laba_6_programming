#include <stdio.h>
#include <stdlib.h>

void words(char *copy1,char *mas1,int *i,int *ind_f_i)
{
    int j=0;
    while(j<strlen(copy1) && mas1[*i]!=',')
    {
        *ind_f_i=*i;
        copy1[j]=mas1[j];
        j++;
        *i++;
    }
    j=0;
}



void erase(char *mas,int ind_f_i,int i)
{
    for(int k=ind_f_i; k<=strlen(mas)-i-1; k++)
    {
        mas[k]=mas[k+i-1];
    }
}

void out(char *mas1)
{
    for(int k=0; k<strlen(mas1)-1;k++)
    {
         printf("%c",mas1[k]);
    }
    printf("\n");
}

int main()
{
    char mas[254] = {"trala,fmdmg,trala,flcdf,trala."};
    char copy[6]={'g'};
    int i=0,ind_f_i;
    printf("after:\t");
    out(&mas);
    printf("\n");
     printf("copy:\t");
    while(i<strlen(mas)-1 && mas[i]!='.')
    {
        words(&copy,&mas,&i,&ind_f_i);
       for(int k=0; k<=strlen(copy)-1;k++)
    {
         printf("%c",copy[k]);
    }

        for(int k=0; k<strlen(mas)-1;k++)
        {
            int j=0;
            while(j<strlen(copy)-1 && mas[k]==copy[j])
            {
                j++;
            }
            if(strlen(copy)-1==j)
            {
               erase(&mas,ind_f_i,i);
            }
        }
        i++;
    }
    printf("BEFORE:\t");
    out(&mas);
    printf("\n");
    return 0;
}
