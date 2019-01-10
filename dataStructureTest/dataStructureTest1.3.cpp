#include <iostream>
#include <cstdio>
using namespace std;

typedef struct node //����ṹ�壬
{
    int num, pwd; //num�����洢�˵���ţ�pwd�����洢�˵�����
    struct node *next;
} lNode, *linkList;

//����ѭ��������
linkList creatLinkList(int n) //����n����������
{
    int i;
    linkList head, p, pt;                  //������
    head = (lNode *)malloc(sizeof(lNode)); //����һ����ͷ��������
    if (!head)
    {
        return NULL; //�������ɹ�������NULL
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
    p->next = head; //����ѭ������
    return head;
}

//�����������뺯��
int enterPwd(linkList p, int n) //����n��������
{
    int pwd;
    printf("\n����������: \n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &pwd);
        p->num = i;   //num�洢�˵����
        p->pwd = pwd; //pwd�洢�˵�����
        p = p->next;
    }
    return pwd;
}
//�����������
int outList(linkList p, int m, int n) //����m��n���ݱ�������ֵ������
{
    int length = n;
    for (int i = 1; i <= n; i++) //��һ��forѭ������ѭ������
    {
        if (m == 1)
        {
            m += length;
        }
        for (int a = 1; a < m - 1; a++) //ɾ�����
        {
            p = p->next;
        }
        linkList del = p->next;
        m = del->pwd;
        printf("%d ", del->num); //����˵����
        p->next = del->next;
        free(del); //�ͷŶ�̬����Ľ��ռ�
        length--;
        p = p->next;
    }
    return 0;
}

int main()
{
    int m, n; //mΪ��������ֵ��nΪ����
    printf("\n����m��n���ݱ�������ֵ������;\n");
    printf("\n������ m ��n: \n");
    scanf("%d %d", &m, &n);
    linkList tmp = creatLinkList(n); //���ô���������
    enterPwd(tmp, n);                //�����������뺯��
    printf("\n���ӵ���������:\n");
    outList(tmp, m, n); //�������������
    system("pause");
    return 0;
}
