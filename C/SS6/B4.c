#include <stdio.h>
#include <stdbool.h>

#define MAX 100 

typedef struct {
    int data[MAX];
    int top; 
} Stack;

bool isEmpty(Stack *s) {
    return s->top == -1;
}

bool isFull(Stack *s) {
    return s->top == MAX - 1;
}

bool push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Ngan xep day!\n");
        return false;
    }
    s->data[++(s->top)] = value;  
    return true;
}

bool pop(Stack *s, int *value) {
    if (isEmpty(s)) {
        printf("Ngan xep rong!\n");
        return false;
    }
    *value = s->data[(s->top)--];  
    return true;
}

bool peek(Stack *s, int *value) {
    if (isEmpty(s)) {
        printf("Ngan xep rong!\n");
        return false;
    }
    *value = s->data[s->top];
    return true;
}

void printStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Ngan xep rong!\n");
        return;
    }
    printf("Cac phan tu cua stack:\n ");
    for (int i = s->top ; i >=0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    (&s)->top=-1;

    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        int value;
        scanf("%d",&value);
        push(&s,value);
    }
    int value;
    if (peek(&s,&value))
    {
        printf("Phan tu tren cung: %d\n",value);
    }
    
    return 0;
}
