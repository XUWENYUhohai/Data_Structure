#include <iostream>

using namespace std;

typedef struct Node
{
    struct Node * pre;
    struct Node * next;
    int data;
};

Node * initList()
{
    Node * L = new Node;
    L->data = 0;
    L->pre = NULL;
    L->next = NULL;
    return L;
}

void headInsert(Node *L, int data)
{
    Node * h = new Node;
    h->data = data;
    h->pre = L;
    h->next = L->next;

    L->data++;
    if (L->next)
    {
        L->next->pre = h;
        L->next = h;
    }
    else
    {
        L->next = h;
    }
}

void tailInsert(Node * L, int data)
{
    Node * t = new Node;
    t->data = data;
    t->next = NULL;

    Node * temp = L;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    t->pre = temp;

    temp->next = t;

    L->data++;
}

bool Delete(Node * L, int data)
{
    Node * temp_pre = L;
    Node * temp_cur = L->next;
    while (temp_cur)
    {
        if (temp_cur->data == data)
        {
            temp_pre->next = temp_cur->next;

            if (temp_cur->next)
            {
                temp_cur->next->pre = temp_pre;
            }

            delete temp_cur;
            temp_cur = temp_pre->next;
            L->data--;
        }
        else
        {
            temp_pre = temp_cur;
            temp_cur = temp_cur->next;
        }
    }
    
    return true;
}

int printList(Node * L)
{
    Node * temp = L->next;
    while (temp)
    {
        printf("Node = %d\n", temp->data);
        temp = temp->next;
    }
}

int main(int argc, char const *argv[])
{
    Node * L = initList();
    headInsert(L, 4);
    headInsert(L, 3);
    headInsert(L, 3);
    headInsert(L, 2);
    headInsert(L, 1);
    tailInsert(L, 5);
    tailInsert(L, 6);
    tailInsert(L, 6);
    tailInsert(L, 7);
    headInsert(L, 0);

    Delete(L, 3);
    Delete(L, 6);
    printList(L);

    return 0;
}
