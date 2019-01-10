#include <cstdio>
#include <cstdlib>
#include <string>
#include <windows.h>
using namespace std;
#define MAXSIZE 20  //电话薄记录数量
#define MAX_SIZE 20 //人名的最大长度
#define HASHSIZE 53 //定义表长

typedef char NA[MAX_SIZE];
 //记录
typedef struct
{
    NA name;
    NA tel;
    NA add;
} Record;

typedef struct
{   //哈希表                        
    Record *elem[HASHSIZE]; //数据元素存储基址
    int count;              //当前数据元素个数
    int size;               //当前容量
} HashTable;

bool eq(NA x, NA y)
{ //关键字比较，相等返回true；否则返回false
    if (strcmp(x, y) == 0)
        return true;
    else
        return false;
}

int NUM_BER; //记录的个数

char *strupr(char *str)
{
    char *orign=str;
    for (; *str!='\0'; str++)
        *str = toupper(*str);
    return orign;
}
void getinf(Record *a)
{ //键盘输入各人的信息
    printf("输入要添加的个数：\n");
    scanf("%d", &NUM_BER);
    int i;
    for (i = 0; i < NUM_BER; i++)
    {

        printf("请输入第%d个记录的用户名:\n", i + 1);
        scanf("%s", a[i].name);
        printf("请输入%d个记录的电话号码:\n", i + 1);
        scanf("%s", a[i].tel);
        printf("请输入第%d个记录的地址:\n", i + 1);
        scanf("%s", a[i].add);
    }
}

void ShowInf(Record *a) //显示输入的用户信息
{
    int i;
    for (i = 0; i < NUM_BER; i++)
        printf("\n第%d个用户信息:\n 姓    名：%s\n 电话号码：%s\n 联系地址：%s\n", i + 1, a[i].name, a[i].tel, a[i].add);
}

void Cls(Record *a)
{
    printf("*");
    system("cls");
}
long fold(NA s)
{ //人名的折叠处理
    char *p;
    long sum = 0;
    NA ss;
    strcpy(ss, s); //复制字符串，不改变原字符串的大小写

    strupr(ss);    //将字符串ss转换为大写形式
    p = ss;
    while (*p != '\0')
        sum += *p++;
    printf("\nsum====================%d", sum);
    return sum;
}

int Hash1(NA str)
{ //哈希函数
    long n;
    int m;
    n = fold(str);    //先将用户名进行折叠处理
    m = n % HASHSIZE; //折叠处理后的数，用除留余数法构造哈希函数
    return m;         //并返回模值
}

int Hash2(NA str)
{ //哈希函数
    long n;
    int m;
    n = atoi(str);    //把字符串转换成整型数.
    m = n % HASHSIZE; //用除留余数法构造哈希函数
    return m;         //并返回模值
}

int collision(int p, int &c)
{ //冲突处理函数，采用二次探测再散列法解决冲突
    int i, q;
    i = c / 2 + 1;
    while (i < HASHSIZE)
    {
        if (c % 2 == 0)
        {
            c++;
            q = (p + i * i) % HASHSIZE;
            if (q >= 0)
                return q;
            else
                i = c / 2 + 1;
        }
        else
        {
            q = (p - i * i) % HASHSIZE;
            c++;
            if (q >= 0)
                return q;
            else
                i = c / 2 + 1;
        }
    }
    return -1;
}
void benGetTime();
void CreateHash1(HashTable *H, Record *a)
{   //建表，以人的姓名为关键字，建立相应的散列表
    //若哈希地址冲突，进行冲突处理
    benGetTime();
    int i, p = -1, c, pp;
    for (i = 0; i < NUM_BER; i++)
    {
        c = 0;
        p = Hash1(a[i].name);
        pp = p;
        while (H->elem[pp] != NULL)
        {
            pp = collision(p, c);
            if (pp < 0)
            {
                printf("第%d记录无法解决冲突", i + 1); //需要显示冲突次数时输出
                continue;
            } //无法解决冲突，跳入下一循环
        }
        H->elem[pp] = &(a[i]); //求得哈希地址，将信息存入
        H->count++;
        printf("第%d个记录冲突次数为%d。\n", i + 1, c); //需要显示冲突次数时输出
    }
    printf("\n建表完成!\n此哈希表容量为%d,当前表内存储的记录个数为%d.\n", HASHSIZE, H->count);
    benGetTime();
}

void SearchHash1(HashTable *H, int &c)
{   //在通讯录里查找姓名关键字，若查找成功，显示信息
    //c用来记录冲突次数,查找成功时显示冲突次数
    benGetTime();
    NA str;
    printf("\n请输入要查找记录的姓名：\n");
    scanf("%s", str);
    int p, pp;
    p = Hash1(str);
    pp = p;
    while ((H->elem[pp] != NULL) && (!eq(str, H->elem[pp]->name)))
        pp = collision(p, c);
    if (H->elem[pp] != NULL && eq(str, H->elem[pp]->name))
    {
        printf("\n查找成功！\n查找过程冲突次数为%d．以下是您需要要查找的信息：\n\n", c);
        printf("姓  名：%s\n电话号码：%s\n联系地址：%s\n", H->elem[pp]->name, H->elem[pp]->tel, H->elem[pp]->add);
    }
    else
        printf("\n此人不存在，查找不成功!\n");
    benGetTime();
}

