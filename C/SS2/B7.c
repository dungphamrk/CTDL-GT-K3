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
    int k;
    printf("Nhap tong can tim  ");
    scanf("%d",&k);
    //sắp xếp
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
    // xử lý 
    int left=0;
    int right=n-1;
      while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == k) {
            printf("Cặp số: (%d, %d)\n", arr[left], arr[right]);
            left++;
            right--;
        } else if (sum < k) {
            left++;
        } else {
            right--;
        }
    }
}