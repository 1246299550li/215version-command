#include <iostream>
#include <iomanip>
#include <string.h>
#include <malloc.h>
#include <stdio.h>
//typedef int  TElemType;
const int UINT_MAX = 1000;
using namespace std;
typedef struct
{
    int weight;                 //权值
    int parent, lchild, rchild; //父节点，左孩子结点，右孩子结点
} HTNode, *HuffmanTree;
typedef char **HuffmanCode;
//-----------全局变量-----------------------
HuffmanTree HT; //代表赫夫曼树
HuffmanCode HC; //代表赫夫曼编码
int *w, i, j, n;
char *z;
int flag = 0;
int numb = 0;
// -----------------求赫夫曼编码-----------------------
void line()
{
    cout << "\n--------------------------------------------------\n";
}
int min(HuffmanTree t, int i)
{
    int j, flag;
    int k = UINT_MAX; // 取k为不小于可能的值
    for (j = 1; j <= i; j++)
        if (t[j].weight < k && t[j].parent == 0)
            k = t[j].weight, flag = j;
    t[flag].parent = 1;
    return flag; //返回标识符
}
//------------------------------------------
void select(HuffmanTree t, int i, int &s1, int &s2)
{
    int j;
    s1 = min(t, i);
    s2 = min(t, i);
    if (s1 > s2) // s1为最小的两个值中序号小的那个
    {
        j = s1;
        s1 = s2;
        s2 = j;
    }
}
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n)
{
    int m, i, s1, s2, start;
    int c, f;
    HuffmanTree p;
    char *cd;
    if (n <= 1)
        return;
    m = 2 * n - 1;
    HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode)); // 0号单元未用
    for (p = HT + 1, i = 1; i <= n; ++i, ++p, ++w)
    {
        p->weight = *w;
        p->parent = 0;
        p->lchild = 0;
        p->rchild = 0;
    }
    for (; i <= m; ++i, ++p)
        p->parent = 0;
    for (i = n + 1; i <= m; ++i) // 建赫夫曼树
    {
        select(HT, i - 1, s1, s2);
        HT[s1].parent = HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }

    HC = (HuffmanCode)malloc((n + 1) * sizeof(char *));
    cd = (char *)malloc(n * sizeof(char));

    cd[n - 1] = '\0';
    for (i = 1; i <= n; i++)
    {
        start = n - 1;
        for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
            // 从叶子到根逆向求编码
            if (HT[f].lchild == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        HC[i] = (char *)malloc((n - start) * sizeof(char));

        strcpy(HC[i], &cd[start]);
    }
    free(cd);
}
//--------------初始化赫夫曼链表---------------------------------
void init()
{ //--------------------------------------------
    flag = 1;
    int num;
    int num2;
    cout << "下面初始化赫夫曼链表" << endl
         << "请输入结点的个数n：";
    cin >> num;
    n = num;
    line();
    w = (int *)malloc(n * sizeof(int));   //weight
    z = (char *)malloc(n * sizeof(char)); //word
    cout << "\n请依次输入" << n << "个字符(字符型)\n注意:必须以回车结束：" << endl;
    char temp[2];
    line();
    for (i = 0; i < n; i++)
    {
        cout << "第" << i + 1 << "个字符:" << endl;
        gets(temp);
        *(z + i) = *temp;
    }
    line();
    for (i = 0; i <= n - 1; i++)
    {
        cout << setw(6) << *(z + i);
    }
    line();
    cout << "\n请依次输入" << n << "个权值(\n注意:必须以回车结束)：" << endl;
    line();
    for (i = 0; i <= n - 1; i++)
    {
        cout << endl
             << "第" << i + 1 << "个字符的权值:";
        cin >> num2;
        *(w + i) = num2;
    }
    //输入部分结束------------------------------------------
    HuffmanCoding(HT, HC, w, n);
    //------------------------打印编码----------------------
    line();
    cout << "字符对应的编码为:" << endl;
    for (i = 1; i <= n; i++)
    {
        //cout<<"字符"<<*(z+i-1)<<"的编码";
        puts(HC[i]);
    }
    //--------------------------将赫夫曼编码写入文件---------
    line();
    cout << "下面将赫夫曼编码写入文件" << endl
         << "...................." << endl;
    FILE *htmTree;
    char r[] = {' ', '\0'};
    if ((htmTree = fopen("htmTree.txt", "w")) == NULL)
    {
        cout << "文件打开失败" << endl;
        return;
    }
    fputs(z, htmTree);
    for (i = 0; i < n + 1; i++)
    {
        fprintf(htmTree, "%6d", *(w + i));
        fputs(r, htmTree);
    }
    for (i = 1; i <= n; i++)
    {
        fputs(HC[i], htmTree);
        fputs(r, htmTree);
    }
    fclose(htmTree);
    cout << "已将字符与对应编码写入根目录下文件htmTree.txt中" << endl
         << endl;
} //init
//---------------------获取字符并写入文件---------------------------------
void inputcode()
{
    //cout<<"请输入你想要编码的字符"<<endl;
    FILE *virttran, *tobetran;
    char str[100];
    if ((tobetran = fopen("tobetran.txt", "w")) == NULL)
    {
        cout << "不能打开文件" << endl;
        return;
    }
    cout << "请输入你想要编码的字符" << endl;
    gets(str);
    fputs(str, tobetran);
    cout << "获取字符成功" << endl;
    fclose(tobetran);
}
//------------------------------------------------------
void encode() //完成译码功能
{
    cout << "下面对目录下文件tobetran.txt中的字符进行编码" << endl;
    FILE *tobetran, *codefile;
    if ((tobetran = fopen("tobetran.txt", "rb")) == NULL)
    {
        cout << "不能打开文件" << endl;
    }
    if ((codefile = fopen("codefile.txt", "wb")) == NULL)
    {
        cout << "不能打开文件" << endl;
    }
    char *tran;
    i = 99;
    tran = (char *)malloc(100 * sizeof(char)); //为tuan分配100个字节
    while (i == 99)
    {
        if (fgets(tran, 100, tobetran) == NULL)
        {
            cout << "不能打开文件" << endl;
            break;
        }
        for (i = 0; *(tran + i) != '\0'; i++)
        {
            for (j = 0; j <= n; j++)
            {
                if (*(z + j - 1) == *(tran + i))
                {
                    fputs(HC[j], codefile);
                    puts(HC[j]);
                    if (j > n)
                    {
                        cout << "字符错误，无法编码!" << endl;
                        break;
                    }
                }
            }
        }
    }
    cout << "编码工作完成" << endl
         << "编码写入目录下的codefile.txt中" << endl
         << endl;
    fclose(tobetran);
    fclose(codefile);
    free(tran);
}
//--------------------------------------------------
void decode() //完成译码功能
{

    cout << "下面对根目录下文件codefile.txt中的字符进行译码" << endl;
    FILE *codef, *txtfile;
    if ((txtfile = fopen("Textfile.txt", "w")) == NULL)
    {
        cout << "不能打开文件" << endl;
    }
    if ((codef = fopen("codefile.txt", "r")) == NULL)
    {
        cout << "不能打开文件" << endl;
    }
    char *tbdc, *outext, i2;
    int io = 0, i, m;
    unsigned long length = 10000;
    tbdc = (char *)malloc(length * sizeof(char)); //分配空间
    fgets(tbdc, length, codef);
    outext = (char *)malloc(length * sizeof(char)); //分配空间

    m = 2 * n - 1;
    for (i = 0; *(tbdc + i) != '\0'; i++) //进入循环
    {
        i2 = *(tbdc + i);
        if (HT[m].lchild == 0)
        {
            *(outext + io) = *(z + m - 1);
            io++;
            m = 2 * n - 1;
            i--;
        }
        else if (i2 == '0')
            m = HT[m].lchild;
        else if (i2 == '1')
            m = HT[m].rchild;
    }
    *(outext + io) = '\0';
    fputs(outext, txtfile);
    cout << "译码完成" << endl
         << "内容写入根目录下的文件txtfile.txt中" << endl
         << endl;
    free(tbdc);
    free(outext);
    fclose(txtfile);
    fclose(codef);
}
//---------------------------------------------
void printcode() //打印代码
{
    cout << "下面打印根目录下文件CodePrin.txt中编码字符" << endl
         << "-----------------------------------------------------------------\n";
    FILE *CodePrin, *codefile;
    if ((CodePrin = fopen("CodePrin.txt", "w")) == NULL)
    {
        cout << "不能打开文件" << endl;
        return;
    }
    if ((codefile = fopen("codefile.txt", "r")) == NULL)
    {
        cout << "不能打开文件" << endl;
        return;
    }
    char *work3;
    work3 = (char *)malloc(51 * sizeof(char));
    do
    {
        if (fgets(work3, 51, codefile) == NULL)
        {
            cout << "不能读取文件" << endl;
            break;
        }
        fputs(work3, CodePrin);
        puts(work3);
    } while (strlen(work3) == 50);
    free(work3);
    line();
    cout << "打印工作结束" << endl
         << endl;
    fclose(CodePrin);
    fclose(codefile);
}
//------------------------打印赫夫曼树的函数----------------------
void coprint(HuffmanTree start, HuffmanTree HT)
{
    char t = ' ';

    if (start != HT)
    {
        FILE *TreePrint;
        if ((TreePrint = fopen("TreePrint.txt", "a")) == NULL)
        {
            cout << "创建文件失败" << endl;
            return;
        }
        numb++; //该变量为已被声明为全局变量
        coprint(HT + start->rchild, HT);
        if (start->lchild != NULL && start->rchild != NULL)
            t = '<';
        cout << setw(5 * numb) << start->weight << t << endl;
        fprintf(TreePrint, "%d\n", start->weight);
        coprint(HT + start->lchild, HT);
        numb--;
        fclose(TreePrint);
    }
}
void printree(HuffmanTree HT, int w) //打印赫夫曼树
{
    HuffmanTree p;
    p = HT + w;
    cout << "下面打印赫夫曼树" << endl; // 输出“打印赫夫曼树”语句
    line();
    coprint(p, HT);
    line();
    cout << "打印工作结束" << endl; //输出“打印工作结束”
}
void printhead()
{
    cout << "===============================================================================\n";
    cout << "\n\t\t";
    cout << "┏━━━━━━━━━━━━━━━━━━━━┓\n\t\t";
    cout << "┃   　　欢迎使用赫夫曼编码解码系统 　　　┃\n\t\t";
    cout << "┡━━━━━━━━━━━━━━━━━━━━┩\n\t\t";
    cout << "│　　i.初始化赫夫曼链表                  │\n\t\t";
    cout << "│　  w.编码字符           　         　　│\n\t\t";
    cout << "│　　e.编    码  　      　      　　    │\n\t\t";
    cout << "│　　d.译    码　 　     　　            │\n\t\t";
    cout << "│　　p.打印编码  　 　　     　          │\n\t\t";
    cout << "│　　t.打印赫夫曼树　                    │\n\t\t";
    cout << "│　　q.退    出 　 　　　                │\n\t\t";
    cout << "└────────────────────┘\n\n";
    cout << "===============================================================================\n";
    if (flag == 0)
        cout << "\n请先初始化赫夫曼链表,输入'i'" << endl
             << "--------------------------------------------\n";
    cout << "请选择你要进行的操作:";
}
/*2．主程序*/
int main()
{
    char choice;
    while (choice != 'q')
    {
        printhead();

        cin >> choice;
        switch (choice)
        {
        case 'i':
            init(); //按下i则进行初始化赫夫曼链表,
            break;
        case 'w': //按下w编码字符
            inputcode();
            break;
        case 'e': //按下e编码
            encode();
            break;
        case 'd': //按下d译码
            decode();
            break;
        case 'p': //按下p打印编码
            printcode();
            break;
        case 't': //按下t打印赫夫曼树
            printree(HT, 2 * n - 1);
            break;
        case 'q': //按下q退出
            break;
        default:
            cout << "输入错误，请重新选择" << endl;
        }
    }
    free(z);  //释放z结点
    free(w);  //释放w结点
    free(HT); //释放HT结点
}