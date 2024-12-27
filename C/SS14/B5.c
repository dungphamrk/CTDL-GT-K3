#include <stdio.h>
int insertionSort(int arr[],int n){
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j= i-1;
        while (j<0&& arr[j]<key)
        {
            arr[j]=arr[j-1];
            j=j-1;
        }
        arr[j+1]=key;
    }
    
}
int main(){
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d]=", i);
        scanf("%d", &arr[i]);
    }
    printf("Before\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n After\n");

    insertSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}