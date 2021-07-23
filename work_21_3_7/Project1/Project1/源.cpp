/*//设计一个程序能计算一个日期加上若干天后是什么日期。
//输入描述 :
//输入第一行表示样例个数m，接下来m行每行四个整数分别表示年月日和累加的天数。
//输出描述 :
//输出m行，每行按yyyy - mm - dd的个数输出。
//示例1
//输入
//1
//2008 2 3 100
//输出
//2008 - 05 - 13*/
//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		//判断日期是否有效
//		if (year <= 0 || month <= 0 || month > 12 || day <= 0 || day > getDay(year, month))
//		{
//			//日期无效,设为默认值
//			_year = 1; _month = 1; _day = 1;
//			cout << "日期无效，设为默认值 1-1-1 " << endl;
//		}
//		_year = year; _month = month; _day = day;
//		//this->display();	
//	}
//	int getDay(int year, int month);
//	Date& operator+=(int day)
//	{
//		_day += day;
//		while (_day > getDay(_year, _month))
//		{
//			_day -= getDay(_year, _month);
//			++_month;
//			if (_month == 13)
//			{
//				++_year;
//				_month = 1;
//			}
//		}
//		while (_day <= 0)
//		{
//			_day += getDay(_year, --_month);
//			if (_month == 0)
//			{
//				--_year;
//				_month = 13;
//			}
//		}
//		return *this;
//	}
//	void display()
//	{
//		cout << _year << '-';
//		if (_month < 10)
//			cout << 0 << _month;
//		else
//			cout << _month;
//		if (_day < 10)
//			cout << '-' << 0 << _day <<endl;
//		else
//			cout << '-' << _day <<endl;
//		
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int Date::getDay(int year, int month)
//{
//	static int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int day = days[month];
//	if (month == 2 && ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//	{
//		day += 1;
//	}
//	return day;
//}
//
//void test()
//{
//	//一个数据
//	/*int i=0;
//	cin >> i;
//	cout << i << endl;
//	int *d = NULL;
//	d = (int *)malloc(i * 4 * sizeof(int));
//	cin >> *d >> *(d + 1) >> *(d + 2) >> *(d + 3);
//	cout << *d << '-' << *(d + 1) << '-' << *(d + 2) << ':' << *(d + 3) << endl;
//	Date date(*d, *(d + 1), *(d + 2));
//	date.operator+=(*(d + 3));
//	date.display();*/
//
//	//m个数据
//	int m = 0;
//	cin >> m;
//	//cout << m << endl;
//	//int *d1 = NULL, *d = NULL;
//	/*int *d1, *d;
//	d1 = (int *)malloc(m * 4 * sizeof(int));
//	d = d1;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> *(d + i * 4 - 4) >> *(d + i * 4 - 3) >> *(d + i * 4 - 2) >> *(d + i * 4 - 1);
//	}
//	cout << "输入结束！" << endl;
//	for (int i = 0; i < m; i++)
//	{
//		cout << *(d + i * 4 - 4) << '-' << *(d + i * 4 - 3) << '-' << *(d + i * 4 - 2) << ':' << *(d + i * 4 - 1) << endl;
//		Date date(*(d + i * 4 - 4), *(d + i * 4 - 3), *(d + i * 4 - 2));
//		date.operator+=(*(d + i * 4 - 1));
//		date.display();
//	}
//	cout << "输出结束！" << endl;
//	for (int i = 0; i < m;i++)
//		free(*d);
//	free(d);*/
//	
//	int *d1, *d;
//	d1 = (int *)malloc(m * 4 * sizeof(int));
//	d = d1;
//	for (int i = 1; i <= m; i++)
//	{
//		//两种写法皆可
//		//cin >> *(d + i * 4 - 4) >> *(d + i * 4 - 3) >> *(d + i * 4 - 2) >> *(d + i * 4 - 1);
//		cin >> d[i * 4 - 4] >> d[i * 4 - 3] >> d[i * 4 - 2] >> d[i * 4 - 1];
//	}
//	//cout << "输入结束！" << endl;
//	cout << "输出结果" << endl;
//	for (int i = 1; i <= m; i++)
//	{
//		//cout << *(d + i * 4 - 4) << '-' << *(d + i * 4 - 3) << '-' << *(d + i * 4 - 2) << ':' << *(d + i * 4 - 1) << endl;
//		Date date(*(d + i * 4 - 4), *(d + i * 4 - 3), *(d + i * 4 - 2));
//		date.operator+=(*(d + i * 4 - 1));
//		date.display();
//	}
//	//cout << "输出结束！" << endl;
//	
//	free(d);
//	//cout << *d << '-' << *(d + 1) << '-' << *(d + 2) << ':' << *(d + 3) << endl;
//	/*Date date(*d, *(d + 1), *(d + 2));
//	date.operator+=(*(d + 3));
//	date.display();*/
//}
//
//int main()
//{
//	test();
//	/*int i, j;
//	cin >> i >> j;
//	cout << i << '-';
//	cout<< 0 << j << endl;*/
//	
//
//	system("pause");
//	return 0;
//}

