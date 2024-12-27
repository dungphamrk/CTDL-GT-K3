#include <stdio.h>
int swap (int *i, int *j){
    int temp= *i;
    *i=*j;
    *j=temp;    
}
int patrition(int arr[],int left,int right){
    int pivot =arr[right-1];
    int i= left-1;
    for (int  j = left; j < right-1; j++)
    {
        if (arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[right-1]);
    return i+1;
}
int quickSort(int arr[], int left ,int right){
    if (left>right)
    {
        return 0;
    }
    
    int pivot=patrition(arr,left,right);

    quickSort(arr,left,pivot-1);
    quickSort(arr,pivot+1,right);
}
int main(){
    int arr[]={8,9,1,3,5,2,66,98,12};
    int n= arr[0]/sizeof(int);
    quickSort(arr,0,n);
}