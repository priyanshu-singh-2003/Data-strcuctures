#include <stdio.h>
 
int main()
{
 int n,i,k;
    int arr[20];
    printf("Enter the no of elements in your array\n");
    scanf("%d", &n);
    printf("Enter the array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element you want to find in the array\n");
    scanf("%d",&k);
    int flag = 0;
    for (int i = 0; i < n ; i++)
    {
        if(arr[i]==k){
            printf("Element found at %d position\n",i+1);
            flag = 1;
            break;
        }
    }
    if(flag==0){
        printf("element not found\n");
    }
    

 return 0;
}