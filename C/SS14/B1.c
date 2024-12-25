#include <stdio.h>

int linearSearch(int arr[],int findValue,int length){
    for (int i = 0; i < length; i++)
    {
        if (arr[i]==findValue)
        {
            return i;
        }
    }
} 
int main(){
    int arr[]={1,2,3,4,5,6,7,8};
    int value;
    int length= sizeof(arr)/sizeof(int);
    printf("Nhap gia tri muon tim trong mang: \n");
    scanf("%d",&value);
    printf("Vi tri cua phan tu do trong mang la %d",linearSearch(arr,value, length) );
}