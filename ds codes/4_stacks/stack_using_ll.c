#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void push(int d)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("memory full\n");
        return;
    }
    if (head == NULL)
    {
        temp->data = d;
        temp->next = NULL;
        head = temp;
        return;
    }
    temp->data = d;
    temp->next = head;
    head = temp;
    return;
}

void pop()
{
    if (head == NULL)
    {
        printf("Stack empty\n");
        return;
    }
    struct node *temp = head;
    head = temp->next;
    free(temp);
}

void peek()
{
    printf("The top most element of the stack is %d\n", head->data);
}
void traverse()
{
    if (head == NULL)
    {
        printf("Stack empty\n");
        return;
    }
    printf("\ncurrent status of Stack\n------------------------------------------------\n");
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d \n", temp->data);
        temp = temp->next;
    }
    printf("------------------------------------------------\n");
}

int main()
{
    int choice;
    printf("Enter 1 for push operation\n");
    printf("Enter 2 for pop operation\n");
    printf("Enter 3 for traversal operation\n");
    printf("Enter 4 for peek operation\n");
    printf("Enter 5 for exit operation\n");
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
            push(data);
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            traverse();
            break;
        }
        case 4:
        {
            peek();
            break;
        }
        case 5:
        {
            break;
        }
        default:
        {
            printf("enter valid choice\n");
            break;
        }
        }

    } while (choice != 5);
    printf("programe sucessfully executed");
    return 0;
}