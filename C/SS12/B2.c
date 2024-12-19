#include <stdio.h>
int main()
{
    int min, n;
    printf("Nhap so phan tu cua mang : \n");
    scanf("%d", &n);
    int arr[n];
    if (n == 0)
    {
        printf("ko co gia tri nho nhatnhat");
        return 0;
    }
    printf("Nhap lan luot tung phan tu trong mang");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    min = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    printf("%d", min);
}