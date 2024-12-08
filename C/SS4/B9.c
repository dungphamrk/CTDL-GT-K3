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
void sortNodeList(node *head)
{
    node current = *head; // Con trỏ duyệt nút hiện tại
    node next = NULL;     // Con trỏ giữ nút tiếp theo

    while (current != NULL)
    {
        next = current->next;
        if (current->data > next->data)
        {
            int temp = current->data;
            current->data = next->data;
            next->data = temp;
        }
        current = next;
    }
}
void mergeNodeList(node *head1,node *head2){
    node temp=*head1;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=*head2;
}
int main()
{
    int n;
    printf("Nhap so luong phan tu cua danh sach 1: ");
    scanf("%d", &n);

    node head1 = NULL;
    node tail1 = NULL;

    printf("Nhap lan luot tung phan tu cua danh sach lien ket:\n");
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        node temp = createNode(x); // Tạo nút mới
        if (head1 == NULL)
        {
            head1 = temp; // Nút đầu tiên
            tail1 = temp;
        }
        else
        {
            tail1->next = temp; // Nối nút mới vào cuối danh sách
            tail1 = temp;       // Gán node cuối vào đuôi để lần lượt thêm vào từ node đó khi mà head vẫn đang giữ giá trị của node đầu tiên
        }
    }
    printf("Nhap so luong phan tu cua danh sach 2: ");
    scanf("%d", &n);

    node head2 = NULL;
    node tail2 = NULL;

    printf("Nhap lan luot tung phan tu cua danh sach lien ket:\n");
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        node temp = createNode(x); // Tạo nút mới
        if (head2 == NULL)
        {
            head2 = temp; // Nút đầu tiên
            tail2 = temp;
        }
        else
        {
            tail2->next = temp; // Nối nút mới vào cuối danh sách
            tail2= temp;       // Gán node cuối vào đuôi để lần lượt thêm vào từ node đó khi mà head vẫn đang giữ giá trị của node đầu tiên
        }
    }

    printf("Danh sach lien ket vua nhap: ");
    mergeNodeList(&head1,&head2);
    sortNodeList(&head1);
    node currentNode = head1;
    while (currentNode != NULL)
    {
        printf("%d -> ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL");
    free(currentNode);
    free(head1);
    free(tail1);
}
