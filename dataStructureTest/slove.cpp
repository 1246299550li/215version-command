#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

const int MAXSIZE = 20;
void columnPivoting(double a[MAXSIZE][MAXSIZE], int n, double b[]); //声明函数columnPivoting

int main()
{
    double matrix[MAXSIZE][MAXSIZE]; //系数
    double b[MAXSIZE];               //b
    int sizeM;
    std::cout << "输入方程组阶数" << '\n';
    cin >> sizeM;
    std::cout << "输入增广矩阵" << '\n';
    for (int i = 0; i < sizeM; i++)
    {
        for (int j = 0; j < sizeM; j++)
            cin >> matrix[i][j];
        cin >> b[i];
    }
    columnPivoting(matrix, sizeM, b);
    return 0;
}

//列主元消去法
void columnPivoting(double a[MAXSIZE][MAXSIZE], int n, double b[])
{
    int i, j, k;
    int col = 0, row = 0;
    for (k = 0; k < n - 1; k++)
    {
        double tmp = 0;
        //找出消元列中最大的那个元素所在的位置
        for (i = k; i < n; i++)
            if (fabs(a[i][k]) > tmp)
            {
                tmp = fabs(a[i][k]);
                //cout << "MAX " << tmp << endl;//
                row = i;
                col = k;
            }

        //如果该对角线元素是0，同样不能用高斯消元法来求解
        if (a[row][row] == 0)
        {
            cout << "can't solve" << endl;
            return;
        }
        //将找出的行进行交换
        if (k != row)
        {
            for (i = 0; i < n; i++)
            {
                swap(a[row][i], a[k][i]);
                swap(b[k], b[row]);
            }
        }
        //消元过程
        double c[n];
        for (j = k + 1; j < n; j++)
        {
            c[j] = a[j][k] / a[k][k];
            //cout << c[j] << endl;
        }
        for (i = k + 1; i < n; i++)
        {
            for (j = 1; j < n; j++)
            {
                a[i][j] = a[i][j] - c[i] * a[k][j];
            }
            b[i] = b[i] - c[i] * b[k];
        }
    }

    double x[n];
    x[n - 1] = b[n - 1] / a[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--)
    {
        double sum = 0;
        for (j = i + 1; j < n; j++)
            sum += a[i][j] * x[j];
        x[i] = (b[i] - sum) / a[i][i];
    }
    for (int i = 0; i < n; i++)
        printf("x[%d] = %.6f\n", i + 1, x[i]); //输出结果
    printf("\n");
    system("pause");
}
