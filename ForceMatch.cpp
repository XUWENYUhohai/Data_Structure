#include <iostream>

using namespace std;

struct String
{
    char * data;// == char data[]
    int len;
};

String * init_String()
{
    String * S = new String;
    S->data = NULL;
    S->len = 0;
    return S;
}

void assignString(String * S, char * data)
{
    if (S->data)
    {
        delete S->data;
    }

    int len = 0;
    char * temp = data;

    while (* temp)
    {
        len++;
        temp++;
    }
    
    if (len == 0)
    {
        S->data = nullptr;
        S->len = 0;
    }
    else
    {
        temp = data;
        S->len = len;
        S->data = new char;//todo
        for (int i = 0; i < len; i++, temp++)
        {
            S->data[i] = * temp;//todo
        }
    }

}

void printStirng(String * S)
{
    for (int i = 0; i < S->len; i++)
    {
        printf(i == 0 ? " %c" : "-> %c", S->data[i]);
    }

    printf("\n");
}

int main(int argc, char *argv[])
{
    String * S = init_String();
    assignString(S, argv[1]);
    printStirng(S);
    return 0;
}
