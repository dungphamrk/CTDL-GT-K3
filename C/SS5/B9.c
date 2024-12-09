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
void printCircularList(node head, int n)
{
    node currentNode = head;
    for (int i = 0; i < n; i++)
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
     for (int i = 0; i < n; i++)
    {
        node temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
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
    convertToCircular(&head);
    printf("Danh sach lien ket vua nhap: ");
    printCircularList(head,n);
}