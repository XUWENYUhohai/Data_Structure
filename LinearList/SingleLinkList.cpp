#include <iostream>

using namespace std;
/**
 * define the struct of list node
 */
typedef struct Node
{
    int data;
    struct Node * next;
}Node;


/**
 * init a link list
 * @return the head pointer of link list's head
 */
Node * initList()
{
    // Node * L = (Node *)malloc(sizeof(Node));
    Node * L = new Node;
    L->data = 0;
    L->next = NULL;
    return L;
}

/**
 * insert item in link list's head  头插
 * @param L the head pointer of link list
 * @param data  the data you want to insert
 */
void headInsert(Node * L, int data)
{
    // Node * h = (Node *)malloc(sizeof(Node));   //todo malloc: https://blog.csdn.net/weixin_72357342/article/details/133971625
    Node * h = new Node;
    h->data = data;
    h->next = L->next;

    L->data++;
    L->next = h;
}

/**
 * insert item in link list's tail  尾插
 * @param L the head pointer of link list
 * @param data the data you want to insert
 */
void tailInsert(Node * L, int data)
{

    Node * n = L;
    //1
    // for (int i = 0; i < L->data; i++)
    // {
    //     n = n->next;
    // }

    //2
    while (n->next)
    {
        n = n->next;
    }
    
    


    // Node * t = (Node *)malloc(sizeof(Node));
    Node * t = new Node;
    t->data = data;
    t->next = NULL;

    n->next = t;
    L->data++;
}

/**
 * delete item in link list   
 * @param L the head pointer of link list
 * @param data the data you want to delete
 * @return success flag
 */
bool Delete(Node * L, int data)
{
    Node * pre = L;
    Node * cur = L->next;

    //无重复元素
    // while (cur)
    // {
    //     if (cur->data == data)
    //     {
    //         pre->next = cur->next;
    //         // free(cur);
    //         delete cur;//todo free: https://blog.csdn.net/u011386173/article/details/134696316
    //         L->data--;
    //         return true;
    //     }

    //     pre = cur;
    //     cur = cur->next;
    // }
    
    // return false;

    //有重复元素
    while (cur)
    {
        if (cur->data == data)
        {
            pre->next = cur->next;
            // free(cur);
            delete cur;//todo free: https://blog.csdn.net/u011386173/article/details/134696316
            L->data--;
            // return true;
            cur = pre->next;
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }

        
    }
    
    return false;
}   

void printList(Node * L)
{
    Node * node = L->next;
    while (node)
    {
        printf("node = %d\n", node->data);
        node = node->next;
    } 
}





int main(int argc, char const *argv[])
{
    Node * L = initList();
    headInsert(L,1);
    headInsert(L,2);
    headInsert(L,3);
    headInsert(L,4);
    tailInsert(L,5);
    tailInsert(L,7);
    tailInsert(L,8);
    tailInsert(L,7);
    tailInsert(L,7);
    headInsert(L,4);
    tailInsert(L,1);

    Delete(L,3);
    Delete(L,7);

    printList(L);
    return 0;
}
