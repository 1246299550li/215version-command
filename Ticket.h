#include <iostream>
#include <string>
#define MAX_TRAIN 6
#define MAX_CITY 12
using namespace std;

//定义站点类
class Station
{
  public:
    int station_num; //站名
    int arrive_time_hour;
    int arrive_time_minute;
    int residence_time; //停留时间
    int price;          //始发站到此站的价格
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

//定义车次信息类
class Train
{
  public:
    string train_number;      //车次
    int departure_station; //始发站名
    int departure_time_hour;
    int departure_time_minute;
    int rated_ticket_num; //额定票数
    Station *next;

    //构造函数
    Train(string tn, int ds, int dth, int dtm, int rtn, Station *s)
    {
        string train_number = tn;
        departure_station = ds;
        departure_time_hour = dth;
        departure_time_minute = dtm;
        rated_ticket_num = rtn;
        next = s;
    }

    //增加站点
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
    int residence_time;     //停留时间
    train_node *next;
} train_node, *train_info;

typedef struct
{ //城市信息节点
    int total_train;
    train_info nextinfo;
} City_linklist;

class City_Train_info
{ //车次下一站的图
  public:
    City_linklist *Index_list;
    City_Train_info(Train *e){ 
        //对车次信息表进行遍历，获取与某一城市有关的
        Index_list = new City_linklist[MAX_CITY];        
        for (int i = 0; i < MAX_CITY; i++)
            Index_list[i].total_train = 0;//将表中的所有站点中的所有车数量先赋值0
        Station *countcc=NULL;
        train_info temp = NULL;
        int name = -1;
        for(int count=0;count<MAX_TRAIN;count++){
            //首先记录起始站点
            name = e[count].departure_station;
            temp=Index_list[name].nextinfo;
            Index_list[name].total_train++;
            while(temp!=NULL) temp=temp->next;//找到最后的位置
            temp->arrive_time_hour=e[count].departure_time_hour;
            temp->arrive_time_minute=e[count].departure_time_minute;
            temp->residence_time=0;
            temp->train_number=count;
            temp->next_city=e[count].next->station_num;
            //下面记录中间站结点
            countcc=e[count].next;
            while(countcc!=NULL){
                name=countcc->station_num;
                temp=Index_list[name].nextinfo;
                Index_list[name].total_train++;
                while(temp!=NULL) temp=temp->next;//找到最后的位置
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
        int train_num;//列车编号
        int origin_stop;//起始站
        int destination;//下车站
        int start_hour;//耗时长的时间
        int start_minute;//分钟
        int arrive_hour;
        int arrive_minute;
        int price;//票价

        Ticket(int start,int destination,int train_num){
            
        }
        void set_start(int o,int h,int m){//o是起始站，h,m是起始站的时间
            origin_stop=o;
            start_hour=h;
            start_minute=m;
        }
        void set_destination(int d,int h,int m){
            //下车站的信息
            destination=d;
            arrive_hour=h;
            arrive_minute=m;
        } 
        void set_basic(int t,int p){
            //车辆基本信息
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

