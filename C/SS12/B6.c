#include <stdio.h>

void countOfRep(int arr[], int n) {
    int count[1000] = {0}; 
    int hasDuplicates = 0;
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (count[arr[i]] > 1) {
            printf("Phan tu %d xuat hien %d lan.\n", arr[i], count[arr[i]]);
            count[arr[i]] = 0; 
            hasDuplicates = 1;
        }
    }
    if (!hasDuplicates) {
        printf("Khong co phan tu lap lai.\n");
    }
}

int main() {
    int n;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    int arr[n];

    printf("Nhap cac phan tu cua mang: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    countOfRep(arr, n);
    return 0;
}
