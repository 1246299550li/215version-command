#include <iostream>
#include <string>
#define MAX_TRAIN 6
#define MAX_CITY 12
using namespace std;

//����վ����
class Station
{
  public:
    int station_num; //վ��
    int arrive_time_hour;
    int arrive_time_minute;
    int residence_time; //ͣ��ʱ��
    int price;          //ʼ��վ����վ�ļ۸�
    bool searched;
    Station *next;

    Station(int sn, int ath, int atm, int rt, int p)
    {
        station_num = sn;
        arrive_time_hour = ath;
        arrive_time_minute = atm;
        residence_time = rt;
        price = p;
    }
};

//���峵����Ϣ��
class Train
{
  public:
    string train_number;      //����
    int departure_station; //ʼ��վ��
    int departure_time_hour;
    int departure_time_minute;
    int rated_ticket_num; //�Ʊ��
    Station *next;

    //���캯��
    Train(string tn, int ds, int dth, int dtm, int rtn, Station *s)
    {
        string train_number = tn;
        departure_station = ds;
        departure_time_hour = dth;
        departure_time_minute = dtm;
        rated_ticket_num = rtn;
        next = s;
    }

    //����վ��
    void add_station(int sn, int ath, int atm, int rt, int p)
    {
        Station s(sn, ath, atm, rt, p);
        s.next = NULL;
        Station *q = next;
        while (q->next)
            q = q->next;
        q->next = &s;
    }
};

typedef struct train_node
{
    int train_number;
    int next_city;
    int arrive_time_hour;
    int arrive_time_minute;
    int residence_time;     //ͣ��ʱ��
    train_node *next;
} train_node, *train_info;

typedef struct
{ //������Ϣ�ڵ�
    int total_train;
    train_info nextinfo;
} City_linklist;

class City_Train_info
{ //������һվ��ͼ
  public:
    City_linklist *Index_list;
    City_Train_info(Train *e){ 
        //�Գ�����Ϣ����б�������ȡ��ĳһ�����йص�
        Index_list = new City_linklist[MAX_CITY];        
        for (int i = 0; i < MAX_CITY; i++)
            Index_list[i].total_train = 0;//�����е�����վ���е����г������ȸ�ֵ0
        Station *countcc=NULL;
        train_info temp = NULL;
        int name = -1;
        for(int count=0;count<MAX_TRAIN;count++){
            //���ȼ�¼��ʼվ��
            name = e[count].departure_station;
            temp=Index_list[name].nextinfo;
            Index_list[name].total_train++;
            while(temp!=NULL) temp=temp->next;//�ҵ�����λ��
            temp->arrive_time_hour=e[count].departure_time_hour;
            temp->arrive_time_minute=e[count].departure_time_minute;
            temp->residence_time=0;
            temp->train_number=count;
            temp->next_city=e[count].next->station_num;
            //�����¼�м�վ���
            countcc=e[count].next;
            while(countcc!=NULL){
                name=countcc->station_num;
                temp=Index_list[name].nextinfo;
                Index_list[name].total_train++;
                while(temp!=NULL) temp=temp->next;//�ҵ�����λ��
                temp->arrive_time_hour=countcc->arrive_time_hour;
                temp->arrive_time_minute=countcc->arrive_time_minute;
                temp->residence_time=countcc->residence_time;
                temp->train_number=count;
                temp->next_city=countcc->next->station_num;
            }
        }      
    }
};

class Ticket{
    public:
        int train_num;//�г����
        int origin_stop;//��ʼվ
        int destination;//�³�վ
        int start_hour;//��ʱ����ʱ��
        int start_minute;//����
        int arrive_hour;
        int arrive_minute;
        int price;//Ʊ��

        Ticket(int start,int destination,int train_num){
            
        }
        void set_start(int o,int h,int m){//o����ʼվ��h,m����ʼվ��ʱ��
            origin_stop=o;
            start_hour=h;
            start_minute=m;
        }
        void set_destination(int d,int h,int m){
            //�³�վ����Ϣ
            destination=d;
            arrive_hour=h;
            arrive_minute=m;
        } 
        void set_basic(int t,int p){
            //����������Ϣ
            train_num=t;
            price=p;
        }       
};
class Tickets{
    public:
        Ticket Capable[MAX_TRAIN];

};
class Ordered{
    public:
        
};

