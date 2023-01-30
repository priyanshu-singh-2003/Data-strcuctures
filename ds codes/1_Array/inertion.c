#include <stdio.h>

int main()
{
    int n, p,a,i;
    int arr[20];
    printf("Enter the no of elements in your array\n");
    scanf("%d", &n);
    printf("Enter the array\n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element you want to insert in the array\n");
    scanf("%d", &a);
    printf("Enter the position at which you want to insert the element in the array\n");
    scanf("%d", &p);
    printf("Array before insertion\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
    for (i = n; i >= p-1 ; i-- )
    {
        arr[i+1]=arr[i];
    }
    arr[p-1]=a;
    n=n+1;
    printf("\nArray after insertion\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}
// test case 4 1 3 4 5 2 2 