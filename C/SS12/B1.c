#include <stdio.h>
int main()
{
    int max, n;
    printf("Nhap so phan tu cua mang : \n");
    scanf("%d", &n);
    int arr[n];
    if (n == 0)
    {
        printf("ko co gia tri lon nhat");
        return 0;
    }
    printf("Nhap lan luot tung phan tu trong mang");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    printf("%d", max);
}