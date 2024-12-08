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
void deleteFirstNode(node *head)
{
    if (*head == NULL)
    {
        return NULL;
    }
    node temp = (*head)->next;
    *head = temp;
}
int main()
{
    int n;
    printf("Nhap so phan tu cua danh sach lien ket ");
    scanf("%d", &n);
    if (n==0)
    {
        printf("Danh sach trong");
    }
    node head = NULL;
    node tail = NULL;

    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        node temp = createNode(data);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    deleteFirstNode(&head);
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