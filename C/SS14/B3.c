#include <stdio.h>
int bubleSort(int arr[], int n)
{
    int i, j, temp;
    int count = 0;
    for (i = 0; i < n - 1; i++)
    {
        int swapped = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        count++;
        if (!swapped)
        {
            break;
        }
    }
    printf("Sap xep hoan thanh sau %d lan lap.\n", count);
    printf("Mang da duoc sap xep: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[] = {3, 2, 1, 8, 9, 5, 4, 12, 32, 11, 22};
    int n = sizeof(arr) / sizeof(int);
    bubleSort(arr, n);
}