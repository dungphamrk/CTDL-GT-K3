#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Node *node;

typedef struct Stack
{
    node top;
} Stack;
typedef struct Stack *stack;

int isEmpty(stack stack)
{
    return stack->top == NULL;
}

void push(stack stack, int value)
{
    node newNode = (node)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(stack stack)
{
    if (isEmpty(stack))
    {
        printf("Ngan xep trong\n");
        return -1;
    }
    node temp = stack->top;
    int value = temp->data;
    stack->top = temp->next;
    free(temp);
    return value;
}

int peek(stack stack)
{
    if (isEmpty(stack))
    {
        printf("Stack rỗng!\n");
        return -1;
    }
    return stack->top->data;
}

void freeStack(stack stack)
{
    while (!isEmpty(stack))
    {
        pop(stack);
    }
    printf("Đã giải phóng bộ nhớ stack.\n");
}
void printStack(stack stack){
    if (isEmpty(stack))
    {
        printf("Stack rỗng!\n");
        return 0;
    }
    node temp=stack->top;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main()
{
    Stack stack;
    stack.top = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Phan tu tren cung la: %d\n", peek(&stack));

    pop(&stack);

    printf("Phan tu tren cung sau khi xoa: %d\n", peek(&stack));
    printf("Cac phan tu con lai trong stack la: ");
    printStack(&stack);
    return 0;
}
