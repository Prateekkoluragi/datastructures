#include<stdio.h>

int main()
{

    int m1,n1,m2,n2,i,j;
    int a[100][100],b[100][100];
    printf("write the number of rows and columns in the amtrix\n");
    scanf("%d",&m1);
    scanf("%d",&n1);
    printf("enter the elements\n");
    for(i=0;i<m1;i++)
    {
        for(j=0;i<n1;j++)
        {
            scanf("%d",a[i][j]);
        }
    }
    printf("Enter the number of rows and columns of second matrix\n");
    scanf("%d",&m2);
    scanf("%d",&n2);
    for(i=0;i<m2;i++)
    {
        for(j=0;j<n2;j++)
        {
            scanf("%d",b[i][j]);
        }
    }
    mul(a,b,m1,n1,m2,n2);
    return 0;
}
void display(int a[90][90],int n,int m)

{
    int i,j;
    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

void mul(int a[100][100],int b[100][100],int n, int m,int n1,int m1)
{
  int i,j,h[90][90],sum,k;

    if(m==n1)
    { sum=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m1;j++)
         {
             for(k=0;k<m;k++)

        {
            sum=sum+a[i][k]*b[k][j];
        }
          h[i][j]=sum;
          sum=0;
         }
        printf("\n ");
    }
    printf("The multiplication of matrix is: %d",h[i][j]);
   display(h,n,m1);
    }
    else
        printf("matrix multiplication not found\n");

}
