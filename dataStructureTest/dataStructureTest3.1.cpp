/*
*二叉树的实现及遍历
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

void insert(BiTree *tree, char val)
{
    BiTree temp = NULL;
    if (!(*tree))
    {
        temp = (BitNode *)malloc(sizeof(BitNode));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }
    if (!(*tree))
    {
        insert(&((*tree)->left), val);
    }
    else
    {
        insert(&((*tree)->right), val);
    }
}
void printPreorder(BiTree tree)
{
    if (tree)
    {
        printf("%c ", tree->data);
        printPreorder(tree->left);
        printPreorder(tree->right);
    }
}

void printInorder(BiTree tree)
{
    if (tree)
    {
        printInorder(tree->left);
        printf("%c ", tree->data);
        printInorder(tree->right);
    }
}

void printPostorder(BiTree tree)
{
    if (tree)
    {
        printPostorder(tree->left);
        printPostorder(tree->right);
        printf("%c ", tree->data);
    }
}

int main()
{
    BiTree root = NULL;
    printf("请输入您要建立的二叉树的先序扩展序列(用*表示空)\n");
    createBinTree(&root);
    printf("构造二叉树成功!\n");

    printf("\nPre Order Display\n");
    printPreorder(root);

    printf("\nIn Order Display\n");
    printInorder(root);

    printf("\nPost Order Display\n");
    printPostorder(root);

    system("pause");
    return 0;
}
