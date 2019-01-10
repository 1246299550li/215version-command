#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
int x = 0;
char a;
int j = 1;
struct TeleNumber //������
{
    char name[20];    //����
    int phoneNumber;  //�̶��绰����
    int mobileNumber; //�ƶ��绰����
    char email[30];   //��������
    int s;
    TeleNumber *Next;
    void ReadFile(istream &in);
    void input();
    void display();
};
void TeleNumber::ReadFile(istream &in) //���ļ������ݶ��뵽����
{
    in >> name >> phoneNumber >> mobileNumber >> email;
}
void TeleNumber::input() //��Ϣ����
{
    cout << "����������" << endl;
    cin >> name;
    cout << "������̶��绰����" << endl;
    cin >> phoneNumber;
    cout << "�������ƶ��绰����" << endl;
    cin >> mobileNumber;
    cout << "�������������" << endl;
    cin >> email;
    s = j++;
}
void TeleNumber::display() //��Ϣ���
{
    cout << "����:" << name << '\t' << "�̶�����:" << phoneNumber << '\t'
         << "�ƶ��绰����:" << mobileNumber << '\t' << "��������:" << email << endl;
}
class TeleMessage //������
{
  public:
    TeleMessage();              //�������ݽṹ
    ~TeleMessage();             //�ͷŵ�����
    void Save();                //���ݱ��浽�ļ�
    TeleNumber *Search(char *); //��Ϣ����
    void Insert();              //����
    void Remove();              //ɾ��
    void Change();              //����
    void Show();                //��ʾ
  private:
    TeleNumber *End, *Head;
    ifstream in; //�������д�ļ�����
    ofstream out;
};
TeleMessage::TeleMessage()
{
    Head = new TeleNumber; //ͷ�巨����������
    Head->Next = new TeleNumber;
    End = Head->Next;
    in.open("TeleNumber.txt"); //������ļ������Ƿ������ݴ���
    if (!in)
        cout << "�绰ϵͳ��û���κκ��룬���������" << endl;
    else
    {
        in.close();
        cout << "��ȡ�绰����ϵͳ�ɹ�!" << endl;
    }
}
TeleMessage::~TeleMessage() //�ͷŵ�����0
{
    TeleNumber *temp;
    while (Head->Next != End)
    {
        temp = Head->Next;
        Head = Head->Next;
        delete temp;
    }
    delete Head, End; //ɾ��ͷβָ��
}
void TeleMessage::Save() //�����ļ�
{
    out.open("TeleNumber.txt"); //��������ļ�TeleNumber.txt
    for (TeleNumber *p = Head->Next; p != End; p = p->Next)
        out << p->name << "\t" << p->phoneNumber << "\t" << p->mobileNumber << "\t" << p->email << endl; //�����ݴ浽����ļ���
    out.close();
    cout << "����ɹ���" << endl;
}
void TeleMessage::Insert() //����
{
    End->input(); //�ӵ�����β������
    End->Next = new TeleNumber;
    End = End->Next;
    cout << endl
         << "����ɹ�" << endl;
}
void TeleMessage::Remove() //ɾ��
{
    char name[20];
    TeleNumber *p = new TeleNumber, *temp = NULL;
    cout << "������Ҫɾ���˵�����:" << endl;
    cin >> name;
    p->Next = Search(name); //�Ƚ��в��ң��ҵ���Ҫɾ���Ľ��
    if (Search(name))
    {
        temp = p->Next;
        p->Next = p->Next->Next; //ժ��
        delete temp;
        cout << "ɾ���ɹ�!" << endl;
    }
    else
    {
        cout << "û���ҵ�!" << endl;
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
        cout << "���޴���" << endl;
    return 0;
}
void TeleMessage::Change() //�޸���Ϣ
{
    char name[20];
    cout << "������Ҫ�޸ĵ��˵�����:";
    cin >> name;
    if (Search(name))
    {
        cout << "���ҵ����˵���Ϣ���������µ���Ϣ!" << endl;
        Search(name)->input();
        cout << "�޸ĳɹ���" << endl;
    }
    else
    {
        cout << "û���ҵ�!" << endl;
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
        cout << "�򵥸��˵绰�����ѯϵͳ" << endl
             << endl;
        cout << "1.������Ϣ" << endl;
        cout << "2.��ʾ��Ϣ" << endl;
        cout << "3.���Һ���" << endl;
        cout << "4.ɾ����Ϣ" << endl;
        cout << "5.�޸���Ϣ" << endl;
        cout << "6.������Ϣ" << endl;
        cout << "0.�˳�ϵͳ" << endl
             << endl;
        cout << "��ѡ��";
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
            cout << "����������" << endl;
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