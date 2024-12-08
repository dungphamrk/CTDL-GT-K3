#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node *node;
node createNode(int data)
{
    node temp = (node)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void reverseNodeList(node *head)
{
    node prev = NULL;       // Con trỏ giữ nút trước
    node current = *head;   // Con trỏ duyệt nút hiện tại
    node next = NULL;       // Con trỏ giữ nút tiếp theo

    while (current != NULL)
    {
        next = current->next;  
        current->next = prev;  
        prev = current;        
        current = next;        
    }

    *head = prev;
}
int main()
{
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    node head = NULL;
    node tail = NULL;

    printf("Nhap lan luot tung phan tu cua danh sach lien ket:\n");
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        node temp = createNode(x); // Tạo nút mới
        if (head == NULL)
        {
            head = temp; // Nút đầu tiên
            tail = temp;
        }
        else
        {
            tail->next = temp; // Nối nút mới vào cuối danh sách
            tail = temp;       // Gán node cuối vào đuôi để lần lượt thêm vào từ node đó khi mà head vẫn đang giữ giá trị của node đầu tiên
        }
    }
    reverseNodeList(&head);
    printf("Danh sach lien ket vua nhap: ");
    node currentNode = head;
    while (currentNode != NULL)
    {
        printf("%d -> ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL");
    free(currentNode);
    free(head);
    free(tail);
}
