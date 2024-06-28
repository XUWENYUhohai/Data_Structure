#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node * front;//头节点的当做头指针
    struct Node * rear;//头节点的当做尾指针
}; 

Node * initQueue()
{
    Node * Q = new Node;
    Q->data = 0;
    Q->front = Q;
    Q->rear = Q;
}

void enQueue(Node * Q, int data)
{
    Node * n = new Node;
    n->data = data;
    n->front = Q->rear;
    n->rear = Q;

    Q->data++;
    if (Q->front == Q)
    {
        Q->front = n;//头指针
    }
    else
    {
        Q->rear->rear = n;
    }

    Q->rear = n;//尾指针
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
        Node * temp_ptr = Q->front;
        int temp_data = temp_ptr->data;
        Q->front = temp_ptr->rear;
        Q->front->front = Q;
        Q->data--;
        delete temp_ptr;
        // delete(temp_ptr);
        return temp_data;
    }
}

void printQueue(Node * Q)
{
    Node * n = Q->front;
    while (n != Q)
    {
        printf("%d -> ", n->data);
        n = n->rear;
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
