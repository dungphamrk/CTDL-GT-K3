#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
typedef struct Node* node;
node createNode(int data){
    node temp=(node)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}
void insertNode(node *head,int data){
    node newNode = createNode(data);
    if (*head== NULL)
    {
        *head=newNode;
    }
    node temp=*head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
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
            tail = temp;  // Gán node cuối vào đuôi để lần lượt thêm vào từ node đó khi mà head vẫn đang giữ giá trị của node đầu tiên  
        }
    }
    int x;
    
    printf("Nhap vao gia tri can tren: ");
    scanf("%d",&x);
    insertNode(&head,x);
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
