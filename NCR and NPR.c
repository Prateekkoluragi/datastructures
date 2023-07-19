#include<stdio.h>

int fact(int n)
{
    int i,p=1;
    for(i=n;i>=1;i--)
    {
        p=p*i;
    }
    return p;
}
