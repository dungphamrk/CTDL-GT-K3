#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
typedef struct Node *node;

node createNode(int data)
{
    node temp = (node)malloc(sizeof(struct Node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

void splitList(node head, node *evenHead, node *oddHead)
{
    *evenHead = NULL;
    *oddHead = NULL;
    node evenTail = NULL, oddTail = NULL;

    while (head != NULL)
    {
        if (head->data % 2 == 0)
        { // Nút có giá trị chẵn
            node newNode = createNode(head->data);
            if (*evenHead == NULL)
            {
                *evenHead = newNode;
                evenTail = newNode;
            }
            else
            {
                evenTail->next = newNode;
                newNode->prev = evenTail;
                evenTail = newNode;
            }
        }
        else
        { // Nút có giá trị lẻ
            node newNode = createNode(head->data);
            if (*oddHead == NULL)
            {
                *oddHead = newNode;
                oddTail = newNode;
            }
            else
            {
                oddTail->next = newNode;
                newNode->prev = oddTail;
                oddTail = newNode;
            }
        }
        head = head->next;
    }
}

void printList(node head)
{
    while (head != NULL)
    {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(node head)
{
    while (head != NULL)
    {
        node temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    node head = NULL, tail = NULL;

    printf("Nhap cac phan tu cua danh sach lien ket doi:\n");
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        node temp = createNode(x);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    printf("Danh sach ban dau: ");
    printList(head);

    node evenHead, oddHead;
    splitList(head, &evenHead, &oddHead);

    printf("Danh sach cac phan tu chan: ");
    printList(evenHead);

    printf("Danh sach cac phan tu le: ");
    printList(oddHead);

    // Giải phóng bộ nhớ
    freeList(head);
    freeList(evenHead);
    freeList(oddHead);

    return 0;
}
