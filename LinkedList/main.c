#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void Create(int arr[], int n)
{
    int i;
    struct Node *t, *last;
    
    first = malloc(sizeof(struct Node));
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = malloc(sizeof(struct Node));
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    
}

void Display(struct Node *p)
{
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int Count(struct Node *p)
{
    int count = 0;

    while (p != NULL) {
        count++;
        p = p->next;
    }

    return count;
}

int CountRecursive(struct Node *p)
{
    if (p == NULL)
        return 0;
    
    return CountRecursive(p->next) + 1;
}

int Sum(struct Node *p)
{
    int sum = 0;

    while (p != NULL) {
        sum += p->data;
        p = p->next;
    }

    return sum;
}

int SumRecursive(struct Node *p)
{
    if (p == NULL)
        return 0;
    
    return SumRecursive(p->next) + p->data;
}

int Max(struct Node *p)
{
    int max = INT_MIN;

    while (p != NULL) {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }

    return max;
}

int MaxRecursive(struct Node *p)
{
    int x = INT_MIN;

    if (p == NULL)
        return INT_MIN;
    
    x = MaxRecursive(p->next);
    
    if (x > p->data)
        return x;
    else return p->data;
}

int LinearSearch(struct Node *p, int key)
{
    while (p != NULL) {
        if (p->data == key)
            return key;
        p = p->next;
    }

    return 0;
}

int RecursiveLinearSearch(struct Node *p, int key)
{
    if (p == NULL)
        return 0;
    
    if (p->data == key)
        return key;

    RecursiveLinearSearch(p->next, key);
}

int main()
{
    int a[] = { 2, 7, 15, 27, 32};

    Create(a, 5);

    int c = RecursiveLinearSearch(first, 7);

    printf("%d\n", c);
}