void benGetTime()
{
    SYSTEMTIME sys;
    GetLocalTime(&sys);
    printf("%4d/%02d/%02d %02d:%02d:%02d.%03d \n", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wMilliseconds);
}

void CreateHash2(HashTable *H, Record *a)
{   //建表，以电话号码为关键字，建立相应的散列表
    //若哈希地址冲突，进行冲突处理
    benGetTime();
    int i, p = -1, c, pp;
    for (i = 0; i < NUM_BER; i++)
    {
        c = 0;
        p = Hash2(a[i].tel);
        pp = p;
        while (H->elem[pp] != NULL)
        {
            pp = collision(p, c);
            if (pp < 0)
            {
                printf("第%d记录无法解决冲突", i + 1); //需要显示冲突次数时输出
                continue;
            } //无法解决冲突，跳入下一循环
        }
        H->elem[pp] = &(a[i]); //求得哈希地址，将信息存入
        H->count++;
        printf("第%d个记录冲突次数为%d。\n", i + 1, c); //需要显示冲突次数时输出
    }
    printf("\n建表完成!\n此哈希表容量为%d,当前表内存储的记录个数为%d.\n", HASHSIZE, H->count);
    benGetTime();
}

void SearchHash2(HashTable *H, int &c)
{   //在通讯录里查找电话号码关键字，若查找成功，显示信息
    //c用来记录冲突次数,查找成功时显示冲突次数
    benGetTime();
    NA tele;
    printf("\n请输入要查找记录的电话号码：\n");
    scanf("%s", tele);
    int p, pp;
    p = Hash2(tele);
    pp = p;
    while ((H->elem[pp] != NULL) && (!eq(tele, H->elem[pp]->tel)))
        pp = collision(p, c);
    if (H->elem[pp] != NULL && eq(tele, H->elem[pp]->tel))
    {
        printf("\n查找成功！\n查找过程冲突次数为%d．以下是您需要要查找的信息：\n\n", c);
        printf("姓  名：%s\n电话号码：%s\n联系地址：%s\n", H->elem[pp]->name, H->elem[pp]->tel, H->elem[pp]->add);
    }
    else
        printf("\n此人不存在，查找不成功!\n");
    benGetTime();
}

void Save()
{
    FILE *fp;
    if ((fp = fopen("d:\test.txt", "w")) == NULL)
    {
        printf("\nERROR opening customet file");
    }
    fclose(fp);
}
int main()
{
    int c, flag = 1;
    HashTable *H;
    H = (HashTable *)malloc(sizeof(HashTable));
    for (int i = 0; i < HASHSIZE; i++)
        H->elem[i] = NULL;
    H->size = HASHSIZE;
    H->count = 0;
    Record a[MAXSIZE];
    while (true)
    {
        printf("\n                      ┏━━━━━━━━━━━━━━━━━━━━━━━━┓                ");
        printf("\n                      ┃ 欢迎使用电话号码查找系统 ┃                ");
        printf("\n       ┏〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓┓");
        printf("\n       ┃           1.  添加用户信息                              ┃");
        printf("\n       ┃           2.  读取所有用户信息                          ┃");
        printf("\n       ┃           3.  以姓名建立哈希表(再哈希法解决冲突)        ┃");
        printf("\n       ┃           4.  以电话号码建立哈希表(再哈希法解决冲突)    ┃");
        printf("\n       ┃           5.  查找并显示给定用户名的记录                ┃");
        printf("\n       ┃           6.  查找并显示给定电话号码的记录              ┃");
        printf("\n       ┃           7.  清屏                                      ┃");
        printf("\n       ┃           8.  保存                                      ┃");
        printf("\n       ┃           9.  退出程序                                  ┃");
        printf("\n       ┗〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓┛");
        printf("\n");
        printf("请输入一个任务选项>>>");
        printf("\n");
        int num;
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            getinf(a);
            break;
        case 2:
            ShowInf(a);
            break;
        case 3:
            CreateHash1(H, a); /* 以姓名建立哈希表 */
            break;
        case 4:
            CreateHash2(H, a); /* 以电话号码建立哈希表 */
            break;
        case 5:
            c = 0;
            SearchHash1(H, c);
            break;
        case 6:
            c = 0;
            SearchHash2(H, c);
            break;
        case 7:
            Cls(a);
            break;
        case 8:
            Save();
            break;
        case 9:
            return 0;
            break;
        default:
            printf("你输错了，请重新输入!");
            printf("\n");
        }
    }

    system("pause");
    return 0;
}