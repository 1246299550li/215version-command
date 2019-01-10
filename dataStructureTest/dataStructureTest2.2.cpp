/*
*dataStructureTest2.2.cpp
*顺序循环队列：少用一个元素空间，约定以“队列头指针在队列尾指针的下一位置（环状的下一位置）上”作为队列“满”状态的标志
*
*/
#include <iostream>
#include <cstdio>
using namespace std;

#define MAXSIZE 30
typedef struct
{
    char data[MAXSIZE];
    int front; //头指针
    int rear;  //尾指针
} sqQueue;

//初始化一个空队列
void initQueue(sqQueue &Q)
{
    Q.front = Q.rear = 0;
}

//求队列长度
int getQueueLength(sqQueue Q)
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

//入队操作，尾指针后移
void enQueue(sqQueue &Q, char e)
{
    if (Q.front == (Q.rear + 1) % MAXSIZE)
    {
        printf("队列已满，入队操作失败！\n");
        return;
    }
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
}

//出队操作，头指针后移,e返回出队元素值
void deQueue(sqQueue &Q, char &e)
{
    if (Q.front == Q.rear)
    {
        printf("队列已空，出队操作失败！\n");
        return;
    }
    e = Q.data[Q.front];
    printf("元素%c出队\n", e);
    Q.front = (Q.front + 1) % MAXSIZE;
}

//利用入队操作创建一个队列，他含有n个元素
void createQueue(sqQueue &Q, int n)
{
    int i = 0;
    printf("请输入%d个字符队列元素：\n", n);
    while (i < n)
    {
        char e;
        scanf("%c", &e);
        enQueue(Q, e);
        i++;
        getchar(); //吃掉回车符
    }
}

void printQueue(sqQueue Q)
{
    printf("打印队列：");
    int i = Q.front;
    while (i % MAXSIZE != Q.rear)
    {
        printf("%c ", Q.data[i]);
        i++;
    }
    printf("\n\n");
}

int main()
{
    sqQueue Q;
    initQueue(Q);
    createQueue(Q, 5);
    printQueue(Q);

    printf("执行入队操作：");
    printf("请输入您要入队的字符元素：");
    char e;
    scanf("%c", &e);
    enQueue(Q, e);
    printQueue(Q);

    printf("执行出队操作：");
    deQueue(Q, e);
    printQueue(Q);
    system("pause");
    return 0;
}
