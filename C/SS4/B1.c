#include <stdio.h>
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node* node;
node createNode(int x){
    node temp = (node)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;
    return temp;
}
int main(){
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    node head = NULL; 
    node tail = NULL; 

    printf("Nhap lan luot tung phan tu cua danh sach lien ket:\n");
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        node temp = createNode(x); // Tạo nút mới
        if (head == NULL) {
            head = temp; // Nút đầu tiên
            tail = temp;
        } else {
            tail->next = temp; // Nối nút mới vào cuối danh sách
            tail = temp;
        }
    }
    printf("Danh sach lien ket vua nhap: ");
    node currentNode = head;
    while (currentNode != NULL) {
        printf("%d -> ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL");
    free(currentNode);
    free(head);
    free(tail);
}