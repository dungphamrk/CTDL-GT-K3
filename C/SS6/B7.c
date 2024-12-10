#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 100

typedef struct
{
    char data[MAX];
    int top;
} Stack;

bool isEmpty(Stack *s)
{
    return s->top == -1;
}

bool isFull(Stack *s)
{
    return s->top == MAX - 1;
}

bool push(Stack *s, char value)
{
    if (isFull(s))
    {
        printf("Ngan xep day!\n");
        return false;
    }
    s->data[++(s->top)] = value;
    return true;
}

bool pop(Stack *s, char *value)
{
    if (isEmpty(s))
    {
        printf("Ngan xep rong!\n");

        return false;
    }
    *value = s->data[(s->top)--];
    return true;
}

bool peek(Stack *s, char *value)
{
    if (isEmpty(s))
    {
        printf("Ngan xep rong!\n");

        return false;
    }
    *value = s->data[s->top];
    return true;
}

void printStack(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Ngan xep rong!\n");
        return;
    }
    printf("Cac phan tu cua stack:\n");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%c", s->data[i]);
    }
    printf("\n");
}

int main()
{
    Stack s;
    s.top = -1;
    char string[100];
    char topChar;
    printf("Nhap chuoi: ");
    fgets(string, sizeof(string), stdin);
     string[strcspn(string, "\n")] = '\0';
    for (int i = 0; i < strlen(string); i++)
    {
        push(&s, string[i]);
    }
    for (int i = 0; i < strlen(string); i++)
    {
        pop(&s, &topChar);
        if (string[i] != topChar)
        {
            printf("Cau nay ko phai cau doi xung");
            return 0;
        }
    }
    printf("Cau nay la cau doi xung");
    return 0;
}
