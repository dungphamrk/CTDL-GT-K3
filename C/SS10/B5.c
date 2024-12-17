#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node của cây nhị phân
typedef struct Node {
    int data;               // Dữ liệu của Node
    struct Node* left;      // Con trỏ trỏ đến Node con bên trái
    struct Node* right;     // Con trỏ trỏ đến Node con bên phải
} Node;

// Hàm khởi tạo một Node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Khong the cap phat bo nho\n");
        return NULL;
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Hàm thêm phần tử vào cây nhị phân
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);  // Nếu cây rỗng, tạo Node mới làm gốc
    }
    if (value < root->data) {
        root->left = insert(root->left, value);  // Thêm vào nhánh trái
    } else if (value > root->data) {
        root->right = insert(root->right, value);  // Thêm vào nhánh phải
    } else {
        printf("Phan tu %d da ton tai trong cay\n", value);
    }
    return root;
}

// Duyệt cây theo thứ tự trước (PreOrder)
void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Duyệt cây theo thứ tự giữa (InOrder)
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Duyệt cây theo thứ tự sau (PostOrder)
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Hàm tìm kiếm một phần tử trong cây
Node* search(Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Giải phóng bộ nhớ của cây nhị phân
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Menu chương trình
int main() {
    Node* root = NULL;  // Khởi tạo cây rỗng
    int choice, value;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Them phan tu vao cay\n");
        printf("2. Duyet cay theo thu tu truoc (PreOrder)\n");
        printf("3. Duyet cay theo thu tu giua (InOrder)\n");
        printf("4. Duyet cay theo thu tu sau (PostOrder)\n");
        printf("5. Tim kiem phan tu trong cay\n");
        printf("6. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Duyet cay theo thu tu truoc: ");
                preOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Duyet cay theo thu tu giua: ");
                inOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Duyet cay theo thu tu sau: ");
                postOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                    printf("Tim thay phan tu %d trong cay\n", value);
                } else {
                    printf("Khong tim thay phan tu %d trong cay\n", value);
                }
                break;
            case 6:
                printf("Ket thuc chuong trinh\n");
                freeTree(root);
                break;
            default:
                printf("Lua chon khong hop le, vui long nhap lai\n");
        }
    } while (choice != 6);

    return 0;
}
