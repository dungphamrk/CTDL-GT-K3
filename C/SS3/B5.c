#include <stdio.h>
#include <string.h>
int kiemTraChuoiDoiXung(char *str, int start, int end)
{
    if (start >= end)
    {
        return 0;
    }
    if (str[start] != str[end])
    {
        return kiemTraChuoiDoiXung(str, start + 1, end - 1);
    }
    else
    {
        return 1;
    }
}
int main()
{
    char str[100];
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    if (kiemTraChuoiDoiXung(str, 0, strlen(str) - 1))
    {
        printf("Palindrome valid");
    }
    else
    {
        printf("Palindrome invalid");
    }
}