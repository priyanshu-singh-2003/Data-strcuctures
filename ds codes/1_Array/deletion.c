#include <stdio.h>
 
int main()
{
    int n, p,i;
    int arr[20];
    printf("Enter the no of elements in your array\n");
    scanf("%d", &n);
    printf("Enter the array\n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the position at which you want to delete an element in the array\n");
    scanf("%d", &p);
    printf("Array before insertion\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    for ( i = p; i < n; i++)
    {
        arr[i-1]=arr[i];
    }
    n=n-1;
    printf("\nArray after deletion\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
 return 0;
}