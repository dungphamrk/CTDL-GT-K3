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
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
}