#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void insert_end(int d)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
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
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    temp->data = d;
    ptr->next = temp;
    temp->next = NULL;
}
void reverse()
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
void traverse()
{
    if (head == NULL)
    {
        printf("list empty\n");
        return;
    }
    printf("\ncurrent status of linked list\n");
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int n;
    printf("enter the no of elements you want in the linked list : ");
    scanf("%d",&n);
    printf("Enter the linked list\n");
    for (int i = 0; i < n; i++)
    {
        int d;
        scanf("%d",&d);
        insert_end(d);
    }
    reverse();
    printf("\nafter reversal\n");
    traverse();
    return 0;
}