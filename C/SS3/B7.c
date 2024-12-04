int tinhToHop(int n, int k)
{
    if (k == 0)
    {
        return 1;
    }
    if (n == k)
    {
        return 1;
    }
    return tinhToHop(n - 1, k - 1) + tinhToHop(n - 1, k);
}
int main()
{
    printf("Nhap lan lupt 2 so n va k");
    int n;
    scanf("%d", &n);
    int k;
    scanf("%d", &k);
    printf("%d", tinhToHop(n, k));
}