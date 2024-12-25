#include <stdio.h>
int main()
{
    int n, temp;
    printf("Nhap so phan tu cua mang");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d]=", i);
        scanf("%d", &arr[i]);
    }
    printf("Before");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("After");
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}