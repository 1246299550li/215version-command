#define INFINITY 200000000 /*����*/
#define MAX_VERTEX_NUM 40
#define MAX 40
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
typedef struct ArCell
{
    int adj;                                         //·����
} ArCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //�ڽӾ���
typedef struct                                       //ͼ�����ʾ��Ҫ�����ž����š����ơ�������Ϣ
{
    char name[20];
    int num;
    char introduction[60]; //���
} infotype;
typedef struct //ͼ�еı߱�ʾ�����ĵ�·�����·�����ȵ���Ϣ��
{
    infotype vexs[MAX_VERTEX_NUM]; //������Ϣ��
    AdjMatrix arcs;
    int vexnum, /*������*/ arcnum; //�߸���
} MGraph;
MGraph b;

void cmd(void);
MGraph InitGraph(void);
void Menu(void);
void Browser(MGraph *G);
void ShortestPath_DIJ(MGraph *G);
void Floyd(MGraph *G);
void Search(MGraph *G);
int LocateVex(MGraph *G, char *v);
MGraph *CreatUDN(MGraph *G);
void print(MGraph *G);
/******************************************************/
int main()
{
    system("color 0f");
    system("mode con: cols=130 lines=120");
    cmd();
}
/******************************************************/

void cmd(void)
{
    int i;
    b = InitGraph();
    Menu();
    scanf("%d", &i);
    while (i != 5)
    {
        switch (i)
        {
        case 1:
            system("cls");
            Browser(&b);
            Menu();
            break; //1.���У԰ȫ��
        case 2:
            system("cls");
            ShortestPath_DIJ(&b);
            Menu();
            break; //2.�鿴��������·��
        case 3:
            system("cls");
            Floyd(&b);
            Menu();
            break; //3.ȷ��������֮����̾���
        case 4:
            system("cls");
            Search(&b);
            Menu();
            break; //4.�鿴������Ϣ
        case 5:
            exit(1);
            break;
        default:
            break;
        }
        printf("���������루1-5����");
        scanf("%d", &i);
    }
}
MGraph InitGraph(void) //��ʼ��
{
    MGraph G;
    int i, j;
    G.vexnum = 16;
    G.arcnum = 40;
    for (i = 0; i < G.vexnum; i++)
        G.vexs[i].num = i;
    strcpy(G.vexs[0].name, "��У��");
    strcpy(G.vexs[0].introduction, "ס��¥");

    strcpy(G.vexs[1].name, "��У��");
    strcpy(G.vexs[1].introduction, "ѧУ����");

    strcpy(G.vexs[2].name, "У�ۺ�¥");
    strcpy(G.vexs[2].introduction, "ȫ���ʦ�칫����");

    strcpy(G.vexs[3].name, "������");
    strcpy(G.vexs[3].introduction, "������һ¥Ϊ������ë��ƹ����");

    strcpy(G.vexs[4].name, "ҽ����");
    strcpy(G.vexs[4].introduction, "Уҽ����");

    strcpy(G.vexs[5].name, "����¥");
    strcpy(G.vexs[5].introduction, "У��ѧ¥����������,����ѧϰ");

    strcpy(G.vexs[6].name, "����¥");
    strcpy(G.vexs[6].introduction, "���ѧԺ Ů������¥ λ�ں��¥�Ա�");

    strcpy(G.vexs[7].name, "����С����");
    strcpy(G.vexs[7].introduction, " ��������,������Ϣ ����");

    strcpy(G.vexs[8].name, "�ڶ���ѧ¥");
    strcpy(G.vexs[8].introduction, "����ʵ����");

    strcpy(G.vexs[9].name, "ͼ���");
    strcpy(G.vexs[9].introduction, "����145���,��ʩ���� һ¥�п����� ��������");

    strcpy(G.vexs[10].name, "���");
    strcpy(G.vexs[10].introduction, "ɶҲû");

    strcpy(G.vexs[11].name, "������ѧ¥");
    strcpy(G.vexs[11].introduction, "У������¥Ϊʵ��¥,������ ���� ���� ��ѧʵ���Һ͵��Ի���");

    strcpy(G.vexs[12].name, "ѧ���ڶ�ʳ��");
    strcpy(G.vexs[12].introduction, "�����ȽϺ� ,���˻�����");

    strcpy(G.vexs[13].name, "28������¥  ");
    strcpy(G.vexs[13].introduction, "����¥");

    strcpy(G.vexs[14].name, "16������¥  ");
    strcpy(G.vexs[14].introduction, "16����ѧУ��ԧ��¥���������붰Ů���붰¥");

    strcpy(G.vexs[15].name, "��������Ԣ");
    strcpy(G.vexs[15].introduction, "�Ա��г���");
    for (i = 0; i < G.vexnum; i++)
        for (j = 0; j < G.vexnum; j++)
            G.arcs[i][j].adj = INFINITY;
    G.arcs[0][1].adj = 80; /*·����*/
    G.arcs[1][11].adj = 110;
    G.arcs[1][2].adj = 50;
    G.arcs[1][5].adj = 90;
    G.arcs[2][11].adj = 65;
    G.arcs[2][5].adj = 90;
    G.arcs[2][10].adj = 85;
    G.arcs[2][9].adj = 90;
    G.arcs[2][3].adj = 150;
    G.arcs[5][9].adj = 80;
    G.arcs[5][3].adj = 70;
    G.arcs[5][13].adj = 40;
    G.arcs[13][8].adj = 50;
    G.arcs[13][3].adj = 100;
    G.arcs[13][5].adj = 80;
    G.arcs[8][6].adj = 55;
    G.arcs[8][7].adj = 50;
    G.arcs[6][4].adj = 55;
    G.arcs[9][10].adj = 45;
    G.arcs[9][3].adj = 65;
    G.arcs[10][14].adj = 120;
    G.arcs[10][12].adj = 150;
    G.arcs[12][14].adj = 170;
    G.arcs[10][12].adj = 170;
    G.arcs[12][15].adj = 160;
    G.arcs[9][10].adj = 150;
    G.arcs[10][12].adj = 100;
    G.arcs[12][15].adj = 160;
    G.arcs[14][7].adj = 150;
    for (i = 0; i < G.vexnum; i++)
        for (j = 0; j < G.vexnum; j++)
            G.arcs[j][i].adj = G.arcs[i][j].adj;
    return G;
} //InitGraph end
void Menu() //�˵�
{
    printf("\n                                      ���ϴ�ѧ����ͼ\n");
    printf("                           ������������������������������������������������������������������������\n");
    printf("                           ��   1.���У԰ȫ��                 ��\n");
    printf("                           ��   2.�鿴��������·��             �� \n");
    printf("                           ��   3.ȷ��������֮����̾���       ��\n");
    printf("                           ��   4.�鿴������Ϣ                 ��\n");
    printf("                           ��   5.�˳�����ϵͳ                 ��\n");
    printf("                           ������������������������������������������������������������������������\n");
    printf("Option-:");
}
void Browser(MGraph *G) //���
{
    int v;
    printf("�����������ש��������������������������ש�����������������������������������������������������������������������������\n");
    printf("����ũ�  ��������   ��    ���                              ��\n");
    printf("�����������ߩ��������������������������ߩ�����������������������������������������������������������������������������\n");
    for (v = 0; v < G->vexnum; v++)
        printf("��%-4d��%-20s��%-60s  \n", G->vexs[v].num, G->vexs[v].name, G->vexs[v].introduction);
    printf("�������ߩ��������������������ߩ�����������������������������������������������������������������������������\n");
}
void ShortestPath_DIJ(MGraph *G) // �Ͻ�˹�����㷨 ��������������·��     ��������·��
{
    int v, w, i, min, t = 0, x, flag = 1, v0;
    int final[20], D[20], p[20][20];
    while (flag)
    {
        printf("��������ʼ������:");
        scanf("%d", &v0);
        if (v0 < 0 || v0 > G->vexnum)
        {
            printf("�����Ŵ�!���������뾰����:");
            scanf("%d", &v0);
        }
        if (v0 >= 0 && v0 < G->vexnum)
            flag = 0;
    }
    for (v = 0; v < G->vexnum; v++)
    {
        final[v] = 0;
        D[v] = G->arcs[v0][v].adj; //�洢��ʼv0-ĩβv֮��Ȩֵ
        for (w = 0; w < G->vexnum; w++)
            p[v][w] = 0;
        if (D[v] < INFINITY)
        {
            p[v][v0] = 1;
            p[v][v] = 1;
        }
    }
    D[v0] = 0;
    final[v0] = 1;
    for (i = 1; i < G->vexnum; i++)
    {
        min = INFINITY;
        for (w = 0; w < G->vexnum; w++)
            if (!final[w])
                if (D[w] < min)
                {
                    v = w;
                    min = D[w];
                }
        final[v] = 1;
        for (w = 0; w < G->vexnum; w++)
            if (!final[w] && (min + G->arcs[v][w].adj < D[w]))
            {
                D[w] = min + G->arcs[v][w].adj;
                for (x = 0; x < G->vexnum; x++)
                    p[w][x] = p[v][x];
                p[w][w] = 1;
            }
    }
    for (v = 0; v < G->vexnum; v++)
    {
        if (v0 != v)
            printf("%s", G->vexs[v0].name);
        for (w = 0; w < G->vexnum; w++)
        {
            if (p[v][w] && w != v0)
                printf("-->%s", G->vexs[w].name);
            t++;
        }
        if (t > G->vexnum && v0 != v)
            printf(" ��·��%dm\n\n", D[v]);
    }
} //ShortestPath_DIJ  end

