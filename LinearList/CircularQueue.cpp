#include <iostream>

using namespace std;

#define MAX_SIZE 5

struct Node
{
    int data[MAX_SIZE];
    int front;
    int rear;
};

Node * initQueue()
{
    Node * n = new Node;
    n->front = n->rear = 0;
    return n;
}

bool isEmpty(Node * n)
{
    if (n->front == n->rear)//todo
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(Node * n)
{
    if ((n->rear + 1) % MAX_SIZE == n->front)//todo a % b 的结果范围在0到b-1之间
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool enQueue(Node * n, int data)
{
    if (isFull(n))
    {
        return false;
    }
    else
    {
        n->data[n->rear] = data;
        n->rear = (n->rear + 1) % MAX_SIZE;//todo
        return true;
    }
}

int deQueue(Node * n)
{
    if (isEmpty(n))
    {
        return -1;  
    }
    else
    {
        int data = n->data[n->front];
        n->front = (n->front + 1) % MAX_SIZE;//todo
        return data;
    }
}

void printQueue(Node * n)
{
    int legth = (n->rear - n->front + MAX_SIZE) % MAX_SIZE;//todo
    int index = n->front;

    for (int i = 0; i < legth; i++)
    {
        printf("Queue %d = %d\n", index, n->data[index]);
        index = (index + 1) % MAX_SIZE;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    Node * q = initQueue();
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);
    enQueue(q, 4);
    printQueue(q);
    deQueue(q);
    deQueue(q);
    printQueue(q);
    enQueue(q,5);
    enQueue(q,6);
    printQueue(q);
    return 0;
}
