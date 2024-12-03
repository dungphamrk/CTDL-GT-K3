#include <stdio.h>
int main()
{
    int n;
    printf("Nhap so phan tu cua mang \n");
    scanf("%d", &n);
    int arr[n];
    printf("nhap tung phan tu cua mang \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int x;
    printf("nhap phan tu can xoa trong mang\t");
    int count = 0;
    scanf("%d", &x);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            arr[i] = 0;
            count++;
        }
    }
    if (count)
    {
        printf("Mang sau khi thuc hien xoa la ");
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 0)    
            {
                printf("%d\t", arr[i]);
            }
        }
    }else{
        printf("Ko co phan tu do ton tai trong mang");
    }
}