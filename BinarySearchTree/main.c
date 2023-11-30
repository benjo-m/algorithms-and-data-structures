#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

void Insert(int key)
{
    struct Node *t = root;
    struct Node *r, *p;

    if (root == NULL)
    {
        p = malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    
    while(t != NULL)
    {
        r = t;

        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else 
            return;
    }

    p = malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if (key < r->data) r->lchild = p;
    else r->rchild = p;
}

void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

struct Node* Search(int key)
{
    struct Node *t = root;

    while (t != NULL)
    {
        if (t->data == key)
            return t;
        else if (t->data < key)
            t = t->rchild;
        else
            t = t->lchild;
    }

    return NULL;
}

int main() {
    struct Node *temp;
    
    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);

    Inorder(root);

    
    printf("\n");

    temp = Search(22);

    if (temp)
        printf("element found: %d", temp->data);
    else
        printf("element is not found");

    return 0;
}
