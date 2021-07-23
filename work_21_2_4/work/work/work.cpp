#include<iostream>
using namespace std;

class Date
{
public:
	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month)
	{
		int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		if ((month == 2) && (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
		{
			day += 1;
		}
		return day;
	}

	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (_year < 0 || _month < 0 || _day < 0)
		{
			_year = 1900; _month = 1; _day = 1;
		}
		_year = year; _month = month; _day = day;
	}

	// �������캯��
	// d2(d1)
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	// ��ֵ���������
	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
			return *this;
		}
		else
			cout << "�Լ���ֵ�Լ���" << endl;
	}

	// ��������
	~Date()
	{
		//cout << "����" << endl;
		//�ظ�Ĭ��
		_year = 1900; _month = 1; _day = 1;
	}

	// ����+=����
	Date& operator+=(int day)
	{
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month += 1;
			if (_month == 12)
			{
				_year++;
				_month = 1;
			}
		}
		while (_day <= 0)
		{
			_month--;
			if (_month == 0)
			{
				_year--;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}

	// ����+����
	Date operator+(int day)
	{
		Date copy(*this);
		copy += day;
		return copy;
	}

	// ����-����
	Date operator-(int day)
	{
		Date copy(*this);
		copy -= day;
		return copy;
	}

	// ����-=����
	Date& operator-=(int day)
	{
		_day -= day;
		while (_day <= 0)
		{
			--_month;

			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		//�ж��Ƿ����
		while (_day > GetMonthDay(_year, _month))
		{
			//��ȥ���µ�����
			_day -= GetMonthDay(_year, _month);
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

	// ǰ��++
	Date& operator++()
	{
		return *this += 1;
	}

	// ����++
	Date operator++(int)
	{
		Date copy(*this);
		*this += 1;
		return copy;
	}

	// ����--
	Date operator--(int)
	{
		Date copy(*this);
		*this -= 1;
		return copy;
	}

	// ǰ��--
	Date& operator--()
	{
		return *this -= 1;
	}

	// >���������
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

	// ==���������
	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	// >=���������
	inline bool operator >= (const Date& d)
	{
		return (*this > d) || (*this == d);
	}

	// <���������
	bool operator < (const Date& d)
	{
		return !((*this > d) || (*this == d));
	}

	// <=���������
	bool operator <= (const Date& d)
	{
		return !(*this > d);
	}

	// !=���������
	bool operator != (const Date& d)
	{
		return !(*this == d);
	}

	// ����-���� ��������
	int operator-(const Date& d)
	{
		Date max = *this;
		Date min = d;
		int flag = 1;
		int day = 0;
		if (max < min)
		{
			flag = -1;
			max = d;
			min = *this;
		}
		while (min < max)
		{
			++day;
			++min;
		}
		return flag*day;
	}

	void display()
	{
		cout << _year << '-' << _month << '-' << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

void test()
{
	Date d1(2021, 2, 5);
	d1.display();
	d1 += 24;
	d1.display();
	d1 += -36;
	d1.display();

	Date d2(2021, 3, 5);
	Date d3 = d2 + 54;
	d2.display();
	d3.display();
	if (d3 > d2)
		cout << "d3 > d2 ? yes" << endl;
	else
		cout << "d3 > d2 ? no" << endl;
	int day = d3 - d2;
	cout << day << endl;

}

int main()
{
	test();

	system("pause");
	return 0;
}