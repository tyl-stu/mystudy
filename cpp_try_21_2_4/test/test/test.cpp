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
	int getDay(int year, int month);
	void display();

	//日期运算
	//左操作数 += 右操作数:左操作数的内容发生变化，并将相加的值进行返回
	Date& operator+=(int day)
	{
		_day += day;
		/*if (day < 0)
		return *this -= day;*/
		//判断是否溢出
		while (_day > getDay(_year, _month))
		{
			//减去当月的天数
			_day -= getDay(_year, _month);
			//月份进位
			++_month;
			//判断月份是否溢出
			if (_month == 13)
			{
				//年份进位
				++_year;
				_month = 1;
			}
		}
		//判断是否反向溢出,此处和 -= 运算符重载函数中的功能一致，但写法有些许不同
		while (_day <= 0)
		{
			_day += getDay(_year, --_month);

			//_day = getDay(_year, _month) - _day;
			if (_month == 0)
			{
				--_year;
				_month = 13;
			}
		}
		
		return *this;
	} 

	//加法：返回相加后的结果，操作数不能改变,不能返回引用，而是返回一个值 
	Date operator+(int day)
	{
		Date copy(*this);//对当前对象进行拷贝
		copy += day;//调用上述 += 重载函数
		return copy;
	}

	//++Date
	Date& operator++()
	{
		return *this += 1;

	}

	//Date++ 后置
	Date operator++(int)
	{
		Date copy(*this);
		*this += 1;
		return copy;
	}

	//左操作数 -= 右操作数
	Date& operator-=(int day)
	{
		_day -= day;
		//判断是否反向溢出
		while (_day <= 0)
		{
			--_month;
			
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
			_day += getDay(_year, _month);
		}
		//判断是否溢出
		while (_day > getDay(_year, _month))
		{
			//减去当月的天数
			_day -= getDay(_year, _month);
			//月份进位
			++_month;
			//判断月份是否溢出
			if (_month == 13)
			{
				//年份进位
				++_year;
				_month = 1;
			}
		}
		return *this;
	}

	//date - int
	Date operator-(int day)
	{
		Date copy(*this);
		copy -= day;
		return copy;
	}

	//--Date
	Date& operator--()
	{
		return *this-=1;
	}

	//Date--
	Date operator--(int)
	{
		Date copy(*this);
		*this -= 1;
		return copy;
	}

	//==
	bool operator==(const Date& d) 
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	//!=
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	//>
	bool operator>(const Date& d)
	{
		if (_year > d._year)
			return true;
		else if (_year == d._year)
		{
			if (_month > d._month)
				return true;
			else if (_month == d._month)
			{
				if (_day > d._day)
					return true;
			}
		}
		return false;
	}

	//<
	bool operator<(const Date& d)
	{
		//方法一：
		/*if (_year < d._year)
			return true;
		else if (_year == d._year)
		{
			if (_month < d._month)
				return true;
			else if (_month == d._month)
			{
				if (_day < d._day)
					return true;
			}
		}
		return false;	*/
		//方法二：
		return !(*this >= d);
	}

	//>=
	bool operator>=(const Date& d)
	{
		//法1：
	//	return !(*this < d);
		//法2：
		return (*this > d) || (*this == d);
	}

	//<=
	bool operator<=(const Date& d)
	{
		//法1：
		//return !(*this > d);
		//法2：
		return (*this < d) || (*this == d);
	}

	//日期相减：Date - Date
	int operator-(const Date& d)
	{
		//计算比较小的日期经过多少次自加的运算，可以和比较大的日期相同
		//自加的次数为相差的天数
		Date max = *this;
		Date min = d;
		int day = 0;
		int flag = 1;
		if (max < min)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		while (min < max)
		{
			++day;
			++min;
		}
		return day * flag;
	}

private:
	int _year;
	int _month;
	int _day;
};

int Date::getDay(int year, int month)
{
	static int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = days[month];
	if (month == 2 && ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
	{
		day += 1;
	}
	return day;
}
void Date::display()
{
	cout << _year << '-' << _month << '-' << _day << endl;
}



void test()
{
	int a = 1;
	a += (-5);
	a = -a;
	cout << a << endl;

	Date d1(2020, 2, 5);
	Date d2 = d1 + 532;
	int day = d1 - d2;
	cout << day << endl;

	/*Date d1(2021,2,25);
	d1.display();
	d1 += 4600;
	d1.display();
	d1 -= 4600;
	d1.display();
	d1 -= -4600;
	d1.display();
	d1 += -4600;
	d1.display();*/

	//Date d2(2021,2,3);
	//Date d3 = d2 + 12;
	//d3.display();
	//
	//Date d4;
	//d4 = ++d1;//前置++
	//d4.display();
	//
	//Date d5;
	////d5 = d1++1;//此种写法用于后置会出现问题,写为完整形式可避免错误
	//d5 = d1.operator++(1);
	//
	//d5.display();
}

//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	
//	/*bool operator==(const Date &d)
//	{
//		if (_year == d._year)
//			return 1;
//		else
//			return 0;
//	}*/
//	//重载 = ,法1：
//	Date operator=(const Date &d)//以d的值作为赋值
//	{
//		cout << "赋值" << endl;
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//			return *this;
//		}
//		else
//			cout << "自己赋值" << endl;
//		
//	}
//	//法2：
//	//void operator=(const Date &d)//以d的值作为赋值
//	//{
//	//	//判断对象是否为同一对象，不能根据内容判断，通过指针判断
//	//	if (this == &d)
//	//	{
//	//		cout << "是同一对象" << endl;
//	//	}
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//	//return *this;
//	//}
//
//	void display()
//	{
//		cout << "year = " << _year << endl
//			<< "month = " << _month << endl
//			<< "day = " << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void test()
//{
//	Date d1(21, 1, 1); //d1.display();
//	Date d2(21, 2, 2); //d2.display();
//	Date d3(24, 3, 3);
//	//Date d4; //d4.display();
//	//if (d1 == d2)//简洁形式
//	//if (d1.operator==(d2))//完整形式
//	//{
//	//	cout << "年份一致" << endl;
//	//}
//
//	//d1.operator=(d2.operator=(d3));//完整形式，下为简写形式
//	d1 = d2 = d3;//连续赋值只能用方法1，若没有运算符重载函数，则此操作属于拷贝
//	
////	d1.display();
//	d1 = d1;//一对赋值两种皆可
//
//	Date d4 = d1;//此不为赋值，为拷贝构造
//}

int main()
{
	test();

	system("pause");
	return 0;
}