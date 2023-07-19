#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct devotee
{
    int age;
    struct devotee *next;
} *Node;
Node getnode()
{
    Node newnode;
    newnode = (Node)malloc(sizeof(struct devotee));
 //   scanf("%d",&newnode->age);
    return newnode;
}
Node insert_begin(Node head,Node newnode)
{


    Node temp=head;
    newnode->next=temp;
    head=newnode;
    return head;
}
int  max(Node head)
{
    Node temp=head;
    Node prev=head;
    int max=0;
    max=prev->age;

   while(temp!=NULL)
    {

       if(temp->age > max)
       {
           max=temp->age;
       }

       temp=temp->next;

    }

    return max;

}
Node delete_(Node head, int max)
{
    Node cur;
    if(head->age == max)
    {
       cur = head;
        head=head->next;
        free(cur);
        return head;
    }
    Node temp=head->next;
    Node prev=head;
    while(temp!=NULL)
    {
        if(temp->age==max)
        {
            prev->next=temp->next;
            free(temp);
            break;
        }
        else
        {
            temp=temp->next;
            prev=prev->next;
        }
    }
    return head;
}
void display(Node head)
{
    Node temp=head;

    printf("Remaining devotees: ");
    while(temp!=NULL)
    {

        printf("%d ",temp->age);
        temp=temp->next;
    }
}
int main() {

    Node head=NULL;
    int m=0;
    int i;
    int n;
    int age;
    Node newnode;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
      newnode=getnode();
      scanf("%d",&age);
      newnode->age=age;
      head=insert_begin(head,newnode);
    }
    m=max(head);
    printf("Allowed for worship: %d\n",m);
    head=delete_(head,m);
    display(head);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
