#include <stdio.h>

int main()
{
    int n, k;
    int arr[20];
    printf("Enter the no of elements in your array\n");
    scanf("%d", &n);
    printf("Enter the array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element you want to find in the array\n");
    scanf("%d", &k);
    int start = 0;
    int end = n - 1;
    int flag = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if(arr[mid]==k){
            printf("Element found at pos %d",mid+1);
            flag = 1;
            break;
        }
        else if(arr[mid]>k){
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    if (flag==0)
    {
      printf("element not found");
    }
    
    return 0;
}