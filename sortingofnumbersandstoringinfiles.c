#include<stdio.h>

int main()
{

    int a[100],i,n,x,temp,j;
    FILE *input_file;
    FILE *output_file;
    input_file=fopen("input.txt","r");
    if(input_file==NULL)
    {
        printf("File not found\n");
        exit(0);
    }
    i=0;
    while(!feof(input_file))
    {
        fscanf(input_file,"%d ",&a[i]);
        i++;
    }
    n=i;
    fclose(input_file);

    printf("Enter the value of x");
    scanf("%d",&x);


    for(i=0;i<x-1;i++)
    {
        for(j=i+1;j<x;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;

            }
        }
    }

    output_file=fopen("output.txt","w");

    for(i=0;i<n;i++)
    {
        fprintf(output_file,"%d\n",a[i]);
    }
    fclose(output_file);
    printf("task done\n");
}
