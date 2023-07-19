#include<stdio.h>
#include<stdlib.h>

typedef struct devotee
{
    int age;
    char name[20];
    int gender;
    struct devotee *next;
}*NODE;
NODE getnode();
NODE insert_devotee(NODE head);
void display(NODE head);
NODE remove_devotee(NODE head);
int main()
{
    NODE head=NULL;
    int ch;
    while(1)
    {
        printf("1.Insert a new devotee\n");
        printf("2.Display all the female aged devotees\n");
        printf("3.Delete the devotee from the que\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head=insert_devotee(head);
                    break;
            case 2: display(head);
                    break;
            case 3: head=remove_devotee(head);
                    break;
        }
    }

}

NODE getnode()
{
    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct devotee));
    newnode->next=NULL;
    return newnode;
}

NODE insert_devotee(NODE head)
{
    NODE newnode;
    newnode=getnode();
    printf("Enter the name of the devotee\n");
    scanf("%s",newnode->name);
    printf("Enter the age of the devotee\n");
    scanf("%d",&newnode->age);
    printf("enter the gender of the devotee\n");
    scanf("%d",&newnode->gender);

    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    if(newnode->age>=80 && newnode->age<=90)
    {
        newnode->next=head;
        head=newnode;
        return head;
    }
        NODE temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        return head;
}

void display(NODE head)
{
    NODE temp=head;

    while(temp!=NULL)
    {
        if(temp->age>=80 && temp->gender==0)
        {
            printf("%s\t",temp->name);
            printf("%d\t",temp->age);
            printf("female\n");
            temp=temp->next;
        }
        temp=temp->next;
    }
}
NODE remove_devotee(NODE head)
{
    NODE temp=head;
    head=head->next;
    free(temp);
    return head;
}
