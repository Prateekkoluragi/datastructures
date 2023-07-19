 #include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define max 100
struct stack
{
    int top;
    int elements[max];
};
void initstack(struct stack *s);
int isFull(struct stack *s);
void push(struct stack *s,int e);
int isEmpty(struct stack *s);
int pop(struct stack *s);
int peek(struct stack *s);
int main()
{
    struct stack s;
    struct stack s1;
    initstack(&s);
    initstack(&s1);
    int n,e,i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&e);
        push(&s,e);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&e);
        push(&s1,e);
    }
    check(&s,&s1);
}

void initstack(struct stack *s)
{
    s->top=-1;
}

int isFull(struct stack *s)
{
    if(s->top==max-1)
        return 1;
    else
        return 0;
}
void push(struct stack *s,int e)
{
    s->top++;
    s->elements[s->top]=e;
}
int isEmpty(struct stack *s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}
int pop(struct stack *s)
{
    int e;
    e=s->elements[s->top];
    s->top--;
    return e;
}
int peek(struct stack *s)
{
    int e;
   e=s->elements[s->top];
    return e;
}
void check(struct stack *s,struct stack *s1)
{
    int e,e1,a[max];
    int i=0,temp;
    int c1=0;
    int c=0;
    while(!isEmpty(&s1))
    {
        e=pop(&s);
        e1=pop(&s1);
        if(e<0 && e1>0)
        {
            a[i]=1;
            i++;
        }
        else if(e>0 && e1<0)
        {
            a[i]=1;
            i++;
        }
        else
        {
            a[i]=0;
            i++;
        }
    }
    temp=i;
    for(i=0;i<temp;i++)
    {
        printf("%d ",a[i]);
        if(a[i]==1)
        {
            c1++;
        }
        else
        {
            c++;
        }
    }
    printf("\n%d\n",c1);
    printf("%d",c);

}
