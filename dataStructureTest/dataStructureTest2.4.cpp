/*
*dataStructureTest2.4.cpp
*À≥–Ú’ª µœ÷¿®∫≈∆•≈‰
*
*
*
*/
#include <iostream>
#include <cstdio>
#include <cstring>
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
        printf("«Î ‰»Î¿®∫≈\n");
        char data[500];
        scanf("%s", data);
        int length = strlen(data);
        if (length % 2)
        {
            printf("¥À¥Æ¿®∫≈∆•≈‰≤ª∫œ∑®\n");
            system("pause");
            return 0;
        }
        else
        {
            for (int i = 0; i < length; i++)
            {

                if (data[i] == '[')
                {
                    push(tmp, 1);
                }
                else if (data[i] == '(')
                {
                    push(tmp, 2);
                }
                if (data[i] == ')')
                {
                    int out;
                    pop(tmp, out);
                    if (out != 2)
                    {
                        printf("¥À¥Æ¿®∫≈∆•≈‰≤ª∫œ∑®\n");
                        system("pause");
                        return 0;
                    }
                }
                else if (data[i] == ']')
                {
                    int out;
                    pop(tmp, out);
                    if (out != 1)
                    {
                        printf("¥À¥Æ¿®∫≈∆•≈‰≤ª∫œ∑®\n");
                        system("pause");
                        return 0;
                    }
                }
            }
            printf("∆•≈‰\n");
        }
    }
    system("pause");
    return 0;
}
