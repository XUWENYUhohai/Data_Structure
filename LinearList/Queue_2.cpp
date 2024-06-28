#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node * next;
};

Node * initQueue()
{
    Node * Q = new Node;
    Q->data = 0;
    // Q->next = nullptr;
    Q->next = nullptr;
}

void enQueue(Node * Q, int data)
{
    Node * temp = Q;
    Node * n = new Node;
    n->data = data;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    
    n->next = nullptr;
    temp->next = n;
    Q->data++;
}

bool isEmpty(Node * Q)
{
    // if (Q->data == 0 || Q->rear == Q || Q->front == Q)
    if (Q->data == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int deQueue(Node * Q)
{
    if (isEmpty(Q))
    {
        return -1;
    }
    else
    {
        Node * temp_ptr = Q->next;
        int temp_data = temp_ptr->data;
        Q->next = temp_ptr->next;
        Q->data--;
        delete temp_ptr;
        // delete(temp_ptr);
        return temp_data;
    }
}

void printQueue(Node * Q)
{
    Node * n = Q->next;
    while (n != nullptr)
    {
        printf("%d -> ", n->data);
        n = n->next;
    }

    printf("\n");
}

int main(int argc, char const *argv[])
{
    Node * Q = initQueue();
    enQueue(Q, 1);
    enQueue(Q, 2);
    enQueue(Q, 3);
    enQueue(Q, 4);
    printQueue(Q);

    cout << "deQueue = " << deQueue(Q) << endl;
    cout << "deQueue = " << deQueue(Q) << endl;
    printQueue(Q);

    cout << "deQueue = " << deQueue(Q) << endl;
    cout << "deQueue = " << deQueue(Q) << endl;
    cout << "deQueue = " << deQueue(Q) << endl;
    printQueue(Q);
    return 0;
}
