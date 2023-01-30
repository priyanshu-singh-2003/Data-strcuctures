#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void diplay()
{
    if (front == NULL)
    {
        printf("Queue empty\n");
        return;
    }
    struct node *ptr;
    ptr = front;
    printf("current status of queue\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr= ptr->next;
    }
    printf("\n");
}

void delete ()
{
    if (front == NULL)
    {
        printf("underflow");
        return;
    }
    struct node *temp = front;
    front = front->next;
    free(temp);
}

void insert(int d)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("memory full");
        return;
    }

    if (front == NULL)
    {
        ptr->data = d;
        ptr->next = NULL;
        front = ptr;
        rear = ptr;
        return;
    }
    ptr->data = d;
    ptr->next = NULL;
    rear->next = ptr;
    rear = ptr;
}

int main()
{
    int choice;
    printf("Enter 1 for insertion operation\n");
    printf("Enter 2 for deletion operation\n");
    printf("Enter 3 for traversal operation\n");
    printf("Enter 4 for exit operation\n");
    do
    {
        printf("Enter choice : \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int data;
            printf("Enter data\n");
            scanf("%d", &data);
            insert(data);
            break;
        }
        case 2:
        {
            delete ();
            break;
        }
        case 3:
        {
            diplay();
            break;
        }

        case 4:
        {
            break;
        }
        default:
        {
            printf("enter valid choice\n");
            break;
        }
        }

    } while (choice != 4);
    printf("programe sucessfully executed");
    return 0;
}