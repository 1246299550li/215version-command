#include <iostream>
using namespace std;

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
};
class Ordered{
    public:
        
};

