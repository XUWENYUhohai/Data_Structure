#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node * next;
};

Node * initStack()
{
    Node * S = new Node;
    // Node * S = (Node *)malloc(sizeof(Node));
    
    S->data = 0;
    S->next = NULL;

    return S;
}

bool isEmpty(Node * S)
{
     if (S->data == 0 || S->next == NULL)
     {
        return 1;
     }
     else
     {
        return 0;
     }
}

int pop(Node * S)
{
    if (S->data == 0)
    {
        return -1;
    }
    else
    {
        Node * n = S->next;
        int data = n->data;
        S->next = n->next;
        S->data--;
        // free(n);
        delete n;
        return data;
    }
}

void push(Node * S, int data)
{
    Node * n = new Node;
    n->data = data;
    n->next = S->next;

    S->next = n;
    S->data++;
}

void printStack(Node * S)
{
    Node * n = S->next;
    while (n)
    {
        printf("stack data = %d\n", n->data);
        n = n->next;
    }
}

int main(int argc, char const *argv[])
{
    Node * S = initStack();
    push(S, 1);
    push(S, 2);
    push(S, 3);
    printStack(S);

    printf("pop stack = %d\n", pop(S));
    printf("pop stack = %d\n", pop(S));
    printf("pop stack = %d\n", pop(S));
    printf("pop stack = %d\n", pop(S));
    cout << pop(S) << endl;
    return 0;
}
