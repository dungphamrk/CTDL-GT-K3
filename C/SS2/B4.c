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
    int count=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i]<arr[j])
            {
                count=arr[i];
                arr[i]=arr[j];
                arr[j]=count;
            }
        }
    }
    printf("day mang da duoc sap xep tang dan la\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
}