/*给出年分m和一年中的第n天，算出第n天是几月几号。
输入描述 :
输入包括两个整数y(1 <= y <= 3000)，n(1 <= n <= 366)。
输出描述 :
可能有多组测试数据，对于每组数据，
按 yyyy - mm - dd的格式将输入中对应的日期打印出来。*/
//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year, int day)
//	{
//		//cout << getDays(year) << endl;
//		//判断日期是否有效
//		if (!(year <= 0 || day > getDays(year)))
//		{
//			//日期有效
//			_year = year;
//			m_d = day;
//		}
//		
//	}
//	int getDays(int year);
//	int getDay(int year,int month);
//	Date& operator-=(int day)
//	{
//		if (_year <= 0 || day > getDays(_year))
//		{
//			//日期无效
//			_year = 0; _month = 0; _day = 0;
//		}
//		else
//		{
//			_day = day;
//			_month = 1;
//			while (_day > getDay(_year, _month))
//			{
//				//int i = getDay(_year, _month);
//				_day -= getDay(_year, _month);
//				_month++;
//			}
//	
//		}
//		return *this;
//	}
//	void display()
//	{
//		this->operator-=(this->m_d);
//		cout << _year << '-';
//		if (_month < 10)
//			cout << 0 << _month;
//		else
//			cout << _month;
//		if (_day < 10)
//			cout << '-' << 0 << _day << endl;
//		else
//			cout << '-' << _day << endl;
//
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	int m_d;
//};
//static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//int Date::getDays(int year)
//{
//	int num = 0;
//	for (int i = 1; i <= 13; i++)
//	{
//		num += days[i];
//	}
//	
//	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
//	{
//		num += 1;
//	}
//	return num;
//}
//int Date::getDay(int year, int month)
//{
//	static int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int day = days[month];
//	if (month == 2 && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)))
//	{
//		day += 1;
//	}
//	return day;
//}
//
//void test()
//{
//	int i, j;
//	//while (cin >> i >> j)
//	//{
//	cin >> i >> j;
//		Date d(i, j);
//		//d.operator-=(52);
//		d.display();
//		i = 0; j = 0;
//	//}
//}
//
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

