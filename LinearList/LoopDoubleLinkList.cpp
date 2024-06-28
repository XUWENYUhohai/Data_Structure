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
    L->pre = L;
    L->next = L;
    return L;
}

void headInsert(Node * L, int data)
{
    Node * h = new Node;
    h->data = data;
    h->pre = L;
    h->next = L->next;

    //! 不用分情况
    // if (L->next)
    // {
    //     h->next = L->next;
        
    // }
    // else
    // {
    //     h->next = L;

    //     L->pre = h;
    // }

    L->next->pre = h;
    L->next = h;
    L->data++;
}

void tailInsert(Node * L, int data)
{
    Node * t = new Node;
    t->data = data;
    t->next = L;
    t->pre = L->pre;

    L->pre->next = t;
    L->data++;
    L->pre = t;
}

bool Delete(Node * L, int data)
{
    Node * temp_pre = L;
    Node * temp_cur = L->next;

    while (temp_cur != L)
    {
        if (temp_cur->data == data)
        {
            temp_pre->next = temp_cur->next;
            delete temp_cur;
            temp_cur = temp_pre->next;
            temp_cur->pre = temp_pre; 
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
    while (temp != L)
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
    headInsert(L, 2);
    headInsert(L, 2);
    tailInsert(L, 5);
    tailInsert(L, 6);
    Delete(L, 2);
    Delete(L, 5);
    tailInsert(L, 6);
    headInsert(L, 1);

    printList(L);
    return 0;
}
