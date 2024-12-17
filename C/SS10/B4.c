#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node
typedef struct Node {
    int data;           // Dữ liệu của node
    struct Node* next;  // Con trỏ trỏ đến node tiếp theo
} Node;

// Định nghĩa cấu trúc Queue
typedef struct Queue {
    Node* front;        // Phần tử đầu hàng đợi
    Node* rear;         // Phần tử cuối hàng đợi
} Queue;

// Hàm khởi tạo hàng đợi
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
    printf("da khoi tao hang doi\n");
}

// Kiểm tra hàng đợi có rỗng không
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Thêm phần tử vào hàng đợi (Enqueue)
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("khong the cap phat bo nho\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {  // Hàng đợi đang rỗng
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("da them %d vao hang doi\n", value);
}

// Xóa phần tử khỏi hàng đợi (Dequeue)
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("hang doi rong, khong the xoa\n");
        return -1; // Giá trị đặc biệt khi hàng đợi rỗng
    }
    Node* temp = q->front;
    int dequeuedValue = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {  // Hàng đợi trở nên rỗng
        q->rear = NULL;
    }
    free(temp);
    printf("da xoa phan tu %d khoi hang doi\n", dequeuedValue);
    return dequeuedValue;
}

// Kiểm tra phần tử đầu hàng đợi (Peek)
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("hang doi rong\n");
        return -1; // Giá trị đặc biệt khi hàng đợi rỗng
    }
    printf("phan tu dau hang doi la: %d\n", q->front->data);
    return q->front->data;
}

// Giải phóng bộ nhớ của hàng đợi
void freeQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    printf("da giai phong bo nho cua hang doi\n");
}

// Chương trình chính
int main() {
    Queue q;    // Tạo hàng đợi
    int choice, value;

    initQueue(&q);

    do {
        printf("\n=== MENU ===\n");
        printf("1. Them phan tu vao hang doi (enqueue)\n");
        printf("2. Xoa phan tu khoi hang doi (dequeue)\n");
        printf("3. Kiem tra phan tu dau (peek)\n");
        printf("4. Kiem tra hang doi co rong khong\n");
        printf("5. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                peek(&q);
                break;
            case 4:
                if (isEmpty(&q)) {
                    printf("hang doi rong\n");
                } else {
                    printf("hang doi khong rong\n");
                }
                break;
            case 5:
                printf("ket thuc chuong trinh\n");
                freeQueue(&q);
                break;
            default:
                printf("lua chon khong hop le\n");
        }
    } while (choice != 5);

    return 0;
}