/*有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天
输入描述:
有多组数据，每组数据有两行，分别表示两个日期，形式为YYYYMMDD
输出描述:
每组数据输出一行，即日期差值*/
/*
//!!!!方法一
//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		//判断日期是否有效
//		if (year <= 0 || month <= 0 || month > 12 || day <= 0 || day > getDay(year, month))
//		{
//			//日期无效,设为默认值
//			_year = 1; _month = 1; _day = 1;
//			cout << "日期无效，设为默认值 1-1-1 " << endl;
//		}
//		_year = year; _month = month; _day = day;
//		this->display();
//	}
//	int getDay(int year, int month);
//	int getDays(int year);
//	void display();
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//static int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//int Date::getDay(int year, int month)
//{
//	int day = days[month];
//	if (month == 2 && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)))
//	{
//		day += 1;
//	}
//	return day;
//}
//int Date::getDays(int year)
//{
//	int num = 0;
//	for (int i = 1; i <= 13; i++)
//	{
//		num += days[i];
//	}
//	
//	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
//	{
//		num += 1;
//	}
//	return num;
//}
//void Date::display()
//{
//	cout << _year << '-';
//	if (_month < 10)
//		cout << 0 << _month;
//	else
//		cout << _month;
//	if (_day < 10)
//		cout << '-' << 0 << _day << endl;
//	else
//		cout << '-' << _day << endl;
//
//}
//void test()
//{
//	int i,j;
//	cin >> i >>j;
//	int y_i = i / 10000, m_i = (i % 10000) / 100, d_i = i % 100;
//	int y_j = j / 10000, m_j = (j % 10000) / 100, d_j = j % 100;
//
//	Date d1(y_i, m_i, d_i);
//	Date d2(y_j, m_j, d_j);
//
//	int day_i = 0; int day_j = 0;
//	int value = 0;;
//	if (i > j)
//	{
//		for (int n = 1; n <= (y_i - y_j); n++)
//		{
//			day_i += d1.getDays(y_j + n);
//		}
//		for (int n = 1; n <= m_i; n++)
//		{
//			day_i += d1.getDay(y_i,n-1);
//		}
//		day_i += d_i;
//		for (int n = 1; n <= m_j; n++)
//		{
//			day_j += d2.getDay(y_j,n-1);
//		}
//		day_j += d_j;
//		value = day_i - day_j + 1;
//	}
//	else if(i < j)
//	{
//		for (int n = 1; n <= (y_j - y_i); n++)
//		{
//			day_j += d1.getDays(y_i + n);
//		}
//		for (int n = 1; n <= m_j; n++)
//		{
//			day_j += d1.getDay(y_j, n-1);
//		}
//		day_j += d_j;
//		for (int n = 1; n <= m_i; n++)
//		{
//			day_i += d2.getDay(y_i, n-1);
//		}
//		day_i += d_i;
//		value = day_j - day_i + 1;
//	}
//	else if (i == j)
//	{
//		/*for (int n = 1; n <= m_j; n++)
//		{
//			day_j += d1.getDay(y_j, n);
//		}
//		day_j += d_j;
//		for (int n = 1; n <= m_i; n++)
//		{
//			day_i += d2.getDay(y_i, n);
//		}
//		day_i += d_i;
//		value = day_j - day_i + 1;
//		value = 0;
//	}
//	cout << value << endl;
//}
//
//int main()
//{
//	test();
//	
//	system("pause");
//	return 0;
//}
*/
/*
//方法二
//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		//判断日期是否有效
//		if (year <= 0 || month <= 0 || month > 12 || day <= 0 || day > getDay(year, month))
//		{
//			//日期无效,设为默认值
//			_year = 1; _month = 1; _day = 1;
//			cout << "日期无效，设为默认值 1-1-1 " << endl;
//		}
//		_year = year; _month = month; _day = day;
//		this->display();
//	}
//	Date& operator+=(int day)
//	{
//		_day += day;
//		while (_day > getDay(_year, _month))
//		{
//			_day -= getDay(_year, _month);
//			++_month;
//			if (_month == 13)
//			{
//				++_year;
//				_month = 1;
//			}
//		}
//		while (_day <= 0)
//		{
//			_day += getDay(_year, --_month);
//			if (_month == 0)
//			{
//				--_year;
//				_month = 13;
//			}
//		}
//		return *this;
//	}
//	bool operator==(const Date& d)
//	{
//		if (this->_year == d._year && this->_month == d._month && this->_day == d._day)
//			return true;
//		else
//			return false;
//	}
//	int getDay(int year, int month);
//	int getDays(int year);
//	void display();
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//static int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//int Date::getDay(int year, int month)
//{
//	int day = days[month];
//	if (month == 2 && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)))
//	{
//		day += 1;
//	}
//	return day;
//}
//int Date::getDays(int year)
//{
//	int num = 0;
//	for (int i = 1; i <= 13; i++)
//	{
//		num += days[i];
//	}
//
//	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
//	{
//		num += 1;
//	}
//	return num;
//}
//void Date::display()
//{
//	cout << _year << '-';
//	if (_month < 10)
//		cout << 0 << _month;
//	else
//		cout << _month;
//	if (_day < 10)
//		cout << '-' << 0 << _day << endl;
//	else
//		cout << '-' << _day << endl;
//
//}
//int value(int n_max, int n_min)
//{
//	int y_max = n_max / 10000, m_max = (n_max % 10000) / 100, d_max = n_max % 100;
//	int y_min = n_min / 10000, m_min = (n_min % 10000) / 100, d_min = n_min % 100;
//	cout << y_max << ' ' << m_max << ' ' << d_max;
//	Date d1(y_max, m_max, d_max);
//	Date d2(y_min, m_min, d_min);
//	int ad = 0;
//	while (!(d1.operator==(d2)))
//	{
//		ad++;
//		d2.operator+=(1);
//	}
//	return (ad + 1);
//}
//void test()
//{
//	int i, j;
//	cin >> i >> j;
//	int max = i, min = j;
//	if (max < min)
//	{
//		int t = max;
//		max = min;
//		min = t;
//	}
//	cout << max << ' ' << min << endl;
//	cout<<"ad = "<< value(max, min);
//	//cout << value(max, min) << endl;
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}*/

