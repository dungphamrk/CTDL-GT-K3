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
    printf("Nhap x");
    scanf("%d",&x);
    int count=0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==x)
        {
            count++;
        }
    }
    printf("so lan xuat hien cua so do trong mang la %d",count);
    return 0;
}