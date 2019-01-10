#include <iostream>
#include <cstdio>
using namespace std;

typedef struct node //定义结构体，
{
    int num, pwd; //num用来存储人的序号，pwd用来存储人的密码
    struct node *next;
} lNode, *linkList;

//创建循环链表函数
linkList creatLinkList(int n) //参数n传递人数，
{
    int i;
    linkList head, p, pt;                  //定义结点
    head = (lNode *)malloc(sizeof(lNode)); //创建一个带头结点的链表
    if (!head)
    {
        return NULL; //创建不成功，返回NULL
    }
    p = head;
    for (i = 1; i < n; i++)
    {
        pt = (lNode *)malloc(sizeof(lNode));
        if (!pt)
        {
            return NULL;
        }
        p->next = pt;
        p = pt;
    }
    p->next = head; //构成循环链表
    return head;
}

//创建输入密码函数
int enterPwd(linkList p, int n) //参数n传递人数
{
    int pwd;
    printf("\n请输入密码: \n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &pwd);
        p->num = i;   //num存储人的序号
        p->pwd = pwd; //pwd存储人的密码
        p = p->next;
    }
    return pwd;
}
//创建输出函数
int outList(linkList p, int m, int n) //参数m、n传递报数上限值和人数
{
    int length = n;
    for (int i = 1; i <= n; i++) //用一个for循环搜索循环链表
    {
        if (m == 1)
        {
            m += length;
        }
        for (int a = 1; a < m - 1; a++) //删除结点
        {
            p = p->next;
        }
        linkList del = p->next;
        m = del->pwd;
        printf("%d ", del->num); //输出人的序号
        p->next = del->next;
        free(del); //释放动态申请的结点空间
        length--;
        p = p->next;
    }
    return 0;
}

int main()
{
    int m, n; //m为报数上限值，n为人数
    printf("\n参数m、n传递报数上限值和人数;\n");
    printf("\n请输入 m 和n: \n");
    scanf("%d %d", &m, &n);
    linkList tmp = creatLinkList(n); //调用创建链表函数
    enterPwd(tmp, n);                //调用输入密码函数
    printf("\n出队的人依次是:\n");
    outList(tmp, m, n); //调用输出链表函数
    system("pause");
    return 0;
}
