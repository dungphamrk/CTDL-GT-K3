#include <stdio.h>
void selectionSort(int arr[], int n)
{
    int min = arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        int minId = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minId])
            {
                minId = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minId];
        arr[minId] = temp;
    }
}
int main()
{
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d]=", i);
        scanf("%d", &arr[i]);
    }
    printf("Before\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n After\n");

    selectionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}