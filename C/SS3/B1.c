#include <stdio.h>
int tinhGiaiThua(int n){
    if (n==1)
    {
        return 1;
    }
    return tinhGiaiThua(n-1)*n;
}
int main (){
    int n;
    printf("Nhap vao so can tinh giai thua\n");
    scanf("%d",&n);
    printf("%d", tinhGiaiThua(n));
}
