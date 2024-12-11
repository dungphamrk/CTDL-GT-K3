#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int data[MAX];
    int front;
    int rear;
} Queue;

void createQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q)
{
    return (q->rear + 1) % MAX == q->front;
}

int isEmpty(Queue *q)
{
    return q->front == -1;
}

void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Hang doi da day");
        return 0;
    }
    if (isEmpty(q))
    {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Hang doi rong");
        return 0;
    }
    int value = q->data[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX;
    }
    return value;
}
void printfQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Hang doi rong.\n");
        return;
    }
    printf("Hang doi: ");
    int i = q->front;
    while (1)
    {
        printf("%d ", q->data[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main()
{
    Queue q;
    createQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printfQueue(&q);

    printf("Phan tu da bi loai bo: %d\n", dequeue(&q));
    printfQueue(&q);

    enqueue(&q, 40);
    printfQueue(&q);

    return 0;
}