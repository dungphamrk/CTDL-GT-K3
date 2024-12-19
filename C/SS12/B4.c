#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
    int score;
} Student;

int main() {
    int n;
    Student students[MAX];
    char searchName[50];
    int found = 0;

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap ten va diem sinh vien %d: ", i + 1);
        scanf("%s %d", students[i].name, &students[i].score);
    }

    printf("Nhap ten sinh vien can tim");
    scanf("%s", searchName);

    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("Diem cua %s la: %d\n", students[i].name, students[i].score);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Ko tim thay sinh vien.\n");
    }

    return 0;
}
