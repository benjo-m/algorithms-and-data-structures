#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

void Create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->arr = malloc(sizeof(int) * size);
}

void Display(struct Queue *q)
{
    for (int i = q->front + 1; i <= q->rear; i++)
        printf("%d ", q->arr[i]);
}

void Enqueue(struct Queue *q, int x)
{
    if (q->rear == q->size - 1)
        printf("Queue full\n");
    else
        q->arr[++q->rear] = x;
}

int Dequeue(struct Queue *q)
{
    if (q->front == q->rear)
        printf("Queue empty\n");
    else
        return q->arr[q->front++];
}

int main()
{
    struct Queue q;
    Create(&q, 5);
    Enqueue(&q, 3);
    Enqueue(&q, 7);
    Enqueue(&q, 19);
    Dequeue(&q);
    Display(&q);
}
