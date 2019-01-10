#define INFINITY 200000000 /*无穷*/
#define MAX_VERTEX_NUM 40
#define MAX 40
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
typedef struct ArCell
{
    int adj;                                         //路径度
} ArCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //邻接矩阵
typedef struct                                       //图顶点表示主要景点存放景点编号、名称、简介等信息
{
    char name[20];
    int num;
    char introduction[60]; //简介
} infotype;
typedef struct //图中的边表示景点间的道路，存放路径长度等信息。
{
    infotype vexs[MAX_VERTEX_NUM]; //顶点信息域
    AdjMatrix arcs;
    int vexnum, /*顶点数*/ arcnum; //边个数
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
            break; //1.浏览校园全景
        case 2:
            system("cls");
            ShortestPath_DIJ(&b);
            Menu();
            break; //2.查看所有游览路线
        case 3:
            system("cls");
            Floyd(&b);
            Menu();
            break; //3.确定两景点之间最短距离
        case 4:
            system("cls");
            Search(&b);
            Menu();
            break; //4.查看景点信息
        case 5:
            exit(1);
            break;
        default:
            break;
        }
        printf("请重新输入（1-5）：");
        scanf("%d", &i);
    }
}
MGraph InitGraph(void) //初始化
{
    MGraph G;
    int i, j;
    G.vexnum = 16;
    G.arcnum = 40;
    for (i = 0; i < G.vexnum; i++)
        G.vexs[i].num = i;
    strcpy(G.vexs[0].name, "南校区");
    strcpy(G.vexs[0].introduction, "住宿楼");

    strcpy(G.vexs[1].name, "北校区");
    strcpy(G.vexs[1].introduction, "学校本部");

    strcpy(G.vexs[2].name, "校综合楼");
    strcpy(G.vexs[2].introduction, "全体教师办公场所");

    strcpy(G.vexs[3].name, "体育馆");
    strcpy(G.vexs[3].introduction, "体育馆一楼为室内羽毛球，乒乓球");

    strcpy(G.vexs[4].name, "医务室");
    strcpy(G.vexs[4].introduction, "校医务室");

    strcpy(G.vexs[5].name, "外语楼");
    strcpy(G.vexs[5].introduction, "校教学楼，环境优美,适宜学习");

    strcpy(G.vexs[6].name, "宿舍楼");
    strcpy(G.vexs[6].introduction, "多个学院 女生宿舍楼 位于弘德楼旁边");

    strcpy(G.vexs[7].name, "湖边小树林");
    strcpy(G.vexs[7].introduction, " 绿树荫阴,适宜休息 晨读");

    strcpy(G.vexs[8].name, "第二教学楼");
    strcpy(G.vexs[8].introduction, "各种实验室");

    strcpy(G.vexs[9].name, "图书馆");
    strcpy(G.vexs[9].introduction, "藏书145万册,设施优良 一楼有咖啡厅 环境优雅");

    strcpy(G.vexs[10].name, "后湖");
    strcpy(G.vexs[10].introduction, "啥也没");

    strcpy(G.vexs[11].name, "第三教学楼");
    strcpy(G.vexs[11].introduction, "校第三教楼为实验楼,环境好 内设 物理 化学实验室和电脑机房");

    strcpy(G.vexs[12].name, "学生第二食堂");
    strcpy(G.vexs[12].introduction, "环境比较好 ,饭菜还可以");

    strcpy(G.vexs[13].name, "28栋宿舍楼  ");
    strcpy(G.vexs[13].introduction, "宿舍楼");

    strcpy(G.vexs[14].name, "16号宿舍楼  ");
    strcpy(G.vexs[14].introduction, "16栋是学校的鸳鸯楼就是男生半栋女生半栋楼");

    strcpy(G.vexs[15].name, "国防生公寓");
    strcpy(G.vexs[15].introduction, "旁边有超市");
    for (i = 0; i < G.vexnum; i++)
        for (j = 0; j < G.vexnum; j++)
            G.arcs[i][j].adj = INFINITY;
    G.arcs[0][1].adj = 80; /*路径度*/
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
void Menu() //菜单
{
    printf("\n                                      中南大学导游图\n");
    printf("                           ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("                           ┃   1.浏览校园全景                 ┃\n");
    printf("                           ┃   2.查看所有游览路线             ┃ \n");
    printf("                           ┃   3.确定两景点之间最短距离       ┃\n");
    printf("                           ┃   4.查看景点信息                 ┃\n");
    printf("                           ┃   5.退出导游系统                 ┃\n");
    printf("                           ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("Option-:");
}
void Browser(MGraph *G) //浏览
{
    int v;
    printf("┏━━━━┳━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃编号┃  景点名称   ┃    简介                              ┃\n");
    printf("┗━━━━┻━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    for (v = 0; v < G->vexnum; v++)
        printf("┃%-4d┃%-20s┃%-60s  \n", G->vexs[v].num, G->vexs[v].name, G->vexs[v].introduction);
    printf("┗━━┻━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}
void ShortestPath_DIJ(MGraph *G) // 迪杰斯特拉算法 计算起点各顶点间短路径     查找所有路线
{
    int v, w, i, min, t = 0, x, flag = 1, v0;
    int final[20], D[20], p[20][20];
    while (flag)
    {
        printf("请输入起始景点编号:");
        scanf("%d", &v0);
        if (v0 < 0 || v0 > G->vexnum)
        {
            printf("景点编号存!请重新输入景点编号:");
            scanf("%d", &v0);
        }
        if (v0 >= 0 && v0 < G->vexnum)
            flag = 0;
    }
    for (v = 0; v < G->vexnum; v++)
    {
        final[v] = 0;
        D[v] = G->arcs[v0][v].adj; //存储起始v0-末尾v之间权值
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
            printf(" 总路线%dm\n\n", D[v]);
    }
} //ShortestPath_DIJ  end

void Floyd(MGraph *G) //	查询图中任意两个景点间的最短路径。
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
        printf("请输入出发地编号:");
        scanf("%d", &k);
        if (k < 0 || k > G->vexnum)
        {
            printf("景点编号存!\n请输入出发地编号:");
            scanf("%d", &k);
        }
        printf("请输入目的地编号:");
        scanf("%d", &j);
        if (j < 0 || j > G->vexnum)
        {
            printf("景点编号存!\n请输入目的地编号:");
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
    printf(" 总路线%dm\n", D[k][j]);
} //Floyd end
void Search(MGraph *G) //查找
{
    int k, flag = 1;
    while (flag)
    {
        printf("请输入要查询景点编号:");
        scanf("%d", &k);
        if (k < 0 || k > G->vexnum)
        {
            printf("景点编号存在! 请重新输入景点编号:");
            scanf("%d", &k);
        }
        if (k >= 0 && k < G->vexnum)
            flag = 0;
    }
    printf("┏━━┳━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃编号┃景点名称┃简介                                                                                        ┃\n");
    printf("┃%-4d┃%-20s    %-60s\n", G->vexs[k].num, G->vexs[k].name, G->vexs[k].introduction);
    printf("┗━━┻━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

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
MGraph *CreatUDN(MGraph *G) //初始化图形接受输入
{
    int i, j, k, w;
    char v1[20], v2[20];
    printf("请输入图顶点数,弧数:");
    scanf("%d%d", &G->vexnum, &G->arcnum);
    printf("请输入景点编号:、名称、简介:\n");
    for (i = 0; i < G->vexnum; i++)
    {
        printf("景点编号:");
        scanf("%d", &G->vexs->num);
        printf("景点名称:");
        scanf("%s", G->vexs[i].name);
        printf("景点简介: ");
        scanf("%s", G->vexs->introduction);
    }
    for (i = 0; i < G->vexnum; i++)
        for (j = 0; j < G->vexnum; j++)
            G->arcs[i][j].adj = INFINITY;
    printf("请输入路径度:\n");
    for (k = 0; k < G->arcnum; k++)
    {
        printf("第%d条边:\n", k + 1);
        printf("景点(x,y):");
        scanf("%s", v1);
        scanf("%s", v2);
        printf("路径度:");
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
void print(MGraph *G) //输出
{
    int v, w, t = 0;
    for (v = 0; v < G->vexnum; v++)
        for (w = 0; w < G->vexnum; w++)
        {
            if (G->arcs[v][w].adj == INFINITY)
                printf("∞    ");
            else
                printf("%-7d", G->arcs[v][w].adj);
            t++;
            if (t % G->vexnum == 0)
                printf("\n");
        }
}