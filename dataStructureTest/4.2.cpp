#include <stdio.h>
#include <stdlib.h>
#define M 20
#define MAX 30

typedef struct
{
    int begin;  //头顶点
    int end;    //末顶点
    int weight; //权值
} edge;

typedef struct
{
    int adj;
    int weight; //权值
} AdjMatrix[MAX][MAX];

typedef struct
{
    AdjMatrix arc;
    int vexnum, arcnum; //顶点 弧
} MGraph;
//函数申明
void CreatGraph(MGraph *);    //图构建
void sort(edge *, MGraph *);  //权值排序
void MiniSpanTree(MGraph *);  //生成最小树
int Find(int *, int);         //   尾顶点查找
void Swapn(edge *, int, int); //权值、头顶点、尾顶点交换
void CreatGraph(MGraph *G)    //构件图
{
    int i, j, n, m;

    printf("请输入边数和顶点数:\n");
    scanf("%d %d", &G->arcnum, &G->vexnum);

    for (i = 1; i <= G->vexnum; i++) //初始化图
    {
        for (j = 1; j <= G->vexnum; j++)
        {
            G->arc[i][j].adj = G->arc[j][i].adj = 0;
        }
    }

    for (i = 1; i <= G->arcnum; i++) //输入边和权值
    {
        printf("请输入有边的2个顶点\n");
        scanf("%d %d", &n, &m);
        while (n < 0 || n > G->vexnum || m < 0 || n > G->vexnum)
        {
            printf("输入的数字不符合要求 请重新输入:\n");
            scanf("%d%d", &n, &m);
        }

        G->arc[n][m].adj = G->arc[m][n].adj = 1;
        getchar();
        printf("请输入%d与%d之间的权值:\n", n, m);
        scanf("%d", &G->arc[n][m].weight);
    }

    printf("邻接矩阵为:\n");
    for (i = 1; i <= G->vexnum; i++)
    {
        for (j = 1; j <= G->vexnum; j++)
        {
            printf("%d ", G->arc[i][j].adj);
        }
        printf("\n");
    }
}

void sort(edge edges[], MGraph *G) //对权值进行排序
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

    printf("权排序之后的为:\n");
    for (i = 1; i <= G->arcnum; i++)
    {
        printf("<< %d, %d >>   %d\n", edges[i].begin, edges[i].end, edges[i].weight);
    }
}

void Swapn(edge *edges, int i, int j) //交换权值 以及头和尾
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

void MiniSpanTree(MGraph *G) //生成最小生成树
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
    printf("最小生成树为:\n");
    for (i = 1; i <= G->arcnum; i++) //核心部分
    {
        n = Find(parent, edges[i].begin);
        m = Find(parent, edges[i].end);
        if (n != m) //判断是否有回路，如果有，舍弃
        {
            parent[m] = n;
            printf("<< %d, %d >>   %d\n", edges[i].begin, edges[i].end, edges[i].weight);
        }
    }
}

int Find(int *parent, int f) //找尾
{
    while (parent[f] > 0)
    {
        f = parent[f];
    }
    return f;
}

int main(void) //主函数
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