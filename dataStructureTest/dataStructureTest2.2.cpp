/*
*dataStructureTest2.2.cpp
*˳��ѭ�����У�����һ��Ԫ�ؿռ䣬Լ���ԡ�����ͷָ���ڶ���βָ�����һλ�ã���״����һλ�ã��ϡ���Ϊ���С�����״̬�ı�־
*
*/
#include <iostream>
#include <cstdio>
using namespace std;

#define MAXSIZE 30
typedef struct
{
    char data[MAXSIZE];
    int front; //ͷָ��
    int rear;  //βָ��
} sqQueue;

//��ʼ��һ���ն���
void initQueue(sqQueue &Q)
{
    Q.front = Q.rear = 0;
}

//����г���
int getQueueLength(sqQueue Q)
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

//��Ӳ�����βָ�����
void enQueue(sqQueue &Q, char e)
{
    if (Q.front == (Q.rear + 1) % MAXSIZE)
    {
        printf("������������Ӳ���ʧ�ܣ�\n");
        return;
    }
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
}

//���Ӳ�����ͷָ�����,e���س���Ԫ��ֵ
void deQueue(sqQueue &Q, char &e)
{
    if (Q.front == Q.rear)
    {
        printf("�����ѿգ����Ӳ���ʧ�ܣ�\n");
        return;
    }
    e = Q.data[Q.front];
    printf("Ԫ��%c����\n", e);
    Q.front = (Q.front + 1) % MAXSIZE;
}

//������Ӳ�������һ�����У�������n��Ԫ��
void createQueue(sqQueue &Q, int n)
{
    int i = 0;
    printf("������%d���ַ�����Ԫ�أ�\n", n);
    while (i < n)
    {
        char e;
        scanf("%c", &e);
        enQueue(Q, e);
        i++;
        getchar(); //�Ե��س���
    }
}

void printQueue(sqQueue Q)
{
    printf("��ӡ���У�");
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

    printf("ִ����Ӳ�����");
    printf("��������Ҫ��ӵ��ַ�Ԫ�أ�");
    char e;
    scanf("%c", &e);
    enQueue(Q, e);
    printQueue(Q);

    printf("ִ�г��Ӳ�����");
    deQueue(Q, e);
    printQueue(Q);
    system("pause");
    return 0;
}
