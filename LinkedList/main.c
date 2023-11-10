#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int Length(struct Node *p)
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

void Insert(struct Node *p, int index, int x)
{
    if (index < 0 || index > Count(p))
        return;

    struct Node *t = malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0) 
    {
        t->next = first;
        first = t;
    }
    else 
    {
        for (int i = 1; i < index; i++)
            p = p->next;

        t->next = p->next;
        p->next = t;        
    }
}

void SortedInsert(struct Node *p, int x)
{
    struct Node *t = malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    struct Node *q = NULL;

    if (first == NULL)
        first = t;
    else
    {
        while (x > p->data && p != NULL)
        {
            q = p;
            p = p->next;
        }

        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            q->next = t;
            t->next = p;
        }
    }
}

int Delete(struct Node *p, int index)
{
    if (index < 0 || index >= Length(p))
        return -1;

    int x;
    struct Node *q = NULL;

    if (index == 0)
    {
        x = p->data;
        first = first->next;
        free(p);
        return x;
    }

    for (int i = 0; i < index; i++)
    {
        q = p;
        p = p->next;
    }

    q->next = p->next;
    x = p->data;
    free(p);

    return x;
}

bool IsSorted(struct Node *p)
{
    while (p->next != NULL)
    {
        if (p->data > p->next->data)
            return false;
            
        p = p->next;
    }

    return true;
}

void RemoveDuplicates(struct Node *p)
{
    struct Node *q = p->next;

    while (q != NULL)
    {
        if (q->data != p->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

int main()
{
    Insert(first, 0, 1);
    Insert(first, 1, 5);
    Insert(first, 2, 5);
    Insert(first, 3, 10);
    Insert(first, 4, 16);

    SortedInsert(first, 12);
    SortedInsert(first, 12);
    SortedInsert(first, 0);

    Display(first);
    printf("\n");
    RemoveDuplicates(first);
    Display(first);
}