void Floyd(MGraph *G) //	��ѯͼ�������������������·����
{
    int v, u, i, w, k, j, flag = 1, p[20][20][20], D[20][20];
    for (v = 0; v < G->vexnum; v++)
        for (w = 0; w < G->vexnum; w++)
        {
            D[v][w] = G->arcs[v][w].adj;
            for (u = 0; u < G->vexnum; u++)
                p[v][w][u] = 0;
            if (D[v][w] < INFINITY)
            {
                p[v][w][v] = 1;
                p[v][w][w] = 1;
            }
        }
    for (u = 0; u < G->vexnum; u++)
        for (v = 0; v < G->vexnum; v++)
            for (w = 0; w < G->vexnum; w++)
                if (D[v][u] + D[u][w] < D[v][w])
                {
                    D[v][w] = D[v][u] + D[u][w];
                    for (i = 0; i < G->vexnum; i++)
                        p[v][w][i] = p[v][u][i] || p[u][w][i];
                }
    while (flag)
    {
        printf("����������ر��:");
        scanf("%d", &k);
        if (k < 0 || k > G->vexnum)
        {
            printf("�����Ŵ�!\n����������ر��:");
            scanf("%d", &k);
        }
        printf("������Ŀ�ĵر��:");
        scanf("%d", &j);
        if (j < 0 || j > G->vexnum)
        {
            printf("�����Ŵ�!\n������Ŀ�ĵر��:");
            scanf("%d", &j);
        }
        if (k >= 0 && k < G->vexnum && j >= 0 && j < G->vexnum)
            flag = 0;
    }
    printf("%s", G->vexs[k].name);
    for (u = 0; u < G->vexnum; u++)
        if (p[k][j][u] && k != u && j != u)
            printf("-->%s", G->vexs[u].name);
    printf("-->%s", G->vexs[j].name);
    printf(" ��·��%dm\n", D[k][j]);
} //Floyd end
void Search(MGraph *G) //����
{
    int k, flag = 1;
    while (flag)
    {
        printf("������Ҫ��ѯ������:");
        scanf("%d", &k);
        if (k < 0 || k > G->vexnum)
        {
            printf("�����Ŵ���! ���������뾰����:");
            scanf("%d", &k);
        }
        if (k >= 0 && k < G->vexnum)
            flag = 0;
    }
    printf("�������ש��������ש���������������������������������������������������������������������������������������������\n");
    printf("����ũ��������Ʃ����                                                                                        ��\n");
    printf("��%-4d��%-20s    %-60s\n", G->vexs[k].num, G->vexs[k].name, G->vexs[k].introduction);
    printf("�������ߩ��������ߩ���������������������������������������������������������������������������������������������\n");

} //Search end

