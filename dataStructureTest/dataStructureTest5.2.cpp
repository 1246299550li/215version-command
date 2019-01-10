#include <cstdio>
#include <cstdlib>
#include <string>
#include <windows.h>
using namespace std;
#define MAXSIZE 20  //�绰����¼����
#define MAX_SIZE 20 //��������󳤶�
#define HASHSIZE 53 //�����

typedef char NA[MAX_SIZE];
 //��¼
typedef struct
{
    NA name;
    NA tel;
    NA add;
} Record;

typedef struct
{   //��ϣ��                        
    Record *elem[HASHSIZE]; //����Ԫ�ش洢��ַ
    int count;              //��ǰ����Ԫ�ظ���
    int size;               //��ǰ����
} HashTable;

bool eq(NA x, NA y)
{ //�ؼ��ֱȽϣ���ȷ���true�����򷵻�false
    if (strcmp(x, y) == 0)
        return true;
    else
        return false;
}

int NUM_BER; //��¼�ĸ���

char *strupr(char *str)
{
    char *orign=str;
    for (; *str!='\0'; str++)
        *str = toupper(*str);
    return orign;
}
void getinf(Record *a)
{ //����������˵���Ϣ
    printf("����Ҫ��ӵĸ�����\n");
    scanf("%d", &NUM_BER);
    int i;
    for (i = 0; i < NUM_BER; i++)
    {

        printf("�������%d����¼���û���:\n", i + 1);
        scanf("%s", a[i].name);
        printf("������%d����¼�ĵ绰����:\n", i + 1);
        scanf("%s", a[i].tel);
        printf("�������%d����¼�ĵ�ַ:\n", i + 1);
        scanf("%s", a[i].add);
    }
}

void ShowInf(Record *a) //��ʾ������û���Ϣ
{
    int i;
    for (i = 0; i < NUM_BER; i++)
        printf("\n��%d���û���Ϣ:\n ��    ����%s\n �绰���룺%s\n ��ϵ��ַ��%s\n", i + 1, a[i].name, a[i].tel, a[i].add);
}

void Cls(Record *a)
{
    printf("*");
    system("cls");
}
long fold(NA s)
{ //�������۵�����
    char *p;
    long sum = 0;
    NA ss;
    strcpy(ss, s); //�����ַ��������ı�ԭ�ַ����Ĵ�Сд

    strupr(ss);    //���ַ���ssת��Ϊ��д��ʽ
    p = ss;
    while (*p != '\0')
        sum += *p++;
    printf("\nsum====================%d", sum);
    return sum;
}

int Hash1(NA str)
{ //��ϣ����
    long n;
    int m;
    n = fold(str);    //�Ƚ��û��������۵�����
    m = n % HASHSIZE; //�۵������������ó��������������ϣ����
    return m;         //������ģֵ
}

int Hash2(NA str)
{ //��ϣ����
    long n;
    int m;
    n = atoi(str);    //���ַ���ת����������.
    m = n % HASHSIZE; //�ó��������������ϣ����
    return m;         //������ģֵ
}

int collision(int p, int &c)
{ //��ͻ�����������ö���̽����ɢ�з������ͻ
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
{   //�������˵�����Ϊ�ؼ��֣�������Ӧ��ɢ�б�
    //����ϣ��ַ��ͻ�����г�ͻ����
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
                printf("��%d��¼�޷������ͻ", i + 1); //��Ҫ��ʾ��ͻ����ʱ���
                continue;
            } //�޷������ͻ��������һѭ��
        }
        H->elem[pp] = &(a[i]); //��ù�ϣ��ַ������Ϣ����
        H->count++;
        printf("��%d����¼��ͻ����Ϊ%d��\n", i + 1, c); //��Ҫ��ʾ��ͻ����ʱ���
    }
    printf("\n�������!\n�˹�ϣ������Ϊ%d,��ǰ���ڴ洢�ļ�¼����Ϊ%d.\n", HASHSIZE, H->count);
    benGetTime();
}

