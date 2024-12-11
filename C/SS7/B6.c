#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Deque
{
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

Deque *createDeque()
{
    Deque *q = (Deque *)malloc(sizeof(Deque));
    q->front = -1;
    q->rear = 0;
    q->size = 0;
    return q;
}

int isEmpty(Deque *q)
{
    return q->size == 0;
}

int isFull(Deque *q)
{
    return q->size == MAX;
}

void pushFront(Deque *q, int value)
{
    if (isFull(q))
    {
        printf("Hang doi da day!\n");
        return;
    }

    if (q->front == -1)
    {
        q->front = q->rear = 0;
    }
    else if (q->front == 0)
    {
        q->front = MAX - 1;
    }
    else
    {
        q->front--;
    }
    q->arr[q->front] = value;
    q->size++;
}

void pushRear(Deque *q, int value)
{
    if (isFull(q))
    {
        printf("Hang doi da day!\n");
        return;
    }

    if (q->front == -1)
    {
        q->front = q->rear = 0;
    }
    else if (q->rear == MAX - 1)
    {
        q->rear = 0;
    }
    else
    {
        q->rear++;
    }
    q->arr[q->rear] = value;
    q->size++;
}

int popFront(Deque *q)
{
    if (isEmpty(q))
    {
        printf("Hang doi rong!\n");
        return -1;
    }

    int value = q->arr[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else if (q->front == MAX - 1)
    {
        q->front = 0;
    }
    else
    {
        q->front++;
    }
    q->size--;
    return value;
}

int popRear(Deque *q)
{
    if (isEmpty(q))
    {
        printf("Hang doi rong!\n");
        return -1;
    }

    int value = q->arr[q->rear];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else if (q->rear == 0)
    {
        q->rear = MAX - 1;
    }
    else
    {
        q->rear--;
    }
    q->size--;
    return value;
}

void displayDeque(Deque *q)
{
    if (isEmpty(q))
    {
        printf("Hang doi rong!\n");
        return;
    }

    int i = q->front;
    printf("Hang doi hien tai");
    while (1)
    {
        printf("%d ", q->arr[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    Deque *q = createDeque();
    printf("Them phan tu vao dau: 10");
    pushFront(q, 10);
    printf("Them phan tu vao cuoi: 20");
    pushRear(q, 20);

    displayDeque(q);

    printf("Lay phan tu dau: %d\n", popFront(q));
    displayDeque(q);

    printf("Lay phan tu cuoi: %d\n", popRear(q));
    displayDeque(q);

    return 0;
}
