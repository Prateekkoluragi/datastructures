#include<stdio.h>
int sport_event(int N)
{
    int block,rem1,flag,rem2,count=0,x,i;
    for(i=1;i<=N;i++)
    {
        printf("enter the blocking number\n");
        scanf("%d",&block);


          while(block)
        {
            rem1=block%10;
            block=block/10;
            rem2=block%10;
            x=rem1-rem2;
            if(x==1)
            {
                flag=1;
            }
        }
        if(flag==1)
        {
          count++;
        }

        }
        printf("No of winners=%d",count);
}
int main()
{
   int N,Z;
   printf("enter the no of participants\n");
   scanf("%d",&N);
   Z=sport_event(N);
   return 0;
}
