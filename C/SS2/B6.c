#include <stdio.h>
int main()
{
    int n;
    printf("Nhap so phan tu cua mang 1 \n");
    scanf("%d", &n);
    int arr1[n];
    printf("nhap tung phan tu cua mang 2\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    int m;
    printf("Nhap so phan tu cua mang 2 \n");
    scanf("%d", &m);
    int arr2[m];
    printf("nhap tung phan tu cua mang 1 \n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr2[i]);
    }
    int size1 = sizeof arr1, length1 = sizeof arr1 / sizeof(int);
    int size2 = sizeof arr2, length2 = sizeof arr2 / sizeof(int);
    int result[length1 + length2];
    memcpy(result, arr1, size1);
    memcpy(&result[length1], arr2, size2);
    printf("%d\n",size1);
    for (int i = 0; i < length1+length2; i++)
    {
        printf("%d ", result[i]);
    }
}