/*根据输入的日期，计算是这一年的第几天。。
测试用例有多组，注意循环输入
输入描述:
输入多行，每行空格分割，分别是年，月，日
输出描述:
成功:返回outDay输出计算后的第几天;
失败:返回-1*/
/* //方法一
#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		//判断日期是否有效
		if (year <= 0 || month <= 0 || month > 12 || day <= 0 || day > getDay(year, month))
		{
			//日期无效,设为默认值
			_year = 1; _month = 1; _day = 1;
			cout << "日期无效，设为默认值 1-1-1 " << endl;
		}
		_year = year; _month = month; _day = day;


	}
	Date& operator+=(int day)
	{
		_day += day;
		while (_day > getDay(_year, _month))
		{
			_day -= getDay(_year, _month);
			++_month;
			if (_month == 13)
			{
				++_year;
				_month = 1;
			}
		}
		while (_day <= 0)
		{
			_day += getDay(_year, --_month);
			if (_month == 0)
			{
				--_year;
				_month = 13;
			}
		}
		return *this;
	}
	bool operator==(const Date& d)
	{
		if (this->_year == d._year && this->_month == d._month && this->_day == d._day)
			return true;
		else
			return false;
	}
	int getDay(int year, int month);
	int getDays(int year);
private:
	int _year;
	int _month;
	int _day;
};
static int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int Date::getDay(int year, int month)
{
	int day = days[month];
	if (month == 2 && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)))
	{
		day += 1;
	}
	return day;
}
int Date::getDays(int year)
{
	int num = 0;
	for (int i = 1; i <= 13; i++)
	{
		num += days[i];
	}


	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
	{
		num += 1;
	}
	return num;
}
void test()
{
	int year,month,day;
	cin >> year >> month >> day;
	Date d1(year, month, day);
	Date d2(year, 1, 1);
	int ad = 0;
	while (!(d1.operator==(d2)))
	{
		ad++;
		d2.operator+=(1);
	}
	cout << ad + 1 << endl;

}
int main()
{
	test();
	system("pause");
	return 0;
}*/
//方法二
//#include<iostream>
//using namespace std;
//static int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//int getDay(int year, int month)
//{
//	int day = days[month];
//	if (month == 2 && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)))
//	{
//		day += 1;
//	}
//	return day;
//}
//int getDays(int year,int month)
//{
//	int num = 0;
//	for (int i = 1; i < month; i++)
//	{
//		num += days[i];
//		if (i == 2 && ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)))
//		{
//			num += 1;
//		}
//	}
//	
//	return num;
//}
//void test()
//{
//	int year, month, day;
//	cin >> year >> month >> day;
//	int value = 0;
//	//判断日期是否有效
//	if (year <= 0 || month <= 0 || month > 12 || day <= 0 || day > getDay(year, month))
//	{
//		//日期无效,设为默认值
//		cout << -1 << endl;
//	}
//	else
//	{
//		value += getDays(year, month);
//		value += day;
//		cout << value << endl;
//	}
//	
//}
//
//int main()
//{
//	test();
//	system("pause");
//	return 0;;
//}

//#include<iostream>
//using namespace std;
//
//int sum(int n)
//{
//	//if (n == 1) return 1;
//	//return  n + sum(n - 1);
//	int m = n;
//	if (n > 0)
//	{
//		return m + sum(n - 1);
//	}
//}
//void test()
//{
//	int n;
//	cin >> n;
//	cout<< sum(n) << endl;
//}
//
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}