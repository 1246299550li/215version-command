/*
*dataStructureTest2.1
*顺序栈的实现
*
*
*/
#include <iostream>
#include <cstdio>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
using namespace std;
typedef struct node
{
    int *base;
    int *top;
    int stackSize;
} sqStack;
bool initStack(sqStack &S)
{
    S.base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
    if (!S.base)
    {
        return false;
    }
    S.top = S.base;
    S.stackSize = STACK_INIT_SIZE;
    return true;
}
bool getTop(sqStack S, int &e)
{
    if (S.top == S.base)
    {
        return false;
    }
    e = *(S.top - 1);
    return true;
}

bool stackEmpty(sqStack S)
{
    if (S.top == S.base)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool push(sqStack &S, int e)
{
    if (S.top - S.base >= S.stackSize)
    {
        S.base = (int *)realloc(S.base, (S.stackSize + STACKINCREMENT) * sizeof(int));
        if (!S.base)
        {
            return false;
        }
        S.top = S.base + S.stackSize;
        S.stackSize += STACKINCREMENT;
    }
    *(S.top++) = e;
    return true;
}
bool pop(sqStack &S, int &e)
{
    if (S.top == S.base)
    {
        return false;
    }
    e = *--S.top;
    return true;
}

int main()
{
    sqStack tmp;
    if (initStack(tmp))
    {
        for (int i = 0; i < 10; i++)
        {
            push(tmp, i);
            cout << i << "入栈" << endl;
        }
        for (int i = 0; i < 6; i++)
        {
            int res;
            pop(tmp, res);
            printf("%d出栈\n", res);
        }
    }
    system("pause");
    return 0;
}
