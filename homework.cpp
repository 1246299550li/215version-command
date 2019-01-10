#include <regex>
#include <string>
//好大一锅粥
using namespace std;
class TS
{

  private:
	string A;
	unsigned long long theTimestamp;
	short theWeekday;

	unsigned long long my_atoi(string aa) //将字符串转换为数字的atoi()
	{
		unsigned long long num = 0;
		for (unsigned int i = 0; i < aa.size(); i++)
			num = num * 10 + aa[i] - '0';
		return num;
	}

	void Check_ChineseandEnglish() //处理字符串中的中英文
	{
		if (regex_search(A, regex("[\u4e00-\u9fa5]"))) //处理中文//"十"没精力处理了
		{
			string Chinese[12] = {"月|年", "零|〇", "一|壹", "二|贰", "三|叁", "四|肆", "五|伍", "六|陆", "七|柒", "八|捌", "九|玖", "日"};
			string Num[12] = {"/", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ""};
			for (int i = 0; i < 12; i++)
				A = regex_replace(A, regex(Chinese[i]), Num[i]);
		}
		if (regex_search(A, regex("[a-zA-Z]"))) //处理英文
		{
			string English[12] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
			string Num[12] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};
			for (int i = 0; i < 12; i++)
				A = regex_replace(A, regex(English[i], regex::icase), Num[i]);
		}
		A = regex_replace(A, regex("[\\|\\\\/\\- ]{2,}"), "/"); //处理类似2018//09/22多了一个/的情况
	}

	bool Check_date() //检查来自字符串的日期是否合法
	{
		int day_num[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		day_num[2] += ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
		if (Year < 1970 || Year > 30000000)
			return 0;
		if (Month < 1 || Month > 12)
			return 0;
		if (Day > day_num[Month])
			return 0;
		return 1;
	}

	bool separate_A() //从字符串提取出年月日
	{
		A = regex_replace(A, regex("^(\\d{4,})(\\d{2})(\\d{2})$"), "$1/$2/$3"); //给没有/的加/
		smatch result;
		if (regex_match(A, result, regex("^(\\d{4,})/(\\d+)/(\\d+)$"))) //按照/提取年月日
		{
			Year = my_atoi(result[1]);
			Month = my_atoi(result[2]);
			Day = my_atoi(result[3]);
			if (Check_date())
				return 1;
			else //年月日不合法
			{
				Year = 0;
				Month = 0;
				Day = 0;
				return 0;
			}
		}
		else
			return 0; //格式不对无法提取
	}

	short calc_Weekday() //Zeller formula
	{
		short m = Month, d = Day;
		unsigned long long y = Year;
		if (m <= 2)
			m += 12, y--;
		unsigned long long c = y / 100;
		y %= 100;
		short w = ((y + (y >> 2) + (c >> 2) - (c << 1) + 13 * (m + 1) / 5 + d - 1) % 7 + 7) % 7;
		if (!w)
			w = 7;
		return w;
	}
	unsigned long long calc_Timestamp() //计算时间戳//计算天数算法来自https://baijiahao.baidu.com/s?id=1591401653797777926
	{
		short m = Month, d = Day;
		unsigned long long y = Year;
		m = (m + 9) % 12;
		if (!m)
			m = 12;
		y = y - m / 10;
		unsigned long long num_day = 365 * y + (y >> 2) - y / 100 + y / 400 + (m * 306 + 5) / 10 + (d - 1);
		return (num_day - 719468) * 86400;
	}

  public:
	unsigned long long Year;
	short Month;
	short Day;
	short Hour;
	short Minute;
	short Second;
	bool operator=(const string &a) //返回结果是否赋值成功
	{
		bool succeed = 0;
		if (regex_search(A, regex("[^零一二三四五六七八九〇壹贰叁肆伍陆柒捌玖年月日\\d\\w/\\-\\|\\\\ ]"))) //字符集是否合法
			return 0;
		else
			A = a, Check_ChineseandEnglish(); //转化为2018
		if (separate_A())
			succeed = 1;
		else
		{
			A = "";
			return 0;
		}
		Hour = Minute = Second = 0;
		theWeekday = calc_Weekday();
		theTimestamp = calc_Timestamp();
		return succeed;
	}
	short ask_Weekday()
	{
		return theWeekday;
	}
	unsigned long long ask_Timestamp()
	{
		return theTimestamp;
	}
};

#include <iostream>
int main()
{
	int a;
	while (1)
	{
		string aa;
		getline(cin,aa);
		TS H;
		if (H = aa)
			cout << H.Year << " " << H.Month << " " << H.Day << " " << H.ask_Weekday() << " " << H.ask_Timestamp();
		else{
			cout<<"非法"<<endl;
		}
	}
	cin >> a;
	return 0;
}
