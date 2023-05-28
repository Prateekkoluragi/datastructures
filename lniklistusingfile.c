#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

void initialize(struct LinkedList* list) {
    list->head = NULL;
}

void insertAtEnd(struct LinkedList* list, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    printf("Data inserted at the end of the list.\n");
}

int deleteAtStart(struct LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return -1;
    } else {
        struct Node* temp = list->head;
        list->head = list->head->next;
        int deletedData = temp->data;
        free(temp);
        printf("Node deleted from the start of the list.\n");
        return deletedData;
    }
}

void display(struct LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
    } else {
        struct Node* current = list->head;
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct LinkedList linkedList;
    initialize(&linkedList);
    FILE * fp1;FILE* fp2; FILE * fp3;FILE * optr ;
    int p,t,q,i,num;
    fp1=fopen("generate.txt","w+");
    optr = fopen("opertaion.txt","w");
    printf("Enter the value of a  and  b  \n");
    scanf("%d %d",&p,&q);

    printf("Enter the value of t  ");

    scanf("%d",&t);
    fprintf(optr,"Generated elements: ");

    for(i=0;i<t;i++)

    {

    num = (rand() % (p - q +1))+ p;

    printf("%d\n ",num);

    fprintf(fp1,"%d ",num);
    fprintf(optr,"%d ",num);

    }
    fprintf(optr,"\n");
    fclose(fp1);
        fp1=fopen("generate.txt","r");

    fp2=fopen("insert.txt","w");
    fp3 = fopen("delete.txt","w");

    int choice, data;

    while (1) {
        printf("\nSelect an operation:\n");
        printf("1. Insert at the end\n");
        printf("2. Delete at the start\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data: ");
                fscanf(fp1,"%d",&data);
                fprintf(fp2,"%d  ",data);
                insertAtEnd(&linkedList, data);

                break;

            case 2:
                data=deleteAtStart(&linkedList);
                fprintf(fp3,"%d\n",data);
                         fprintf(optr,"deleted element is : %d \n",data);
                break;

            case 3:
                display(&linkedList);
                break;

            case 4:
                printf("Program exited.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}
