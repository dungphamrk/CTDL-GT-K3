#include <stdio.h>
int main()
{
    int n;
    printf("Nhap so phan tu cua mang : \n");
    scanf("%d", &n);
    int arr[n];
    if (n == 0)
    {
        printf("Ko co phan tu doi xung.");
        return 0;
    }
    printf("Nhap lan luot tung phan tu trong mang: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n / 2; i++)
    {
        if (arr[i] == arr[n - 1 - i])
        {
            printf("Cap doi xung :(%d,%d)\nn", arr[i] ,arr[n - i]);
        }
    }
}