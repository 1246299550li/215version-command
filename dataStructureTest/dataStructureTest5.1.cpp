#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 2．二分查找算法（设计性实验）

int search(int data[], int len, int num)
{
    int l = 0, r = len - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (data[mid] == num)
        {
            return mid;
        }
        if (data[mid] < num)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int data[2005], n, num;
    printf("请输入一串整数的长度(<2000)\n");
    scanf("%d", &n);
    printf("请输入这串整数\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }
    printf("请输入要查找的数\n");
    scanf("%d", &num);
    sort(data, data + n - 1);
    int index = search(data, n, num);
    if (index != -1)
    {
        printf("要查找的数在第%d个\n", index + 1);
    }
    else
    {
        printf("未查找到此数\n");
    }
    system("pause");
    return 0;
}