#include <stdio.h>

int main()
{
    int n;
    int arr[20];
    printf("Enter the no of elements in your array\n");
    scanf("%d", &n);
    printf("Enter the array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Array entered is\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}