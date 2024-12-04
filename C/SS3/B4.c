#include <stdio.h>
#include <string.h>
void daoNguocChuoi(char *str, int start, int end) {
    if (start >= end) {
        return; 
    }
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    daoNguocChuoi(str, start + 1, end - 1);
}
int main(){
    char str[100];
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin); 
    daoNguocChuoi(str,0,strlen(str)-1);
    printf("%s",str);
}