void SearchHash1(HashTable *H, int &c)
{   //��ͨѶ¼����������ؼ��֣������ҳɹ�����ʾ��Ϣ
    //c������¼��ͻ����,���ҳɹ�ʱ��ʾ��ͻ����
    benGetTime();
    NA str;
    printf("\n������Ҫ���Ҽ�¼��������\n");
    scanf("%s", str);
    int p, pp;
    p = Hash1(str);
    pp = p;
    while ((H->elem[pp] != NULL) && (!eq(str, H->elem[pp]->name)))
        pp = collision(p, c);
    if (H->elem[pp] != NULL && eq(str, H->elem[pp]->name))
    {
        printf("\n���ҳɹ���\n���ҹ��̳�ͻ����Ϊ%d������������ҪҪ���ҵ���Ϣ��\n\n", c);
        printf("��  ����%s\n�绰���룺%s\n��ϵ��ַ��%s\n", H->elem[pp]->name, H->elem[pp]->tel, H->elem[pp]->add);
    }
    else
        printf("\n���˲����ڣ����Ҳ��ɹ�!\n");
    benGetTime();
}

void benGetTime()
{
    SYSTEMTIME sys;
    GetLocalTime(&sys);
    printf("%4d/%02d/%02d %02d:%02d:%02d.%03d \n", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wMilliseconds);
}

void CreateHash2(HashTable *H, Record *a)
{   //�����Ե绰����Ϊ�ؼ��֣�������Ӧ��ɢ�б�
    //����ϣ��ַ��ͻ�����г�ͻ����
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
                printf("��%d��¼�޷������ͻ", i + 1); //��Ҫ��ʾ��ͻ����ʱ���
                continue;
            } //�޷������ͻ��������һѭ��
        }
        H->elem[pp] = &(a[i]); //��ù�ϣ��ַ������Ϣ����
        H->count++;
        printf("��%d����¼��ͻ����Ϊ%d��\n", i + 1, c); //��Ҫ��ʾ��ͻ����ʱ���
    }
    printf("\n�������!\n�˹�ϣ������Ϊ%d,��ǰ���ڴ洢�ļ�¼����Ϊ%d.\n", HASHSIZE, H->count);
    benGetTime();
}

void SearchHash2(HashTable *H, int &c)
{   //��ͨѶ¼����ҵ绰����ؼ��֣������ҳɹ�����ʾ��Ϣ
    //c������¼��ͻ����,���ҳɹ�ʱ��ʾ��ͻ����
    benGetTime();
    NA tele;
    printf("\n������Ҫ���Ҽ�¼�ĵ绰���룺\n");
    scanf("%s", tele);
    int p, pp;
    p = Hash2(tele);
    pp = p;
    while ((H->elem[pp] != NULL) && (!eq(tele, H->elem[pp]->tel)))
        pp = collision(p, c);
    if (H->elem[pp] != NULL && eq(tele, H->elem[pp]->tel))
    {
        printf("\n���ҳɹ���\n���ҹ��̳�ͻ����Ϊ%d������������ҪҪ���ҵ���Ϣ��\n\n", c);
        printf("��  ����%s\n�绰���룺%s\n��ϵ��ַ��%s\n", H->elem[pp]->name, H->elem[pp]->tel, H->elem[pp]->add);
    }
    else
        printf("\n���˲����ڣ����Ҳ��ɹ�!\n");
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
        printf("\n                      ����������������������������������������������������                ");
        printf("\n                      �� ��ӭʹ�õ绰�������ϵͳ ��                ");
        printf("\n       ��������������������������������������������������������������");
        printf("\n       ��           1.  ����û���Ϣ                              ��");
        printf("\n       ��           2.  ��ȡ�����û���Ϣ                          ��");
        printf("\n       ��           3.  ������������ϣ��(�ٹ�ϣ�������ͻ)        ��");
        printf("\n       ��           4.  �Ե绰���뽨����ϣ��(�ٹ�ϣ�������ͻ)    ��");
        printf("\n       ��           5.  ���Ҳ���ʾ�����û����ļ�¼                ��");
        printf("\n       ��           6.  ���Ҳ���ʾ�����绰����ļ�¼              ��");
        printf("\n       ��           7.  ����                                      ��");
        printf("\n       ��           8.  ����                                      ��");
        printf("\n       ��           9.  �˳�����                                  ��");
        printf("\n       ��������������������������������������������������������������");
        printf("\n");
        printf("������һ������ѡ��>>>");
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
            CreateHash1(H, a); /* ������������ϣ�� */
            break;
        case 4:
            CreateHash2(H, a); /* �Ե绰���뽨����ϣ�� */
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
            printf("������ˣ�����������!");
            printf("\n");
        }
    }

    system("pause");
    return 0;
}