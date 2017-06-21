#include <stdio.h>
#include <stdlib.h>
int max[20][20];
int alloc[20][20];
int n,r;
int need[20][20];
int avail[20];
int finish[20];
int safe[20];
int c=0;
int foundproc;
int stop()//returns a 1 when all processes are visited
{
    int i;
    int flag=1;
    for(i=0;i<n;i++)
    {
        if(finish[i]==0)
        {
            flag=0;
            break;
        }
    }
    return flag;
}
void safety()
{

    int i,j,k,f;

         for(i=0;i<n;i++)
         {

             if(finish[i]==1)
                 continue;
             foundproc=0;
              f=1;

             for(j=0;j<r;j++)
             {
                 if(need[i][j]>avail[j])//if need is greater than available for any resource then break out
                 {

                      f=0;
                      break;
                 }

             }
             if(f==1)//we found a process for which need is less than available
             {

                 foundproc=1;

                 finish[i]=1;
                 for(k=0;k<r;k++)
                    avail[k]=avail[k]+alloc[i][k];// change the availability to availability=available+allocation
                safe[c++]=i;
             }
         }
}

int main()
{
    int s[20],resource[20];
    int i,j;
    for(i=0;i<20;i++)
    {
        s[i]=0;
    }
    printf("\nenter the number of processes  ");
    scanf("%d",&n);
    printf("\nenter the number of resources  ");
    scanf("%d",&r);
    printf("\nEnter the MAX Matrix ");
    for(i=0;i<n;i++)
    {
        printf("\n\nFOR Process P%d:\n",i);
        for(j=0;j<r;j++)
        {
            printf("\nEnter Max for R%d   ",j);
            scanf("%d",&max[i][j]);
        }
    }
    printf("\nThe max matrix entered is  \n");
     for(i=0;i<n;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("%d\t",max[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the ALLOCATION Matrix ");
    for(i=0;i<n;i++)
    {
        printf("\n\nFOR Process P%d:\n\n",i);
        for(j=0;j<r;j++)
        {
            printf("\nEnter allocation for R%d   ",j);
            scanf("%d",&alloc[i][j]);
        }
    }
     printf("\nThe allocation matrix entered is  \n");//prints allocation matrix
     for(i=0;i<n;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("%d\t",alloc[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<n;i++)//calculates need matrix
    {
        for(j=0;j<r;j++)
        {
           need[i][j]=max[i][j]-alloc[i][j];
        }
    }
     printf("\nThe NEED matrix is  \n");
     for(i=0;i<n;i++)//prints need matrix
    {
        for(j=0;j<r;j++)
        {
            printf("%d\t",need[i][j]);
        }
        printf("\n");
    }
    for(j=0;j<r;j++)//calculates the sum of each allocated resource
    {
        for(i=0;i<n;i++)
        {
           s[j]=s[j]+alloc[i][j];
        }

}

    printf("\nEnter number of instances of each resource");
    for(i=0;i<r;i++)
    {
       printf("\nNumber of instances of R%d",i);
       scanf("%d",&resource[i]);
    }

     for(i=0;i<r;i++)//calculates available matrix
     {
         avail[i]=resource[i]-s[i];
     }
     printf("\nThe available vector is\n");
     for(i=0;i<r;i++)
        printf("%d\t",avail[i]);
     printf("\n\n");
     

	for(i=0;i<n;i++)
        finish[i]=0;
     while(stop()!=1)
     {
         safety();

         if(foundproc==0)//if for no i need of i < available then there is no safe sequence
            break;

     }
     if(foundproc==0)
     {
         printf("\nThere is no safe sequence  ");
         return 0;
     }
     printf("\n\nThe SAFE sequence is\n\n");
     for(i=0;i<n;i++)
        printf("P%d\t",safe[i]);

     return 0;



}
