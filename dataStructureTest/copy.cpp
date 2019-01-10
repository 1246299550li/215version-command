#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
int x = 0;
char a;
int j = 1;
struct TeleNumber //数据类
{
    char name[20];    //姓名
    int phoneNumber;  //固定电话号码
    int mobileNumber; //移动电话号码
    char email[30];   //电子邮箱
    int s;
    TeleNumber *Next;
    void ReadFile(istream &in);
    void input();
    void display();
};
void TeleNumber::ReadFile(istream &in) //从文件把数据读入到程序
{
    in >> name >> phoneNumber >> mobileNumber >> email;
}
void TeleNumber::input() //信息输入
{
    cout << "请输入姓名" << endl;
    cin >> name;
    cout << "请输入固定电话号码" << endl;
    cin >> phoneNumber;
    cout << "请输入移动电话号码" << endl;
    cin >> mobileNumber;
    cout << "请输入电子邮箱" << endl;
    cin >> email;
    s = j++;
}
void TeleNumber::display() //信息输出
{
    cout << "姓名:" << name << '\t' << "固定号码:" << phoneNumber << '\t'
         << "移动电话号码:" << mobileNumber << '\t' << "电子邮箱:" << email << endl;
}
class TeleMessage //功能类
{
  public:
    TeleMessage();              //构造数据结构
    ~TeleMessage();             //释放单链表
    void Save();                //数据保存到文件
    TeleNumber *Search(char *); //信息查找
    void Insert();              //插入
    void Remove();              //删除
    void Change();              //更改
    void Show();                //显示
  private:
    TeleNumber *End, *Head;
    ifstream in; //定义读，写文件对象
    ofstream out;
};
TeleMessage::TeleMessage()
{
    Head = new TeleNumber; //头插法建立单链表
    Head->Next = new TeleNumber;
    End = Head->Next;
    in.open("TeleNumber.txt"); //打开外存文件，看是否有数据存在
    if (!in)
        cout << "电话系统中没有任何号码，请输入号码" << endl;
    else
    {
        in.close();
        cout << "读取电话号码系统成功!" << endl;
    }
}
TeleMessage::~TeleMessage() //释放单链表0
{
    TeleNumber *temp;
    while (Head->Next != End)
    {
        temp = Head->Next;
        Head = Head->Next;
        delete temp;
    }
    delete Head, End; //删除头尾指针
}
void TeleMessage::Save() //保存文件
{
    out.open("TeleNumber.txt"); //建立外存文件TeleNumber.txt
    for (TeleNumber *p = Head->Next; p != End; p = p->Next)
        out << p->name << "\t" << p->phoneNumber << "\t" << p->mobileNumber << "\t" << p->email << endl; //将数据存到外存文件里
    out.close();
    cout << "保存成功！" << endl;
}
void TeleMessage::Insert() //插入
{
    End->input(); //从单链表尾部插入
    End->Next = new TeleNumber;
    End = End->Next;
    cout << endl
         << "插入成功" << endl;
}
void TeleMessage::Remove() //删除
{
    char name[20];
    TeleNumber *p = new TeleNumber, *temp = NULL;
    cout << "请输入要删除人的姓名:" << endl;
    cin >> name;
    p->Next = Search(name); //先进行查找，找到所要删除的结点
    if (Search(name))
    {
        temp = p->Next;
        p->Next = p->Next->Next; //摘链
        delete temp;
        cout << "删除成功!" << endl;
    }
    else
    {
        cout << "没有找到!" << endl;
    }
}
TeleNumber *TeleMessage::Search(char *name)
{
    for (TeleNumber *p = Head->Next; p != End; p = p->Next)
        if (!strcmp(p->name, name))
        {
            if (x == 4)
            {
                p->display();
                return p;
            }
            else
                return p;
        }
    if (x == 4)
        cout << "查无此人" << endl;
    return 0;
}
void TeleMessage::Change() //修改信息
{
    char name[20];
    cout << "请输入要修改的人的姓名:";
    cin >> name;
    if (Search(name))
    {
        cout << "已找到个人的信息，请输入新的信息!" << endl;
        Search(name)->input();
        cout << "修改成功！" << endl;
    }
    else
    {
        cout << "没有找到!" << endl;
    }
}
void TeleMessage::Show()
{
    for (TeleNumber *p = Head->Next; p != End; p = p->Next)
        p->display();
}
int main()
{
    bool flag = true;
    TeleMessage tele;
    char name[20];
    while (flag)
    {
        // system("cls");
        cout << "简单个人电话号码查询系统" << endl
             << endl;
        cout << "1.增加信息" << endl;
        cout << "2.显示信息" << endl;
        cout << "3.查找号码" << endl;
        cout << "4.删除信息" << endl;
        cout << "5.修改信息" << endl;
        cout << "6.保存信息" << endl;
        cout << "0.退出系统" << endl
             << endl;
        cout << "请选择：";
        cin >> x;
        switch (x)
        {
        case 0:
            flag = false;
            break;
        case 1:
            tele.Insert();
            break;
        case 2:
            cout << "111";
            tele.Show();
            break;
        case 3:
            cout << "请输入姓名" << endl;
            cin >> name;
            tele.Search(name);
            break;
        case 4:
            tele.Remove();
            break;
        case 5:
            tele.Change();
            break;
        case 6:
            tele.Save();
            break;
        }
    }
    return 0;
}