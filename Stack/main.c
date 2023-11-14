#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

void Create(struct Stack *st)
{
    printf("Enter stack size: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->arr = malloc(st->size * sizeof(int));
}

void Display(struct Stack *st)
{
    for (int i = st->top; i >= 0; i--)
        printf("%d ", st->arr[i]);   
}

void Push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("Stack overflow\n");
    else
        st->arr[++st->top] = x; 
}

int Pop(struct Stack *st)
{
    if (st->top == -1)
        return -1;

    int x = st->arr[st->top--];
    return x;
}

int Peek(struct Stack *st, int index)
{
    int x = -1;

    if (index < 0 || index > st->size - 1)
        printf("Invalid index\n");
    else 
        x = st->arr[st->top - index + 1];

    return x;
}

int IsEmpty(struct Stack *st)
{
    return st->top == -1;
}

int IsFull(struct Stack *st)
{
    return st->top == st->size-1;
}

int Top(struct Stack *st)
{
    if (!IsEmpty(st))
        return st->arr[st->top];
    return -1;
}


int main()
{
    struct Stack st;

    Create(&st);
    Push(&st, 4);
    Push(&st, 1);
    Push(&st, 5);
    Push(&st, 3);

    printf("%d \n", Top(&st));

    Display(&st);
}
