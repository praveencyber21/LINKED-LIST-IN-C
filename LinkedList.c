#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtBeginning(int data)
{
    struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));
    if(newNode == NULL)
    {
        printf("Memory Not Allocated\n");
        return;
    }

    //If head is empty, this block is executed
    if(head == NULL)
    {
        newNode -> data = data;
        newNode -> next = NULL;
        head = newNode;
    }
    else
    {
        newNode -> data = data;
        newNode -> next = head;
        head = newNode;
    }
    printf("Data Inserted\n");

}

void display()
{   
    struct Node* temp = head;

    //Check list is empty or not
    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    
    while(temp != NULL)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;

    }
    printf("\n");
}

void insertAtPosition(int pos, int data)
{
    struct Node* temp;
    struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));

    if(newNode == NULL)
    {
        printf("Memory Not Allocated\n");
        return;
    }

    temp = head;
    // First we traverse to the prev position
    for(int i=1; i<pos; i++)
    {
        temp = temp -> next;
    }
        newNode -> data = data;
        newNode -> next = temp -> next;
        temp -> next = newNode;
}

void deleteAtPosition(int pos)
{
    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    
    struct Node* prev;
    struct Node* temp;

    temp = head;
    //Traverse to the position and also prev position
    for(int i=1; i<=pos; i++)
    {

        prev = temp;
        temp = temp -> next;
    }

    prev -> next = temp -> next;
    free(temp);
}
int main()

{
    int choice, data, pos;
    

    while(1)
    {

        printf("------------Linked List Menu----------------\n");
        printf("1. Insert At Beginning\n");
        printf("2. Insert At Specific Position (start at 0)\n");
        printf("3. Delete From Specifc Position\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("\n------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) 
        {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter the position: ");
                scanf("%d", &pos);
                printf("Enter the data: ");
                scanf("%d", &data);

                if(pos == 0)
                {
                    insertAtBeginning(data);
                }
                else
                {
                    insertAtPosition(pos, data);
                }
                break;

            case 3:
                printf("Enter the position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}