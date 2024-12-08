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

int sizeOfNodeList(node head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
void deleteFirstNode(node *head)
{
    if (*head == NULL)
        return;
    node temp = *head;
    *head = (*head)->next;
    free(temp);
}
void deleteLastNode(node *head)
{
    node temp = (*head);
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteNodeByPos(node *head, int pos)
{
    if (pos > sizeOfNodeList(*head) - 1 || pos < 0)
    {
        printf("Vi tri ko hop le");
        return;
    }
    if (pos == 0)
    {
        deleteFirstNode(head);
        return;
    }

    if (pos == sizeOfNodeList(*head) - 1)
    {
        deleteLastNode(head);
        return;
    }

    int count = 0;
    node temp = *head;
    while (temp->next != NULL)
    {
        if (pos == count + 1)
        {
            node a = temp->next;
            temp->next = a->next;
            free(a);
            return;
        }
        temp = temp->next;
        count++;
    }
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

    int pos;
    printf("Nhap vi tri can xoa: ");
    scanf("%d", &pos);
    deleteNodeByPos(&head, pos);
    printf("Danh sach lien ket sau khi thuc hien xoa: ");
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
