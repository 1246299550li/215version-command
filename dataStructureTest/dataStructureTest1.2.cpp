#include <iostream>
#include <cstdio>
#include <string>
#include <ctime>
using namespace std;
typedef struct node
{
    string cityName;
    int x, y;
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
        linkList insNode = new lNode;
        
        insNode->cityName = "city" + to_string(i + 1);
        insNode->x = rand() % 100;
        insNode->y = rand() % 100;
        insNode->next = head->next;
        head->next = insNode;
    }
    cout << n <<" citys are be created" << endl;
    return true;
}
// 查找某个元素
int findList(linkList *L, string value)
{
    linkList p = (*L);
    if (!p || !p->next)
    {
        return -1;
    }
    int pos = 0;
    while (p->cityName != value && p)
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
        cout << "position:(" << p->x << "," << p->y << ")" << endl;
        return pos;
    }
}
// 查找一个点距离d内的所有城市
void findCityList(linkList *L, int x, int y, double dis)
{
    cout << "all city < d" << endl;
    linkList p = (*L);
    if (!p || !p->next)
    {
        cout << "void" << endl;
        return;
    }
    p = p->next;
    while (p)
    {
        double pDis = (p->x - x) * (p->x - x) + (p->y - y) * (p->y - y);
        if (pDis < dis * dis)
        {
            cout << "cityName:" << p->cityName << endl;
        }
        p = p->next;
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
            cout << "num:" << pos << "  cityName:" << p->cityName << "  position:(" << p->x << "," << p->y << ")" << endl;

            // printf("num:%d cityName:%s position:(%d,%d)\n", pos, p->cityName, p->x, p->y);
        }
        pos++;
        p = p->next;
    }
}
int main()
{
    linkList head = new lNode;
    createList(&head, 10);
    printList(&head);
    printf("----------------------\n");
    int pos = findList(&head, "city5");
    printf("pos:%d\n", pos);
    printf("----------------------\n");
    findCityList(&head, 20, 20, 30);
    system("pause");
    return 0;
}
