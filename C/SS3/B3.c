#include <stdio.h>
#include <stdlib.h>
int tinhFibonaci(int n, int *arr) {
    if (arr[n] != -1) {
        return arr[n];
    }
  
    if (n == 1 || n == 0) {
        arr[n] = n;
        return arr[n];
    }

    int a = tinhFibonaci(n - 1, arr);
    int b = tinhFibonaci(n - 2, arr);

    arr[n] = a + b; 
    return arr[n];
}

int main(){
    int n;
    printf("Nhap vao so lan hien thi so fibonaci\n");
    scanf("%d",&n);
    int *arr = (int *)malloc((n + 1) * sizeof(int));

    for (int i = 0; i <= n; i++) {
        arr[i] = -1;
    }

    int result = tinhFibonaci(n, arr);

    printf("Day Fibonacci:\n");
    for (int i = 0; i <= n; i++) {
        printf("%d", arr[i]);
        if (i!=n)
        {
            printf(",");
        }
        
    }

    free(arr);
}