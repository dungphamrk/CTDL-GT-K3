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
    printf("mang dao nguoc cua mang vua duoc nhap vao la \n");
    for (int i = n-1; i >= 0; i--)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}