#include <stdio.h>
#include <stdlib.h>
#define M 20
#define MAX 30

typedef struct
{
    int begin;  //ͷ����
    int end;    //ĩ����
    int weight; //Ȩֵ
} edge;

typedef struct
{
    int adj;
    int weight; //Ȩֵ
} AdjMatrix[MAX][MAX];

typedef struct
{
    AdjMatrix arc;
    int vexnum, arcnum; //���� ��
} MGraph;
//��������
void CreatGraph(MGraph *);    //ͼ����
void sort(edge *, MGraph *);  //Ȩֵ����
void MiniSpanTree(MGraph *);  //������С��
int Find(int *, int);         //   β�������
void Swapn(edge *, int, int); //Ȩֵ��ͷ���㡢β���㽻��
void CreatGraph(MGraph *G)    //����ͼ
{
    int i, j, n, m;

    printf("����������Ͷ�����:\n");
    scanf("%d %d", &G->arcnum, &G->vexnum);

    for (i = 1; i <= G->vexnum; i++) //��ʼ��ͼ
    {
        for (j = 1; j <= G->vexnum; j++)
        {
            G->arc[i][j].adj = G->arc[j][i].adj = 0;
        }
    }

    for (i = 1; i <= G->arcnum; i++) //����ߺ�Ȩֵ
    {
        printf("�������бߵ�2������\n");
        scanf("%d %d", &n, &m);
        while (n < 0 || n > G->vexnum || m < 0 || n > G->vexnum)
        {
            printf("��������ֲ�����Ҫ�� ����������:\n");
            scanf("%d%d", &n, &m);
        }

        G->arc[n][m].adj = G->arc[m][n].adj = 1;
        getchar();
        printf("������%d��%d֮���Ȩֵ:\n", n, m);
        scanf("%d", &G->arc[n][m].weight);
    }

    printf("�ڽӾ���Ϊ:\n");
    for (i = 1; i <= G->vexnum; i++)
    {
        for (j = 1; j <= G->vexnum; j++)
        {
            printf("%d ", G->arc[i][j].adj);
        }
        printf("\n");
    }
}

void sort(edge edges[], MGraph *G) //��Ȩֵ��������
{
    int i, j;

    for (i = 1; i < G->arcnum; i++)
    {
        for (j = i + 1; j <= G->arcnum; j++)
        {
            if (edges[i].weight > edges[j].weight)
            {
                Swapn(edges, i, j);
            }
        }
    }

    printf("Ȩ����֮���Ϊ:\n");
    for (i = 1; i <= G->arcnum; i++)
    {
        printf("<< %d, %d >>   %d\n", edges[i].begin, edges[i].end, edges[i].weight);
    }
}

void Swapn(edge *edges, int i, int j) //����Ȩֵ �Լ�ͷ��β
{

    int temp;

    temp = edges[i].begin;
    edges[i].begin = edges[j].begin;
    edges[j].begin = temp;

    temp = edges[i].end;
    edges[i].end = edges[j].end;
    edges[j].end = temp;

    temp = edges[i].weight;
    edges[i].weight = edges[j].weight;
    edges[j].weight = temp;
}

void MiniSpanTree(MGraph *G) //������С������
{
    int i, j, n, m;
    int k = 1;
    int parent[M];

    edge edges[M];

    for (i = 1; i < G->vexnum; i++)
    {
        for (j = i + 1; j <= G->vexnum; j++)
        {
            if (G->arc[i][j].adj == 1)
            {
                edges[k].begin = i;
                edges[k].end = j;
                edges[k].weight = G->arc[i][j].weight;
                k++;
            }
        }
    }

    sort(edges, G);
    for (i = 1; i <= G->arcnum; i++)
    {
        parent[i] = 0;
    }
    printf("��С������Ϊ:\n");
    for (i = 1; i <= G->arcnum; i++) //���Ĳ���
    {
        n = Find(parent, edges[i].begin);
        m = Find(parent, edges[i].end);
        if (n != m) //�ж��Ƿ��л�·������У�����
        {
            parent[m] = n;
            printf("<< %d, %d >>   %d\n", edges[i].begin, edges[i].end, edges[i].weight);
        }
    }
}

int Find(int *parent, int f) //��β
{
    while (parent[f] > 0)
    {
        f = parent[f];
    }
    return f;
}

int main(void) //������
{
    MGraph *G;

    G = (MGraph *)malloc(sizeof(MGraph));
    if (G == NULL)
    {
        printf("memory allcation failed,goodbye");
        exit(1);
    }

    CreatGraph(G);
    MiniSpanTree(G);

    system("pause");
    return 0;
}