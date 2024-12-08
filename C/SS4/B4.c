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
int indexDataOfNode(node *head, int data)
{
    int count=0;
    node current=(*head);
    while (current->next!=NULL)
    {
        if (current->data==data)
        {
            return count;
        }
        count+=1;
        node temp=current->next;
        current=temp;
    }
    return -1;
}
int main()
{
    int n;
    printf("Nhap so phan tu cua danh sach lien ket: ");
    scanf("%d", &n);
    if (n == 0)
    {
        printf("Danh sach trong");
    }
    node head = NULL;
    node tail = NULL;
    printf("Nhap lan luot tung phan tu cua danh sach lien ket \n");
    for (int i = 0; i < n; i++)
    {   
        int x;
        scanf("%d",&x);
        node temp = createNode(x);
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
    printf("Nhap gia tri cua phan tu muon tim kiem: ");
    int searchData;
    scanf("%d", &searchData);
    printf("%d",indexDataOfNode(&head,searchData));
}