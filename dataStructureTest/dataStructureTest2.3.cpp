/*
*dataStructureTest2.3
*顺序栈实现数字转换
*
*
*
*/
#include <iostream>
#include <cstdio>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
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
    e = *(--S.top);
    return true;
}

int main()
{
    sqStack tmp;
    if (initStack(tmp))
    {
        printf("请输入十进制数\n");
        int num;
        scanf("%d", &num);
        while (num)
        {
            push(tmp, num % 8);
            num /= 8;
        }
        int out;
        printf("转化为八进制数为");
        while (!stackEmpty(tmp))
        {
            pop(tmp, out);
            printf("%d", out);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