int LocateVex(MGraph *G, char *v)
{
    int c = -1, i;
    for (i = 0; i < G->vexnum; i++)
        if (strcmp(v, G->vexs[i].name) == 0)
        {
            c = i;
            break;
        }
    return c;
}
MGraph *CreatUDN(MGraph *G) //��ʼ��ͼ�ν�������
{
    int i, j, k, w;
    char v1[20], v2[20];
    printf("������ͼ������,����:");
    scanf("%d%d", &G->vexnum, &G->arcnum);
    printf("�����뾰����:�����ơ����:\n");
    for (i = 0; i < G->vexnum; i++)
    {
        printf("������:");
        scanf("%d", &G->vexs->num);
        printf("��������:");
        scanf("%s", G->vexs[i].name);
        printf("������: ");
        scanf("%s", G->vexs->introduction);
    }
    for (i = 0; i < G->vexnum; i++)
        for (j = 0; j < G->vexnum; j++)
            G->arcs[i][j].adj = INFINITY;
    printf("������·����:\n");
    for (k = 0; k < G->arcnum; k++)
    {
        printf("��%d����:\n", k + 1);
        printf("����(x,y):");
        scanf("%s", v1);
        scanf("%s", v2);
        printf("·����:");
        scanf("%d", &w);
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        if (i >= 0 && j >= 0)
        {
            G->arcs[i][j].adj = w;
            G->arcs[j][i] = G->arcs[i][j];
        }
    }
    return G;
}
void print(MGraph *G) //���
{
    int v, w, t = 0;
    for (v = 0; v < G->vexnum; v++)
        for (w = 0; w < G->vexnum; w++)
        {
            if (G->arcs[v][w].adj == INFINITY)
                printf("��    ");
            else
                printf("%-7d", G->arcs[v][w].adj);
            t++;
            if (t % G->vexnum == 0)
                printf("\n");
        }
}