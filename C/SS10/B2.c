#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;            
    struct Node* prev;   
    struct Node* next;    
} Node;

Node* head = NULL;
Node* tail = NULL;
void printMessage(const char* msg) {
    for (int i = 0; msg[i] != '\0'; i++) {
        if (msg[i] >= 'A' && msg[i] <= 'Z') printf("%c", msg[i] + 32);
        else if (msg[i] == 'đ' || msg[i] == 'Đ') printf("d");
        else printf("%c", msg[i]);
    }
    printf("\n");
}

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void addToHead(int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printMessage("da them vao dau danh sach");
}

void addToTail(int value) {
    Node* newNode = createNode(value);
    if (tail == NULL) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    printMessage("da them vao cuoi danh sach");
}

void deleteFromHead() {
    if (head == NULL) {
        printMessage("danh sach rong");
        return;
    }
    Node* temp = head;
    if (head == tail) { 
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    free(temp);
    printMessage("da xoa node dau");
}

void deleteFromTail() {
    if (tail == NULL) {
        printMessage("danh sach rong");
        return;
    }
    Node* temp = tail;
    if (head == tail) { 
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    free(temp);
    printMessage("da xoa node cuoi");
}

void printForward() {
    printMessage("danh sach tu dau den cuoi:");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printBackward() {
    printMessage("danh sach tu cuoi ve dau:");
    Node* temp = tail;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void clearList() {
    while (head != NULL) {
        deleteFromHead();
    }
    printMessage("da giai phong bo nho"); 
}

int main() {
    int choice, value;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Them node vao dau\n");
        printf("2. Them node vao cuoi\n");
        printf("3. Xoa node dau\n");
        printf("4. Xoa node cuoi\n");
        printf("5. In danh sach tu dau den cuoi\n");
        printf("6. In danh sach tu cuoi ve dau\n");
        printf("7. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri: ");
                scanf("%d", &value);
                addToHead(value);
                break;
            case 2:
                printf("Nhap gia tri: ");
                scanf("%d", &value);
                addToTail(value);
                break;
            case 3:
                deleteFromHead();
                break;
            case 4:
                deleteFromTail();
                break;
            case 5:
                printForward();
                break;
            case 6:
                printBackward();
                break;
            case 7:
                printMessage("ket thuc chuong trinh");
                clearList();
                break;
            default:
                printMessage("lua chon khong hop le");
        }
    } while (choice != 7);

    return 0;
}
