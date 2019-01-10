#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;

} lNode, *linkList;
// 用头插法建立链表
bool createList(linkList *L, int n)
{
    srand((int)time(0));
    linkList head = (*L);
    head->next = NULL;
    for (int i = 0; i < n; i++)
    {
        linkList insNode = (linkList)malloc(sizeof(lNode));
        insNode->data = rand() % 100;
        insNode->next = head->next;
        head->next = insNode;
    }
    cout << "用头插法建立链表成功" << endl;
    return true;
}
// 向链表的第pso位置插入数据
bool insertList(linkList *L, int pos, int elem)
{
    linkList p = (*L);
    // 链表为空，在第1个位置插入一个新的节点；
    if (p->next == NULL)
    {
        linkList insNode = (linkList)malloc(sizeof(lNode));
        insNode->data = elem;
        insNode->next = NULL;
        p->next = insNode;
        return true;
    }
    // 链表非空的情况下，可以在pos位置插入节点
    int j = 0;
    while (p && j < pos - 1)
    {
        j++;
        p = p->next;
    }
    // 如果超过了链表的长度返回false；
    if (!p->next || !p)
    {
        return false;
    }
    linkList insNode = (linkList)malloc(sizeof(lNode));
    insNode->data = elem;
    insNode->next = p->next;
    p->next = insNode;
    return false;
}

// 删除第pos位置结点
bool deleteList(linkList *L, int pos)
{
    linkList p = (*L);

    if (!p->next || !p)
    {
        return false;
    }
    int j = 0;
    while (p->next && j < pos - 1)
    {
        j++;
        p = p->next;
    }
    if (!p->next)
    {
        return false;
    }
    linkList pNext = p->next;
    p->next = pNext->next;
    free(pNext);
    return true;
}
// 查找某个元素
int findList(linkList *L, int value)
{
    linkList p = (*L);
    if (!p || !p->next)
    {
        return -1;
    }
    int pos = 0;
    while (p->data != value && p)
    {
        pos++;
        p = p->next;
    }
    if (!p->next)
    {
        return -1;
    }
    else
    {
        return pos;
    }
}
//打印链表
void printList(linkList *L)
{
    linkList p = (*L);
    if (!p || !p->next)
    {
        printf("这是一个空链表.\n");
    }
    int pos = 0;
    while (p)
    {
        if (pos)
        {
            printf("num:%d data:%d\n", pos, p->data);
        }
        pos++;
        p = p->next;
    }
}
int main()
{
    linkList head = (linkList)malloc(sizeof(lNode));
    createList(&head, 10);
    printList(&head);
    printf("----------------------\n");
    printf("在位置5插入数据99999\n");
    insertList(&head, 5, 99999);
    printList(&head);
    printf("----------------------\n");
    printf("查找99999的位置\n");
    int pos = findList(&head, 99999);
    printf("pos:%d\n", pos);
    printf("----------------------\n");
    printf("删除99999\n");
    deleteList(&head, pos);
    printList(&head);
    system("pause");
    return 0;
}
