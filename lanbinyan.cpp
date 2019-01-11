#include <iostream>
#include <string>

#define MAX_TRAIN 3
#define MAX_CITY 10
using namespace std;

//?????????
class Station{
public:
    string station_name;        //???
    int arrive_time_hour;
    int arrive_time_minute;
    int residence_time;         //??????
    int price;                  //?????????????
    Station* next;
	Station(){
		cout<<"???????"<<endl;
	}
    Station(string sn,int ath,int atm,int rt,int p){
        station_name = sn;
        arrive_time_hour = ath;
        arrive_time_minute = atm;
        residence_time = rt;
        price = p;
    }
};

//???t????????
class Train{
public:
    string train_number;        //????
    string departure_station;   //??????
    int departure_time_hour;
    int departure_time_minute;
    int rated_ticket_num;       //?????
    Station* next;

    //??????
    Train(){
    	cout<<"???????"<<endl;
    }
    Train(string tn,string ds,int dth,int dtm,int rtn,Station* s){
        string train_number = tn;        
        departure_station = ds;   
        departure_time_hour = dth;
        departure_time_minute = dtm;
        rated_ticket_num = rtn;
        next = s;
    }

    //???????
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

typedef struct{//??????????
	string city_name;
	int total_train;
	train_info nextinfo;	
}City_linklist;

class City_Train_info{//??????????? 
	public:
		City_linklist *Index_list;
		
		City_Train_info(Train *e){//????????????§Ò?????????????????§Û?? 
			Index_list = new City_linklist[MAX_CITY];
			for(int i=0;i<MAX_CITY;i++)
				Index_list[i].total_train=0;
			for(int i=0;i<MAX_TRAIN;i++){
				int count = 0;//??????????????¦Ë?? 
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
		
		//?§Ø????????????????a???????? 
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
					if(a!=NULL) cout<<"??"; 
				}
			}
		}
};

int main(void){
	cout<<"ÎÒ¼ÒÅªºÃ"<<endl;
	system("pause");
	return 0;
}
