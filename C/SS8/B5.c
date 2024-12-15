#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Lỗi cấp phát bộ nhớ!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

Node* searchNode(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return searchNode(root->left, key);
    }
    return searchNode(root->right, key);
}

void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Node* root = NULL;
    int choice, value;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Chen mot gia tri vao cay\n");
        printf("2. Tim kiem \n");
        printf("3. In các giá trị theo thứ tự tăng dần (Inorder)\n");
        printf("4. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhập giá trị cần chèn: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                printf("Đã chèn %d vào cây.\n", value);
                break;

            case 2:
                printf("Nhập giá trị cần tìm: ");
                scanf("%d", &value);
                if (searchNode(root, value) != NULL) {
                    printf("Tìm thấy giá trị %d trong cây.\n", value);
                } else {
                    printf("Không tìm thấy giá trị %d trong cây.\n", value);
                }
                break;

            case 3:
                printf("Cây theo thứ tự tăng dần (Inorder): ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Thoát chương trình.\n");
                break;

            default:
                printf("Lựa chọn không hợp lệ. Vui lòng thử lại!\n");
                break;
        }
    } while (choice != 4);
    freeTree(root);
    return 0;
}
