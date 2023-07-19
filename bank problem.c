 #include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct node
{
    char name[20];
    char code;
    struct node *next;
}*node;

node getnode()
{
    node newnode;
    newnode=(node)malloc(sizeof(struct node));
    newnode->next=NULL;
    return newnode;
}
node insert_end(node head,node newnode)
{
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    node temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=NULL;
    return head;
}
int main() {


    node head=NULL;
    node newnode,prev,temp1,temp;
    int i,n;
    char name[20];
    char code;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newnode=getnode();
        scanf("%s",newnode->name);
        scanf(" %c",&newnode->code);
        //strcpy(newnode->name,name);
       // newnode->code=code;

        head=insert_end(head,newnode);

    }
    prev=NULL;
    temp=head;
    while(temp!=NULL)
    {

        if(temp->code!='C')
        {
            printf("%s ",temp->name);
            prev=temp;
            temp=temp->next;


        }
        else
            {

        printf("%s",temp->name);
        prev=temp;
        temp=temp->next;
            }


    }

}
