#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void traverse()
{
    if (head == NULL)
    {
        printf("list empty\n");
        return;
    }
    printf("Current status of ll :\n");
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}
void search()
{
    int d;
    printf("enter data you want to search\n");
    scanf("%d", &d);
    struct node *temp = head;
    int flag = 0;
    int i = 0;
    while (temp != NULL)
    {
        i++;
        if (temp->data == d)
        {
            printf("element fount at post %d\n", i);
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (flag == 0)
    {
        printf("element not found\n");
    }
    return;
}
void insert_at_beg()
{
    int d;
    printf("enter data you want to insert\n");
    scanf("%d", &d);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("memory full - OVERFLOW\n");
    }
    ptr->data = d;
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
        return;
    }
    ptr->next = head;
    head = ptr;
    return;
}
void insert_at_end()
{
    int d;
    printf("enter data you want to insert\n");
    scanf("%d", &d);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("memory full - OVERFLOW\n");
    }
    ptr->data = d;
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
    return;
}
void insert_at_pos()
{
    int d, pos;
    printf("enter data you want to insert\n");
    scanf("%d", &d);
    printf("enter position at you want to insert\n");
    scanf("%d", &pos);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("memory full - OVERFLOW\n");
        return;
    }
    ptr->data = d;
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
        return;
    }
    struct node *temp = head;
    struct node *t = temp;
    int i = 0;
    for (int i = 0; i < pos - 1; i++)
    {
        t = temp;
        temp = temp->next;
    }
    ptr->next = temp;
    t->next = ptr;
    return;
}
void delete_at_beg()
{
    if (head == NULL)
    {
        printf("Nothing to delete - UNDERFLOW\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    return;
}
void delete_at_end()
{
    if (head == NULL)
    {
        printf("Nothing to delete - UNDERFLOW\n");
        return;
    }
    if (head->next == NULL)
    {
        struct node *temp = head;
        head = head->next;
        free(head);
        return;
    }
    struct node *temp = head;
    struct node *ptr = temp;
    while (temp->next != NULL)
    {
        ptr = temp;
        temp = temp->next;
    }
    ptr->next = NULL;
    free(temp);

    return;
}
void delete_at_pos()
{
    int pos;
    if (head == NULL)
    {
        printf("Nothing to delete - UNDERFLOW\n");
        return;
    }
    printf("enter the position at which you want to delete\n");
    scanf("%d", &pos);
    struct node *temp = head;
    struct node *prev = temp;
    for (int i = 1; i < pos; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);

    return;
}
int main()
{
    printf("\n\n*********Main Menu*********\n");
    printf("\nChoose one option from the following list ...\n");
    printf("\n===============================================\n");
    printf("\n0.TRAVERSE\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Search for an element\n8.Exit\n");
    int choice;
    do
    {
        printf("eneter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
        {
            traverse();
            break;
        }
        case 1:
        {
            insert_at_beg();
            break;
        }
        case 2:
        {
            insert_at_end();
            break;
        }
        case 7:
        {
            search();
            break;
        }
        case 3:
        {
            insert_at_pos();
            break;
        }
        case 4:
        {
            delete_at_beg();
            break;
        }
        case 5:
        {
            delete_at_end();
            break;
        }
        case 6:
        {
            delete_at_pos();
            break;
        }
        case 8:
        {
            break;
        }
        default:
        {
            printf("Enter valid choice");
        }
        }

    } while (choice != 9);
    return 0;
}
