#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void Read_votes(int A[],int n);
void check_votes(int A[],int n);

int main()
{

    int n;
    int A[1000];
    scanf("%d",&n);
    if(n<1)
    {
        printf("Invalid");
    }
    else
    {
    Read_votes(A,n);
    check_votes(A,n);
    }
    return 0;
}

void Read_votes(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
}

void check_votes(int A[],int n)
{
    int i,j,c=0;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(A[i]==A[j])
            c++;
        }
    if(c>=1)
    {
        printf("%d\t",A[i]);
    }
    }
}
