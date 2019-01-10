#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;

} lNode, *linkList;
// ��ͷ�巨��������
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
    cout << "��ͷ�巨��������ɹ�" << endl;
    return true;
}
// ������ĵ�psoλ�ò�������
bool insertList(linkList *L, int pos, int elem)
{
    linkList p = (*L);
    // ����Ϊ�գ��ڵ�1��λ�ò���һ���µĽڵ㣻
    if (p->next == NULL)
    {
        linkList insNode = (linkList)malloc(sizeof(lNode));
        insNode->data = elem;
        insNode->next = NULL;
        p->next = insNode;
        return true;
    }
    // ����ǿյ�����£�������posλ�ò���ڵ�
    int j = 0;
    while (p && j < pos - 1)
    {
        j++;
        p = p->next;
    }
    // �������������ĳ��ȷ���false��
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

// ɾ����posλ�ý��
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
// ����ĳ��Ԫ��
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
//��ӡ����
void printList(linkList *L)
{
    linkList p = (*L);
    if (!p || !p->next)
    {
        printf("����һ��������.\n");
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
    printf("��λ��5��������99999\n");
    insertList(&head, 5, 99999);
    printList(&head);
    printf("----------------------\n");
    printf("����99999��λ��\n");
    int pos = findList(&head, 99999);
    printf("pos:%d\n", pos);
    printf("----------------------\n");
    printf("ɾ��99999\n");
    deleteList(&head, pos);
    printList(&head);
    system("pause");
    return 0;
}
