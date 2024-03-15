#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int val; 
    struct Node *next;
    struct Node *prev;
} Node;

void add_last(Node *n, int val);
void freeAll(Node *head);

int main()
{
    Node *n = malloc(sizeof(Node));

    add_last(n, 1);
    add_last(n, 2);
    add_last(n, 3);

    while (n != NULL)
    {
        printf("Node val: %d  ", n->val);
        printf("Node prev: %p  ", n->prev);
        printf("Node next: %p\n", n->next);
        n = n->next;
    }

    freeAll(n);
    return 0;
}

void add_last(Node *n, int val)
{
    if (n->prev == NULL && n->next == NULL && n->val == 0) // first element
    {
        n->val = val;
    }
    else if (n->next != NULL)
    {
        Node *last;
        do {
            n = n->next;  
            last = n; 
        } while (n->next != NULL);

        last->next = malloc(sizeof(Node));
        Node *tmp = last->next;
        tmp->val = val;
    } else 
    {
        Node *last;
        n->next = last = malloc(sizeof(Node));
        last->prev = n;
        last->val = val;
    }
    
}

void freeAll(Node *head) {
    Node *temp;
    while (head != NULL)
    {
       temp = head;
       head = head->next;
       free(temp); 
    }

    temp = NULL;
    while (head != NULL)
    {
        temp = head;
        head = head->prev;
        free(temp);   
    }
    temp = NULL;
}
