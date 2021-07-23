#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		//�ж������Ƿ���Ч
		if (year <= 0 || month <= 0 || month > 12 || day <= 0 || day > getDay(year, month))
		{
			//������Ч,��ΪĬ��ֵ
			_year = 1; _month = 1; _day = 1;
			cout << "������Ч����ΪĬ��ֵ 1-1-1 " << endl;
		}
		_year = year; _month = month; _day = day;
	}
	int getDay(int year, int month);
	void display();

	//��������
	//������� += �Ҳ�����:������������ݷ����仯��������ӵ�ֵ���з���
	Date& operator+=(int day)
	{
		_day += day;
		/*if (day < 0)
		return *this -= day;*/
		//�ж��Ƿ����
		while (_day > getDay(_year, _month))
		{
			//��ȥ���µ�����
			_day -= getDay(_year, _month);
			//�·ݽ�λ
			++_month;
			//�ж��·��Ƿ����
			if (_month == 13)
			{
				//��ݽ�λ
				++_year;
				_month = 1;
			}
		}
		//�ж��Ƿ������,�˴��� -= ��������غ����еĹ���һ�£���д����Щ��ͬ
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

	//�ӷ���������Ӻ�Ľ�������������ܸı�,���ܷ������ã����Ƿ���һ��ֵ 
	Date operator+(int day)
	{
		Date copy(*this);//�Ե�ǰ������п���
		copy += day;//�������� += ���غ���
		return copy;
	}

	//++Date
	Date& operator++()
	{
		return *this += 1;

	}

	//Date++ ����
	Date operator++(int)
	{
		Date copy(*this);
		*this += 1;
		return copy;
	}

	//������� -= �Ҳ�����
	Date& operator-=(int day)
	{
		_day -= day;
		//�ж��Ƿ������
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
		//�ж��Ƿ����
		while (_day > getDay(_year, _month))
		{
			//��ȥ���µ�����
			_day -= getDay(_year, _month);
			//�·ݽ�λ
			++_month;
			//�ж��·��Ƿ����
			if (_month == 13)
			{
				//��ݽ�λ
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
		//����һ��
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
		//��������
		return !(*this >= d);
	}

	//>=
	bool operator>=(const Date& d)
	{
		//��1��
	//	return !(*this < d);
		//��2��
		return (*this > d) || (*this == d);
	}

	//<=
	bool operator<=(const Date& d)
	{
		//��1��
		//return !(*this > d);
		//��2��
		return (*this < d) || (*this == d);
	}

	//���������Date - Date
	int operator-(const Date& d)
	{
		//����Ƚ�С�����ھ������ٴ��Լӵ����㣬���ԺͱȽϴ��������ͬ
		//�ԼӵĴ���Ϊ��������
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
	//d4 = ++d1;//ǰ��++
	//d4.display();
	//
	//Date d5;
	////d5 = d1++1;//����д�����ں��û��������,дΪ������ʽ�ɱ������
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
//	//���� = ,��1��
//	Date operator=(const Date &d)//��d��ֵ��Ϊ��ֵ
//	{
//		cout << "��ֵ" << endl;
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//			return *this;
//		}
//		else
//			cout << "�Լ���ֵ" << endl;
//		
//	}
//	//��2��
//	//void operator=(const Date &d)//��d��ֵ��Ϊ��ֵ
//	//{
//	//	//�ж϶����Ƿ�Ϊͬһ���󣬲��ܸ��������жϣ�ͨ��ָ���ж�
//	//	if (this == &d)
//	//	{
//	//		cout << "��ͬһ����" << endl;
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
//	//if (d1 == d2)//�����ʽ
//	//if (d1.operator==(d2))//������ʽ
//	//{
//	//	cout << "���һ��" << endl;
//	//}
//
//	//d1.operator=(d2.operator=(d3));//������ʽ����Ϊ��д��ʽ
//	d1 = d2 = d3;//������ֵֻ���÷���1����û����������غ�������˲������ڿ���
//	
////	d1.display();
//	d1 = d1;//һ�Ը�ֵ���ֽԿ�
//
//	Date d4 = d1;//�˲�Ϊ��ֵ��Ϊ��������
//}

int main()
{
	test();

	system("pause");
	return 0;
}