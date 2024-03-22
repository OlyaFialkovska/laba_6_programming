#include <stdio.h>
#include <stdlib.h>
void delete_repeat(char *mas1,int ind_ff,int ll,int i,int count_words1)
{
    int k;
        int j=0;
        if(ind_ff<=ll)
        k=ind_ff;
        else
            k=i-(ll*(i/ll));

        while( j<=strlen(mas1)-1 )
        {

            printf("\nmas1=%c\t",mas1[j]);
            printf("j=%d\t k=%d\t",j,k);

            //printf("MAS=%c\n",mas[k]);
            while(k<ind_ff+ll && mas1[j]==mas1[k])
            {
                 printf("KKKKKK=%d\t",k);printf("3 step %d\n",i);
                k++;

                if(k-1==ind_ff+ll-1)
            {
                //puts(mas1);
                for(int p=j-ll; p<=strlen(mas1)-ll-1; p++)
                {
                    mas1[p]=mas1[p+ll+1];
                }
                puts(mas1);
                 printf("ind_f22=%d\n",ind_ff);

                k=ind_ff;
                //j=i;
            }

            }


            j++;
            // printf("k=%d\n",k);
        }
}
void out(char *mas1)
{
    for(int i = 0; i<strlen(mas1); i++)
        printf("%c",mas1[i]);
    printf("\n");
}
int main()
{
    char mas[254] = {"trala,fmdmg,trala,fmdmg,trala."};

    out(&mas);

    // printf("%d",n);

    int i = 0,l = 0,count_words=1,ind_f=i;
    int n=strlen(mas);


    printf("strlen(mas)=%d\n",strlen(mas));
    while (i<=strlen(mas)-1)
    {
        l=0;
        //printf("1 step\n");
        ind_f = i;
        printf("Search:\t");
        while(mas[i]!=',' && mas[i]!='.' && i<strlen(mas)-1)
        {
           //printf("2 step %d\n",i);
            printf("%c\t",mas[i]);
            //if(l==0)

            i++;
            l++;
        }
        if(mas[i-1]==',')
             count_words++;
        // i++;
   // }
   // printf("count_words=%d\t",count_words-1);
  //       while (i<=strlen(mas)-1)
   // {
printf("before i=%d\t",i);
        delete_repeat(&mas,ind_f,l,i,count_words);

        printf("\n");
        printf("i=%d\t",i);
        i++;
        printf("length=%d\t",l);
        printf("ind_f=%d\t",ind_f);
        printf("strlen(mas)=%d\n",strlen(mas));

        //under this line

    }

   out(&mas);

    return 0;
}
