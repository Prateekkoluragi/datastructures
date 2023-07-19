#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define max 100
struct stack
{
    int elements[max];
    int top;
};
void initstack(struct stack *s);
void push(struct stack *s,int e);
int pop(struct stack *s);
int peek(struct stack *s);
int isfull(struct stack *s);
int isempty(struct stack *s);
void winner(struct stack *s1,struct stack *s2);
int main() {
    struct stack s1;
    struct stack s2;
    initstack(&s1);
    initstack(&s2);
    int n;
    int e;
    int i;
    scanf("%d",&n);
    if(n>0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&e);
            push(&s1,e);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&e);
            push(&s2,e);
        }
        winner(&s1,&s2);

    }

    return 0;
}
void initstack(struct stack *s)
{
    s->top=-1;
}
void push(struct stack *s,int e)
{
    s->top++;
    s->elements[s->top]=e;
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
int isfull(struct stack *s)
{
    if(s->top==max-1)
        return 1;
    else
        return 0;
}
int isempty(struct stack *s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}
void winner(struct stack *s1,struct stack *s2)
{
    int c1=0;
    int c2=0;
    int e;
    while(!isempty(&s1))
    {
        e=pop(&s1);
        if(e%2==0)
            c1++;
    }
    while(!isempty(&s2))
    {
        e=pop(&s2);
        if(e%2==0)
            c2++;
    }
    if(c1>c2)
        printf("Vinay");
    else if(c1==c2)
        printf("Both Vinay and Pavan are the Winners");
    else
        printf("Pavan");
}
