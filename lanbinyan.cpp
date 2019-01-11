#include <iostream>
#include <string>

#define MAX_TRAIN 3
#define MAX_CITY 10
using namespace std;

//定义站点结点
class Station{
public:
    string station_name;        //站名
    int arrive_time_hour;
    int arrive_time_minute;
    int residence_time;         //停留时间
    int price;                  //始发站到此站的价格
    Station* next;
	Station(){
		cout<<"你个智障"<<endl;
	}
    Station(string sn,int ath,int atm,int rt,int p){
        station_name = sn;
        arrive_time_hour = ath;
        arrive_time_minute = atm;
        residence_time = rt;
        price = p;
    }
};

//定义车次信息结点
class Train{
public:
    string train_number;        //车次
    string departure_station;   //始发站名
    int departure_time_hour;
    int departure_time_minute;
    int rated_ticket_num;       //额定票数
    Station* next;

    //构造函数
    Train(){
    	cout<<"你是谁啊"<<endl;
    }
    Train(string tn,string ds,int dth,int dtm,int rtn,Station* s){
        string train_number = tn;        
        departure_station = ds;   
        departure_time_hour = dth;
        departure_time_minute = dtm;
        rated_ticket_num = rtn;
        next = s;
    }

    //增加站点
    void add_station(string sn,int ath,int atm,int rt,int p){
        Station s(sn,ath,atm,rt,p);
        s.next = NULL;
        Station *q = next;
        while(q->next) q = q->next;
        q->next = &s;
    }
};


typedef struct train_node{
	int train_number;
	train_node * next;
}train_node,*train_info;

typedef struct{//城市信息节点
	string city_name;
	int total_train;
	train_info nextinfo;	
}City_linklist;

class City_Train_info{//车次下一站的图 
	public:
		City_linklist *Index_list;
		
		City_Train_info(Train *e){//对车次信息表进行遍历，获取与某一城市有关的 
			Index_list = new City_linklist[MAX_CITY];
			for(int i=0;i<MAX_CITY;i++)
				Index_list[i].total_train=0;
			for(int i=0;i<MAX_TRAIN;i++){
				int count = 0;//用来指示当前应插入位置 
				Station *ss = e[i].next; 
				string name = ss->station_name;
				int a = already_exist(name);
				if(a==-1){
					Index_list[count].city_name=name;
					Index_list[count].total_train++;
					count++;
					Index_list[count].nextinfo =new train_node;
					Index_list[count].nextinfo->train_number=i;
					Index_list[count].nextinfo->next=NULL;
				} 
				else{
					train_info cc = Index_list[a].nextinfo;
					while(cc->next!=NULL){
						cc=cc->next;
					}	
					cc->train_number=i;	
					Index_list[a].total_train++;			
				}
			}
		}
		
		//判断表中是否已经存在以a为头的链表。 
		int already_exist(string a){
			for(int i = 0;i < MAX_CITY;i++){
				if(Index_list[i].city_name==a)
					return i;
			}
			return -1;				
		}
		
		void show(){
			for(int i=0;i<MAX_CITY;i++){
				train_info a = Index_list[i].nextinfo;
				cout<<Index_list[i].city_name;
				while(a!=NULL){
					cout<<a->train_number;
					a=a->next;
					if(a!=NULL) cout<<"、"; 
				}
			}
		}
};

class Ordered
int main(void){
	Train *e =new Train[MAX_TRAIN];
	for(int i=0;i<MAX_TRAIN;i++){
		e.Train("G123","南京",8,20,1000,new Station);
	}
	City_Train_info index = City_Train_info(e);
	return 0;
}
