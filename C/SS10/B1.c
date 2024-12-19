#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;           
    struct Node* next;  
} Node;

Node* createNode() {
    return NULL;  
}

Node* insertHead(Node* head, int value) {
    Node* moi = (Node*)malloc(sizeof(Node));
    moi->data = value;
    moi->next = head;
    return moi;
}

Node* insertTail(Node* head, int value) {
    Node* moi = (Node*)malloc(sizeof(Node));
    moi->data = value;
    moi->next = NULL;
    if (head == NULL) {
        return moi;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = moi;
    return head;
}

Node* delHead(Node* head) {
    if (head == NULL) return NULL;
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* delLast(Node* head) {
    if (head == NULL || head->next == NULL) {
        free(head);
        return NULL;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

void find(Node* head, int value) {
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Tim thay phan tu: %d\n", value);
            count = 1;
            break;
        }
        temp = temp->next;
    }
    if (!count) {
        printf("Khong tim thay phan tu: %d\n", value);
    }
}

void printf(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeNodeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* danhSach = createNode();
    int luaChon, value;

    do {
        printf("\nMenu:\n");
        printf("1. Them vao dau danh sach\n");
        printf("2. Them vao cuoi danh sach\n");
        printf("3. Xoa phan tu dau\n");
        printf("4. Xoa phan tu cuoi\n");
        printf("5. Tim kiem phan tu\n");
        printf("6. Hien thi danh sach\n");
        printf("7. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                printf("Nhap gia tri can them vao dau: ");
                scanf("%d", &value);
                danhSach = insertHead(danhSach, value);
                break;
            case 2:
                printf("Nhap gia tri can them vao cuoi: ");
                scanf("%d", &value);
                danhSach = insertTail(danhSach, value);
                break;
            case 3:
                danhSach = delHead(danhSach);
                printf("Da xoa phan tu dau danh sach.\n");
                break;
            case 4:
                danhSach = delLast(danhSach);
                printf("Da xoa phan tu cuoi danh sach.\n");
                break;
            case 5:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                find(danhSach, value);
                break;
            case 6:
                printf("Danh sach hien tai: ");
                printf(danhSach);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                freeNodeList(danhSach);
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (luaChon != 7);

    return 0;
}
