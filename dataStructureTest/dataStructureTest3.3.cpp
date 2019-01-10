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
    int weight;                 //Ȩֵ
    int parent, lchild, rchild; //���ڵ㣬���ӽ�㣬�Һ��ӽ��
} HTNode, *HuffmanTree;
typedef char **HuffmanCode;
//-----------ȫ�ֱ���-----------------------
HuffmanTree HT; //����շ�����
HuffmanCode HC; //����շ�������
int *w, i, j, n;
char *z;
int flag = 0;
int numb = 0;
// -----------------��շ�������-----------------------
void line()
{
    cout << "\n--------------------------------------------------\n";
}
int min(HuffmanTree t, int i)
{
    int j, flag;
    int k = UINT_MAX; // ȡkΪ��С�ڿ��ܵ�ֵ
    for (j = 1; j <= i; j++)
        if (t[j].weight < k && t[j].parent == 0)
            k = t[j].weight, flag = j;
    t[flag].parent = 1;
    return flag; //���ر�ʶ��
}
//------------------------------------------
void select(HuffmanTree t, int i, int &s1, int &s2)
{
    int j;
    s1 = min(t, i);
    s2 = min(t, i);
    if (s1 > s2) // s1Ϊ��С������ֵ�����С���Ǹ�
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
    HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode)); // 0�ŵ�Ԫδ��
    for (p = HT + 1, i = 1; i <= n; ++i, ++p, ++w)
    {
        p->weight = *w;
        p->parent = 0;
        p->lchild = 0;
        p->rchild = 0;
    }
    for (; i <= m; ++i, ++p)
        p->parent = 0;
    for (i = n + 1; i <= m; ++i) // ���շ�����
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
            // ��Ҷ�ӵ������������
            if (HT[f].lchild == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        HC[i] = (char *)malloc((n - start) * sizeof(char));

        strcpy(HC[i], &cd[start]);
    }
    free(cd);
}
//--------------��ʼ���շ�������---------------------------------
void init()
{ //--------------------------------------------
    flag = 1;
    int num;
    int num2;
    cout << "�����ʼ���շ�������" << endl
         << "��������ĸ���n��";
    cin >> num;
    n = num;
    line();
    w = (int *)malloc(n * sizeof(int));   //weight
    z = (char *)malloc(n * sizeof(char)); //word
    cout << "\n����������" << n << "���ַ�(�ַ���)\nע��:�����Իس�������" << endl;
    char temp[2];
    line();
    for (i = 0; i < n; i++)
    {
        cout << "��" << i + 1 << "���ַ�:" << endl;
        gets(temp);
        *(z + i) = *temp;
    }
    line();
    for (i = 0; i <= n - 1; i++)
    {
        cout << setw(6) << *(z + i);
    }
    line();
    cout << "\n����������" << n << "��Ȩֵ(\nע��:�����Իس�����)��" << endl;
    line();
    for (i = 0; i <= n - 1; i++)
    {
        cout << endl
             << "��" << i + 1 << "���ַ���Ȩֵ:";
        cin >> num2;
        *(w + i) = num2;
    }
    //���벿�ֽ���------------------------------------------
    HuffmanCoding(HT, HC, w, n);
    //------------------------��ӡ����----------------------
    line();
    cout << "�ַ���Ӧ�ı���Ϊ:" << endl;
    for (i = 1; i <= n; i++)
    {
        //cout<<"�ַ�"<<*(z+i-1)<<"�ı���";
        puts(HC[i]);
    }
    //--------------------------���շ�������д���ļ�---------
    line();
    cout << "���潫�շ�������д���ļ�" << endl
         << "...................." << endl;
    FILE *htmTree;
    char r[] = {' ', '\0'};
    if ((htmTree = fopen("htmTree.txt", "w")) == NULL)
    {
        cout << "�ļ���ʧ��" << endl;
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
    cout << "�ѽ��ַ����Ӧ����д���Ŀ¼���ļ�htmTree.txt��" << endl
         << endl;
} //init
//---------------------��ȡ�ַ���д���ļ�---------------------------------
void inputcode()
{
    //cout<<"����������Ҫ������ַ�"<<endl;
    FILE *virttran, *tobetran;
    char str[100];
    if ((tobetran = fopen("tobetran.txt", "w")) == NULL)
    {
        cout << "���ܴ��ļ�" << endl;
        return;
    }
    cout << "����������Ҫ������ַ�" << endl;
    gets(str);
    fputs(str, tobetran);
    cout << "��ȡ�ַ��ɹ�" << endl;
    fclose(tobetran);
}
//------------------------------------------------------
void encode() //������빦��
{
    cout << "�����Ŀ¼���ļ�tobetran.txt�е��ַ����б���" << endl;
    FILE *tobetran, *codefile;
    if ((tobetran = fopen("tobetran.txt", "rb")) == NULL)
    {
        cout << "���ܴ��ļ�" << endl;
    }
    if ((codefile = fopen("codefile.txt", "wb")) == NULL)
    {
        cout << "���ܴ��ļ�" << endl;
    }
    char *tran;
    i = 99;
    tran = (char *)malloc(100 * sizeof(char)); //Ϊtuan����100���ֽ�
    while (i == 99)
    {
        if (fgets(tran, 100, tobetran) == NULL)
        {
            cout << "���ܴ��ļ�" << endl;
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
                        cout << "�ַ������޷�����!" << endl;
                        break;
                    }
                }
            }
        }
    }
    cout << "���빤�����" << endl
         << "����д��Ŀ¼�µ�codefile.txt��" << endl
         << endl;
    fclose(tobetran);
    fclose(codefile);
    free(tran);
}
//--------------------------------------------------
void decode() //������빦��
{

    cout << "����Ը�Ŀ¼���ļ�codefile.txt�е��ַ���������" << endl;
    FILE *codef, *txtfile;
    if ((txtfile = fopen("Textfile.txt", "w")) == NULL)
    {
        cout << "���ܴ��ļ�" << endl;
    }
    if ((codef = fopen("codefile.txt", "r")) == NULL)
    {
        cout << "���ܴ��ļ�" << endl;
    }
    char *tbdc, *outext, i2;
    int io = 0, i, m;
    unsigned long length = 10000;
    tbdc = (char *)malloc(length * sizeof(char)); //����ռ�
    fgets(tbdc, length, codef);
    outext = (char *)malloc(length * sizeof(char)); //����ռ�

    m = 2 * n - 1;
    for (i = 0; *(tbdc + i) != '\0'; i++) //����ѭ��
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
    cout << "�������" << endl
         << "����д���Ŀ¼�µ��ļ�txtfile.txt��" << endl
         << endl;
    free(tbdc);
    free(outext);
    fclose(txtfile);
    fclose(codef);
}
//---------------------------------------------
void printcode() //��ӡ����
{
    cout << "�����ӡ��Ŀ¼���ļ�CodePrin.txt�б����ַ�" << endl
         << "-----------------------------------------------------------------\n";
    FILE *CodePrin, *codefile;
    if ((CodePrin = fopen("CodePrin.txt", "w")) == NULL)
    {
        cout << "���ܴ��ļ�" << endl;
        return;
    }
    if ((codefile = fopen("codefile.txt", "r")) == NULL)
    {
        cout << "���ܴ��ļ�" << endl;
        return;
    }
    char *work3;
    work3 = (char *)malloc(51 * sizeof(char));
    do
    {
        if (fgets(work3, 51, codefile) == NULL)
        {
            cout << "���ܶ�ȡ�ļ�" << endl;
            break;
        }
        fputs(work3, CodePrin);
        puts(work3);
    } while (strlen(work3) == 50);
    free(work3);
    line();
    cout << "��ӡ��������" << endl
         << endl;
    fclose(CodePrin);
    fclose(codefile);
}
//------------------------��ӡ�շ������ĺ���----------------------
void coprint(HuffmanTree start, HuffmanTree HT)
{
    char t = ' ';

    if (start != HT)
    {
        FILE *TreePrint;
        if ((TreePrint = fopen("TreePrint.txt", "a")) == NULL)
        {
            cout << "�����ļ�ʧ��" << endl;
            return;
        }
        numb++; //�ñ���Ϊ�ѱ�����Ϊȫ�ֱ���
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
void printree(HuffmanTree HT, int w) //��ӡ�շ�����
{
    HuffmanTree p;
    p = HT + w;
    cout << "�����ӡ�շ�����" << endl; // �������ӡ�շ����������
    line();
    coprint(p, HT);
    line();
    cout << "��ӡ��������" << endl; //�������ӡ����������
}
void printhead()
{
    cout << "===============================================================================\n";
    cout << "\n\t\t";
    cout << "��������������������������������������������\n\t\t";
    cout << "��   ������ӭʹ�úշ����������ϵͳ ��������\n\t\t";
    cout << "�ũ�����������������������������������������\n\t\t";
    cout << "������i.��ʼ���շ�������                  ��\n\t\t";
    cout << "����  w.�����ַ�           ��         ������\n\t\t";
    cout << "������e.��    ��  ��      ��      ����    ��\n\t\t";
    cout << "������d.��    �롡 ��     ����            ��\n\t\t";
    cout << "������p.��ӡ����  �� ����     ��          ��\n\t\t";
    cout << "������t.��ӡ�շ�������                    ��\n\t\t";
    cout << "������q.��    �� �� ������                ��\n\t\t";
    cout << "��������������������������������������������\n\n";
    cout << "===============================================================================\n";
    if (flag == 0)
        cout << "\n���ȳ�ʼ���շ�������,����'i'" << endl
             << "--------------------------------------------\n";
    cout << "��ѡ����Ҫ���еĲ���:";
}
/*2��������*/
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
            init(); //����i����г�ʼ���շ�������,
            break;
        case 'w': //����w�����ַ�
            inputcode();
            break;
        case 'e': //����e����
            encode();
            break;
        case 'd': //����d����
            decode();
            break;
        case 'p': //����p��ӡ����
            printcode();
            break;
        case 't': //����t��ӡ�շ�����
            printree(HT, 2 * n - 1);
            break;
        case 'q': //����q�˳�
            break;
        default:
            cout << "�������������ѡ��" << endl;
        }
    }
    free(z);  //�ͷ�z���
    free(w);  //�ͷ�w���
    free(HT); //�ͷ�HT���
}