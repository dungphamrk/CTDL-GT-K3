int soCachDiLen(int n){
    if (n==2)
    {
        return 2;
    }
    if (n==1)
    {
        return 1;
    }
    return soCachDiLen(n-1)+soCachDiLen(n-2);
}
int main(){
    printf("Nhap so bac thang");
    int n ;
    scanf("%d",&n);
    soCachDiLen(n);
}