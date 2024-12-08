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
int maxNodeOfList(node *head)
{

    node temp = *head;
    int max = temp->data;

    while (temp != NULL)
    {
        if (temp->data > max)
        {
            max = temp->data;
        }
        temp = temp->next;
    }

    return max;
}
int main()
{
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    node head = NULL;
    node tail = NULL;
    if (n <= 0)
    {
        printf("Danh sach trong");
    }
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
    printf("%d", maxNodeOfList(&head));
    free(head);
    free(tail);
}
