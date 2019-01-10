#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 2�����ֲ����㷨�������ʵ�飩

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
    printf("������һ�������ĳ���(<2000)\n");
    scanf("%d", &n);
    printf("�������⴮����\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }
    printf("������Ҫ���ҵ���\n");
    scanf("%d", &num);
    sort(data, data + n - 1);
    int index = search(data, n, num);
    if (index != -1)
    {
        printf("Ҫ���ҵ����ڵ�%d��\n", index + 1);
    }
    else
    {
        printf("δ���ҵ�����\n");
    }
    system("pause");
    return 0;
}