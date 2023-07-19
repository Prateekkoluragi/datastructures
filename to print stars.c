   /*/* Program to print the following pattern
*
* *
* * *
*/


#include<stdio.h>
main()
{
      int N;
      int i,j;
      printf("Enter the value for N : \n");
      scanf("%d", &N);
     for(i=1;i<=N; i++)
    {
       for(j=0;j<i;j++)
      {
         printf("*");
      }
    printf("\n");
   }
}
