#include <stdio.h>
#include <stdlib.h>

// insertion at front
// deletion at end
struct employee_node
{
    int empcode;
    struct employee_node *prev;
    struct employee_node *next;
};
struct employee_node *head;

void traverse()
{
    if (head == NULL)
    {
        printf("list empty\n");
        return;
    }
    printf("current status of linked list\n");
    struct employee_node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->empcode);
        temp = temp->next;
    }
    printf("\n");
}
void insertion_at_front(int code)
{
    struct employee_node *temp = (struct employee_node *)malloc(sizeof(struct employee_node));

    if (temp == NULL)
    {
        printf("memory full\n");
        return;
    }

    if (head == NULL)
    {
        temp->empcode = code;
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        return;
    }

    temp->empcode = code;
    temp->next = head;
    head->prev = temp;
    temp->prev = NULL;
    head = temp;
}
void deletion_at_end()
{
    if (head == NULL)
    {
        printf("linked list empty\n");
        return;
    }
    struct employee_node *temp;
    if (head->next == NULL)
    {
        head = NULL;
        free(head);
        return;
    }
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}
int main()
{
    int choice;
    printf("Enter 1 for traversal operation\n");
    printf("Enter 2 for insetion at begining operation\n");
    printf("Enter 3 for deletion at end operation\n");
    printf("Enter 4 for exit operation\n");

    do
    {
    printf("CHOICE : ");
    scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            traverse();
            break;
        }
        case 2:
        {
            printf("Enter emplyee code\n");
            int empcode;
            scanf("%d", &empcode);
            insertion_at_front(empcode);
            break;
        }
        case 3:
        {
            deletion_at_end();
            break;
        }
        case 4:
            break;
        default:
        {
            printf("enter a valid choice\n");
            break;
        }
        }
    } while (choice != 4);
    printf("program successfully executed");
    return 0;
}