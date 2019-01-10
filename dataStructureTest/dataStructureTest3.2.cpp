/*
*按凹入表形式横向打印二叉树结构
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

 //根据所有序列创建二叉树
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

//凹入表打印树结构
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
    printf("请输入您要建立的二叉树的先序扩展序列(用*表示空)\n");
    createBinTree(&root);
    printf("构造二叉树成功!\n");

    string str = "";
    printHelp(root, str);

    system("pause");
    return 0;
}