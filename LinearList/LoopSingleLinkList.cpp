#include <iostream>

using namespace std;

typedef struct Node
{
    int data;
    struct Node * next;
};

Node * initList()
{
    Node * L = new Node;
    L->data = 0;
    L->next = L;

    return L;
}

void headInsert(Node * L, int data)
{
    Node * h = new Node;
    h->data = data;
    h->next = L->next;//末端指向头结点

    L->data++;
    L->next = h;
}

void tailInsert(Node * L, int data)
{
    Node * temp = L;
    while (temp->next != L)
    {
        temp = temp->next;
    }

    Node * t = new Node;
    t->data = data;
    t->next = L;

    temp->next = t;
    L->data++;   
}

bool Delete(Node * L, int data)
{
    Node * pre = L;
    Node * cur = L->next;

    while (cur != L)
    {
        if (cur->data == data)
        {   
            pre->next = cur->next;
            delete cur;
            cur = pre->next;
            L->data--;
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
    }

    return true;
}

int printList(Node * L)
{
    Node * temp = L->next;
    while (temp != L)
    {
        printf("node = %d\n", temp->data);
        temp = temp->next;
    }
}

int main(int argc, char const *argv[])
{
    Node * L = initList();
    headInsert(L, 3);
    headInsert(L, 3);
    headInsert(L, 2);
    headInsert(L, 1);
    tailInsert(L, 4);
    tailInsert(L, 5);
    tailInsert(L, 5);
    tailInsert(L, 6);
    headInsert(L, 0);

    Delete(L, 3);
    Delete(L, 5);

    printList(L);
    return 0;
}
