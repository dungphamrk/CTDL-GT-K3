#include <stdio.h>
int main (){
    int n;
    printf("Nhap vao 2 so m va n\n");
    scanf("%d",&n);
    int m ;
    scanf("%d",&m);
    if (n>=m)
    {
        printf("n phai nho hon m");
        return 0;
    }
    int result=0;
    for (int i = n; i <= m; i++)
    {
        result +=i;
    }
    printf("%d",result);
}
