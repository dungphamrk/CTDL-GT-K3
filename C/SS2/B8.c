#include <stdio.h>
int main()
{
    int n;
    printf("Nhap so phan tu cua mang \n");
    scanf("%d", &n);
    int arr[n];
    printf("nhap tung phan tu cua mang \n");
    for (int i = 0; i < n-1; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i]+1 != i)
        {
            printf("so can tim la %d",i);
        }
    }
    
}