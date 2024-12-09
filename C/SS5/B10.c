#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *pre;
};
typedef struct Node *node;
node createNode(int data)
{
    node newNode = (node)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->pre = NULL;
    return newNode;
}
void convertToCircular(node *head)
{
    node temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node tail = temp;
    temp = *head;
    temp->pre = tail;
    tail->next = temp;
}
void printList(node head)
{
    node currentNode = head;
    while (currentNode != NULL)
    {
        printf("%d", currentNode->data);
        if (currentNode->next != NULL)
        {
            printf(" <-> ");
        }
        currentNode = currentNode->next;
    }
    printf(" <-> NULL\n");

    currentNode = head;
    while (currentNode != NULL)
    {
        node temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }
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
                newNode->pre = evenTail;
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
                newNode->pre = oddTail;
                oddTail = newNode;
            }
        }
        head = head->next;
    }
}
int main()
{
    int n;
    printf("Nhap so phan tu cua danh sach lien ket: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Danh sach trong");
        return 0;
    }
    node head = NULL;
    node tail = NULL;
    node evenHead=NULL;
    node oddHead=NULL;
    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        node newNode = createNode(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->pre = tail;
            tail = newNode;
        }
    }

    printf("Danh sach lien ket vua nhap: ");
    splitList(&head,&evenHead,&oddHead);
    printList(head);

}