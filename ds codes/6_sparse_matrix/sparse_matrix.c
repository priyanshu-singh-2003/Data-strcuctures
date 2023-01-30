#include <stdio.h>
#include <stdlib.h>
struct element
{
    int r;
    int c;
    int val;
    struct element *next;
};
int main()
{
    int a;
    int b;
    int arr[100][100];
    printf("enter the no of rows and collumns\n");
    scanf("%d%d", &a, &b);
    printf("Enter the marix\n");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("matrix inputed\n");
    struct element *start= NULL;
    struct element *tail= NULL;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (arr[i][j] != 0)
            {
                struct element *ptr = (struct element *)malloc(sizeof(struct element));
                ptr->r = i;
                ptr->c = j;
                ptr->next = NULL;
                ptr->val = arr[i][j];
                if (start == NULL)
                {
                    start = ptr;
                    tail = ptr;
                }
                else
                {
                    tail->next = ptr;
                    tail = ptr;
                }
            }
        }
    }
    printf("Acessing the elements of our sparse matrix\nval       row          coll \n");
    struct element *temp = start;
    while (temp != NULL)
    {
        printf("%d         %d            %d \n", temp->val, temp->r, temp->c);
        temp = temp->next;
    }

    return 0;
}