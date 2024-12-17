#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;          
    struct Node* next; 
} Node;

typedef struct Stack {
    Node* top;          
} Stack;

void initStack(Stack* stack) {
    stack->top = NULL;
    printf("da khoi tao ngan xep\n");
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("khong the cap phat bo nho\n");
        return;
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("da them %d vao ngan xep\n", value);
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("ngan xep rong, khong the xoa\n");
        return -1; 
    }
    Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = temp->next;
    free(temp);
    printf("da xoa phan tu %d khoi ngan xep\n", poppedValue);
    return poppedValue;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("ngan xep rong\n");
        return -1; 
    }
    printf("phan tu tren cung cua ngan xep la: %d\n", stack->top->data);
    return stack->top->data;
}

void freeStack(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    printf("da giai phong bo nho cua ngan xep\n");
}

int main() {
    Stack stack;   
    int choice, value;

    initStack(&stack);

    do {
        printf("\n=== MENU ===\n");
        printf("1. Them phan tu vao ngan xep (push)\n");
        printf("2. Xoa phan tu khoi ngan xep (pop)\n");
        printf("3. Kiem tra phan tu tren cung (peek)\n");
        printf("4. Kiem tra ngan xep co rong khong\n");
        printf("5. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                peek(&stack);
                break;
            case 4:
                if (isEmpty(&stack)) {
                    printf("ngan xep rong\n");
                } else {
                    printf("ngan xep khong rong\n");
                }
                break;
            case 5:
                printf("ket thuc chuong trinh\n");
                freeStack(&stack);
                break;
            default:
                printf("lua chon khong hop le\n");
        }
    } while (choice != 5);

    return 0;
}
