#include <stdio.h>
void selectionSort(int arr[], int n)
{
    int min = arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        int minId = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minId])
            {
                minId = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minId];
        arr[minId] = temp;
    }
}
int binarySearch(int arr[], int left, int right, int value)
{
    while (left < right)
    {
        int mid = (left + right + 1) / 2;
        if (arr[mid] == value)
        {
            return mid;
        }
        if (arr[mid] > value)
        {
           return binarySearch(arr,mid+1,right,value);
        }
        if (arr[mid] < value)
        {
            return binarySearch(arr,left,mid-1,value);
        }
    }
}
int main()
{
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d]=", i);
        scanf("%d", &arr[i]);
    }
    printf("Nhap phan tu can tim kiem :");
    int value;
    scanf("%d",&value);
    printf("Mang sau khi sap xep: \n");

    selectionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n Phan tu %d duoc tim thay tai vi tri %d",value,binarySearch(arr,0,n,value));
    
}