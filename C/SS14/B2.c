#include <stdio.h>
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
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int value;
    int length = sizeof(arr) / sizeof(int);
    printf("Nhap gia tri muon tim trong mang: \n");
    scanf("%d", &value);
    int left = 0;
    printf("Vi tri cua phan tu do trong mang la %d", binarySearch(arr, left, length, value));
}