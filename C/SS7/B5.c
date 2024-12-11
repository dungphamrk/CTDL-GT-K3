#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int data;
    int priority;
} Element;

typedef struct
{
    Element elements[MAX];
    int size;
} PriorityQueue;

void initializeQueue(PriorityQueue *q)
{
    q->size = 0;
}

int isEmpty(PriorityQueue *q)
{
    return q->size == 0;
}

void enqueue(PriorityQueue *q, int data, int priority)
{
    if (q->size == MAX)
    {
        printf("Hàng đợi đầy!\n");
        return;
    }
    Element newElement = {data, priority};
    q->elements[q->size] = newElement;
    q->size++;

    for (int i = q->size - 1; i > 0; i--)
    {
        if (q->elements[i].priority > q->elements[i - 1].priority)
        {
            Element temp = q->elements[i];
            q->elements[i] = q->elements[i - 1];
            q->elements[i - 1] = temp;
        }
        else
        {
            break;
        }
    }
}

int dequeue(PriorityQueue *q)
{
    if (isEmpty(q))
    {
        printf("Hang doi rong!\n");
        return -1;
    }
    int data = q->elements[0].data;

    for (int i = 0; i < q->size - 1; i++)
    {
        q->elements[i] = q->elements[i + 1];
    }
    q->size--;
    return data;
}

int peek(PriorityQueue *q)
{
    if (isEmpty(q))
    {
        printf("Hang doi rong!\n");
        return -1;
    }
    return q->elements[0].data;
}

void display(PriorityQueue *q)
{
    if (isEmpty(q))
    {
        printf("Hang doi rong!\n");
        return;
    }
    for (int i = 0; i < q->size; i++)
    {
        printf("Data: %d, Priority: %d\n", q->elements[i].data, q->elements[i].priority);
    }
}

int main()
{
    PriorityQueue q;
    initializeQueue(&q);

    enqueue(&q, 10, 2);
    enqueue(&q, 20, 1);
    enqueue(&q, 30, 3);

    display(&q);
    printf("Phan tu co do uu tien cao nhat: %d\n", peek(&q));

    printf("Lay ra phan tu: %d\n", dequeue(&q));
    printf("Phan tu co do uu tien cao nhat: %d\n", peek(&q));
    printf("Lay ra phan tu: %d\n", dequeue(&q));

    return 0;
}
