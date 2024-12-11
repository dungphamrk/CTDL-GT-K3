#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue
{
    int data[MAX];
    int front;
    int rear;
};
typedef struct Queue Queue;
void createQueue(Queue *q)
{
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
        q->rear = -1;
    }
    q->front = (q->front + 1) % MAX;
    return value;
}
int peek(Queue *q){
       if (isEmpty(q))
    {
        printf("Hang doi rong");
        return 0;
    }
    return q->data[q->front];
}
int main()
{
    Queue q;
    createQueue(&q);
    enqueue(&q, 10);
    printf("phan tu o tren dau  tien cua hang doi la: %d",peek(&q));
    enqueue(&q, 20);
    printf("phan tu o tren dau  tien cua hang doi la: %d",peek(&q));
    enqueue(&q, 30);
    printf("phan tu o tren dau  tien cua hang doi la: %d",peek(&q));
    if (!isEmpty(&q))
    {
        printf("Hang doi ko rong");
    }
    printfQueue(&q);
}