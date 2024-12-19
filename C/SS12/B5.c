#include <stdio.h>

int main()
{
    int n, target, found = 0, position = -1;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nhap cac phan tu cua mang: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Nhap gia tri can tim: ");
    scanf("%d", &target);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            found = 1;
            position = i + 1;
            break;
        }
    }
    if (found)
    {
        printf("Phan tu %d nam o vi tri: %d\n", target, position);
    }
    else
    {
        printf("Khong tim thay phan tu trong mang.\n");
    }
    return 0;
}
