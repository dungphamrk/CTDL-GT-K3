int tinhSoDuongDi(int n,int m){
    if (m==1||n==1)
    {
        return 1;
    }
    return tinhSoDuongDi(n-1,m)+tinhSoDuongDi(n,m-1);
}

int main(){
    int n;
    scanf("%d",&n);
    int m;
    scanf("%d",&m);
    printf("So duong di trong ma tran la %d",tinhSoDuongDi(n,m));
}