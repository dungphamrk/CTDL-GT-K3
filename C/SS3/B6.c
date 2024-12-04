#include <stdio.h>
int tinhTong(int *arr,int length){
    if (length==-1)
    {
        return 0;
    }
    return tinhTong(arr,length-1)+arr[length];
}
int main (){
    int n;
    printf("Nhap vao so phan tu cua mang\n");
    scanf("%d",&n);
    int arr[n];
    printf("Nhap vao tung phan tu cua mang ");
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d]:",i);
        scanf("%d",&arr[i]);
    }
    printf("%d",tinhTong(arr,n-1));
}
