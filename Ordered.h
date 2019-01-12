#include <iostream>
using namespace std;

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
};
class Ordered{
    public:
        
};

