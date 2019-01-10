/*
*���������ʽ�����ӡ�������ṹ
*
*
*/

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

typedef struct BitNode
{
    char data;
    struct BitNode *left, *right;
} BitNode, *BiTree;

 //�����������д���������
bool createBinTree(BiTree *tree)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '*')
    {
        (*tree) = NULL;
    }
    else
    {
        if (!(*tree = (BitNode *)malloc(sizeof(BitNode))))
        {
            return false;
        }
        (*tree)->data = ch;
        createBinTree(&((*tree)->left));
        createBinTree(&((*tree)->right));
    }
    return true;
}

//������ӡ���ṹ
void printHelp(BitNode *p, string str)
{
    if (p == NULL)
        return;
    str += "   ";
    printHelp(p->right, str);
    cout << str << p->data << endl;
    printHelp(p->left, str);
}

int main()
{
    BiTree root = NULL;
    printf("��������Ҫ�����Ķ�������������չ����(��*��ʾ��)\n");
    createBinTree(&root);
    printf("����������ɹ�!\n");

    string str = "";
    printHelp(root, str);

    system("pause");
    return 0;
}