#include<iostream>
using namespace std;

//class Time
//{
//public:
//	Time(int hour = 1, int minute=1, int second=1)//需加上默认参数值
//		:_hour(hour),
//		_minute(minute),
//		_second(second)
//	{
//
//	}
//	
//	Time& operator=(const Time& t)
//	{
//		cout << "operator=" << endl;
//		this->_hour = t._hour;
//		this->_minute = t._minute;
//		this->_second = t._second;
//		return *this;
//	}
//
//	void show()
//	{
//		cout << _hour << ':' << _minute << ':' << _second << endl;
//	}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//
//class Date
//{
//public:
//	//Date(int year, int month, int day)
//	//	//const ，引用必须在定义时进行初始化
//	//	:_year(year),
//	//	_month(month),
//	//	_day(day),
//	//	_hour(12),
//	//	_time(9,42,26)
//	//{
//	//	cout << _year << '-' << _month << '-' << _day << '-' << _hour << endl;
//	//	_time.show();
//	//}
//	Date()
//		:_time(15,3,55)
//	{
//		/*Time tmp(15, 03, 56);
//		_time = tmp;*/
//		_time.show();
//	}
//
//private: 
//	/*int& _year;
//	int& _month;
//	int& _day;
//	const int _hour;*/
//	Time _time;
//};
//
////Date::Date(int year, int month, int day)
////	:_year(year), _month(month), _day(day)
////{
////	cout << "参数的初始化" << endl;
////}
//
//void test()
//{
//	Date d1;
//	//Date d1(2021,2,11);
//	//cout << d1._year << ':' << d1._month << ':' << d1._day << endl;
//}

//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//void test()
//{
//	A aa(1);
//	aa.Print();
//}

//class A
//{
//public:
//	A()
//	{
//		++_count; show();
//		cout << "默认" << endl;
//	}
//	A(const A& a)//拷贝构造
//	{
//		++_count;
//		show();
//		cout << "youcan" << endl;
//	}
//	void show()
//	{
//		cout << _count << endl;
//	}
//	void add()
//	{
//		//非静态可以调用静态，因为非静态中具有隐藏的this指针
//		cout << "1+2=3" << endl;
//		cout << "add - getCount = " << getCount() << endl;
//	}
//	static int getCount()
//	{
//		//add();//无法调用非静态函数，因为静态函数中缺少隐藏的this指针
//		return _count;
//	}
//private:
//	//静态成员是所有对象共享
//	//static成员变量，必须在类外进行声明
//	static int _count;
//};
//
//int A::_count = 0;
//
//A funA(A a)
//{
//	return a;//两个对象创建
//}
//
//void test()
//{
//	A a1;//1
//	A a2;//2
//	A a3 = funA(a1);//调用了两次,拷贝构造
//	cout << "getCount = " << a3.getCount() << endl;
//	cout << "A::count = " << A::getCount() << endl;
//	a3.add();
//	//a3.show();
//}

//友元
//class Date
//{
//public:
//	Date(int year, int month, int day)
//		//const ，引用必须在定义时进行初始化
//		:_year(year),
//		_month(month),
//		_day(day)
//	{
//		//cout << _year << '-' << _month << '-' << _day  << endl;
//	}
//	//重载 << 
//	//以下两种重载方式皆可实现目标功能，皆是友元函数
//	//友元函数可以调用类中的私有变量，但不属于类中函数，且友元函数须在对应类中进行声明，可以在类外也可以在类内进行定义
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	/*friend ostream& operator<<(ostream& _cout,const Date& d)
//	{
//		_cout << d._year << '-' << d._month << '-' << d._day << endl;
//		return _cout;
//	}*/
//
//	//重载 >>
//	friend istream& operator>>(istream& _cin, Date& d);
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//};
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << '-' << d._month << '-' << d._day << endl;
//	return _cout;
//}
//istream& operator>>(istream& _cin, Date& d)
//{
//	_cin >> d._year >> d._month >> d._day;
//	return _cin;
//}
//
//void test()
//{
//	//重载 cout<<
//	//Date d1(2021, 3, 11);
//	////operator<<(cout,d1);//完整形式
//	////cout << d1;
//	////cout << d1 << d1 << endl;
//	//cout.operator<<(endl);//完整形式
//	//cout << endl;
//
//	//重载输入 cin>>
//	Date d2(2021, 3, 20);
//	cout << d2;
//	cin >> d2;
//	cout << d2;
//}
class Time;
class Date
{
	friend class Time;
public:
	Date(int y=1,int m=1)
	{
		_y = y;
		_m = m;
	}
	static int a;
private	:
	int _y;
	int _m;
};
int Date::a = 2;
class Time
{
public:
	Time(int t = 1)
	{
		_t = t;
		
	}
	class A
	{public:
		int wa = 5555;
	};
	
	void sety(int t)
	{
		d._y = t;
		d._m = d.a;
	}
	int _t;
	void dis()
	{
		cout << "d._y = " << d._y << "d._m = " << d._m << endl;
	}
private:
	  
	Date d;
	
};
void test()
{
	Time ttt(56);
	ttt.sety(ttt._t);
	ttt.dis();
	Time::A b;
	cout << b.wa << endl; 
}


int main()
{
	test();
	system("pause");
	return 0;
}
