#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
#include<assert.h>

/* ʵ�� string ��*/

/*����д��*/
//class String
//{
//public:
//	/*String()
//		:_data(new char[1]) 
//	{
//		_data[0] = '\0';
//	}*/
//
//	//ȫȱʡ�Ĺ��캯��
//	String(const char* str = "")
//		:_data(new char[strlen(str) + 1])// +1 ��Ϊ '\0'��λ��
//	{
//		cout << "String" << endl;
//		strcpy(_data, str);
//	}
//
//	//ǳ����
//	/*String(const String& str)
//		:_data(str._data)
//	{
//
//	}*/
//
//	//���
//	String(const String& str)
//		:_data(new char[strlen(str._data) + 1])
//	{
//		cout << "���" << endl;
//		//���,�ؿ��ռ䱣������
//		strcpy(_data, str._data);
//	}
//
//	//��ĳ�Ա��������� const������������������������
//	//������ݳ�Ա��׼ȷ��˵�ǷǾ�̬���ݳ�Ա�����κθı䡣
//	const char *c_str() const
//	{
//		return _data;
//	}
//
//	String& operator=(const String& str)
//	{
//		cout << "operator=" << endl;
//		if (this != &str)//��ʱ�� & �������ã����ǵ�ַ����ָ�룬�� this ��Ӧ
//		{
//			//�ͷ�ԭ�еĿռ䣬Ȼ������һ��str�Ŀռ�
//			delete[] _data;
//			_data = new char[strlen(str._data) + 1];
//			strcpy(_data, str._data);
//		}
//		return *this;
//	}
//
//	~String()
//	{
//		cout << "~String" << endl;
//		if (_data)
//		{
//			delete[] _data;
//			_data = nullptr;
//		}
//	}
//private:
//	char *_data;
//};
//
//void test()
//{
//	String str("123");
//	String str2(str);//���
//	String str3 = str2;//���
//	String str4;
//	str4.operator=("hjsfhjk");//��ֵ��������أ������Ǵ��� hjsfhjk ����Ȼ���ٸ�ֵ��str4
//	cout << str.c_str() << endl;
//	cout << str2.c_str() << endl;
//	cout << str3.c_str() << endl;
//	cout << str4.c_str() << endl;
//}
//
////void test()
////{
////	String str("123");
////	//ǳ������ֻ����String�����е�����
////	//String copy(str);//ǳ����
////	String str2("456");
////	str2 = str;//ǳ�������ڴ�й©
////}
//
////void test()
////{
////	string str;
////	cout << str.c_str() << endl;
////	String str1("123");
////	cout << str1.c_str() << endl;
////}

/*�ִ�д��*/
//class String
//{
//public:
//
//	//ȫȱʡ�Ĺ��캯��
//	String(const char* str = "")
//		:_data(new char[strlen(str) + 1])// +1 ��Ϊ '\0'��λ��
//	{
//		cout << "String" << endl;
//		strcpy(_data, str);
//	}
//
//	//ǳ����
//	/*String(const String& str)
//	:_data(str._data)
//	{
//
//	}*/
//
//	//���  --  ����������ִ�д��
//	String(const String& str)
//		:_data(nullptr)//ʹ_data��Ϊ��ָ��
//	{
//		cout << "swap - ����" << endl;
//		String tmp(str._data);//tmp Ϊ��ʱ���󣬵�������Զ��ͷ� -- ���ù��캯�����߼�
//		swap(tmp._data, _data);//�൱��thisָ����tmpָ�����˱任 -- ���ʵ�ʵĿ���
//	}
//
//	//��ĳ�Ա��������� const������������������������
//	//������ݳ�Ա��׼ȷ��˵�ǷǾ�̬���ݳ�Ա�����κθı䡣
//	const char *c_str() const 
//	{
//		return _data;
//	}
//
//	//String& operator=(const String& str)
//	//{
//	//	cout << "operator=" << endl;
//	//	if (this != &str)//��ʱ�� & �������ã����ǵ�ַ����ָ�룬�� this ��Ӧ
//	//	{
//	//		//�ͷ�ԭ�еĿռ䣬Ȼ������һ��str�Ŀռ�
//	//		delete[] _data;
//	//		String tmp(str._data);
//	//		swap(tmp._data, _data);
//	//	}
//	//	return *this;
//	//}
//	/*��ֵ��������ִ�д��
//	�ͷ�ԭ�пռ䣬�����µĿռ䣬��������*/
//	String& operator=(const String& str)
//	{
//		cout << "operator=" << endl;
//		//swap(str._data, _data);//�����ύ�� str._data �� this->_data ��ֵ
//		String tmp(str._data);
//		swap(tmp._data, _data);//����ǽ� str._data ��ֵ�� this->_data
//		return *this;
//	}
//
//	~String()
//	{
//		cout << "~String" << endl;
//		if (_data)
//		{
//			delete[] _data;
//			_data = nullptr;
//		}
//	}
//private:
//	char *_data;
//};
//
//void test()
//{
//	String str("123");
//	String str2(str);//���
//	String str3 = str2;//���
//	String str4;
//	str4.operator=(str);//��ֵ��������أ������Ǵ��� hjsfhjk ����Ȼ���ٸ�ֵ��str4
//	cout << str.c_str() << endl;
//	cout << str2.c_str() << endl;
//	cout << str3.c_str() << endl;
//	cout << str4.c_str() << endl;
//}

/*дʱ����*/
class String
{
public:
	//String�ĵ�����
	//������������������ָ��
	//�����ã�*iterator --> ��ȡ��
	//�ƶ���++iterator,--iterator,�ƶ�������Ԫ�ص�λ��
	//String������ʵ�֣��ַ�ָ��
	typedef char *iterator;//�ɶ���д
	typedef const char *const_iterator;//�ɶ�����д
	iterator begin()
	{
		cout << "begin" << endl;
		//��һ��Ԫ�ص�λ��
		return _data;
	}
	iterator end()
	{
		//���һ��Ԫ�ص���һ��λ��
		return _data + _size;
	}

	const_iterator begin() const
	{
		cout << "const_begin" << endl;
		//��һ��Ԫ�ص�λ��
		return _data;
	}
	const_iterator end() const
	{
		//���һ��Ԫ�ص���һ��λ��
		return _data + _size;
	}

	String(const char *str = "")//���캯��ֻ�贫���ַ����ݣ������������ô���
	{
		_size = strlen(str);
		_data = new char[_size + 1];
		_capacity = _size;
		strcpy(_data, str);//strcpy(a,b)  -- ��b��ֵ����a
	}
		
	String(const String& str)
		:_data(nullptr),
		_size(0),
		_capacity(0)
	{
		cout << "string" << endl;
		String tmp(str._data);
		Swap(tmp);
	}

	void Swap(String& str)
	{
		swap(_data, str._data);
		swap(_size, str._size);
		swap(_capacity, str._capacity);
	}

	String& operator=(String str)
	{
		cout << "operator=" << endl;
		Swap(str);
		return *this;
	}

	const char *c_str() const
	{
		return _data;
	}

	const size_t ca_str() const
	{
		return _capacity;
	}

	const size_t sz_str() const
	{
		return _size;
	}

	~String()
	{
		cout << "~String" << endl;
		if (_data)
		{
			delete[] _data;
			_data = nullptr;
			_size = _capacity = 0;
		}
	}

	char& operator[](size_t pos)
	{
		cout << "operator[]" << endl;
		assert(pos < _size);
		return _data[pos];
	} 

	const char& operator[](size_t pos) const
	{
		cout << "const operator[]" << endl;
		assert(pos < _size);
		return _data[pos];
	}

	size_t size() const
	{
		return _size;
	}

	//β���ַ�
	void push_back(const char &ch)
	{
		//���ռ�
		if (_size == _capacity)
		{
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			//���� 2��
			reserve(newC);
		}
		_data[_size++] = ch;

		//��ӽ����ַ� '\0'
		_data[_size] = '\0';
	}

	void reserve(size_t n)
	{
		if (n > _capacity)
		{
			//����ռ�
			char *tmp = new char[n + 1];
			//����
			strcpy(tmp, _data);//��_data��ֵ����tmp
			//�ͷ�ԭ�пռ�
			delete[] _data;
			_data = tmp;
			_capacity = n;
		}
		//cout << _capacity << endl;
	}

	void resize(size_t n, const char& ch = '\0')
	{
		//n > _capacity : ��Ҫ����
		if (n > _capacity)
		{
			reserve(n);
		}
		// _size < n <= _capacity
		//����ַ� ch
		//void * memset��void * ptr��int value��size_t num��; -- ��ptrָ����ڴ���ǰnum���ֽ�����Ϊָ��ֵ
		if (n > _size)
			memset(_data + _size, ch, (n - _size)*sizeof(char));

		//ֱ���޸�size
		_size = n;

		_data[_size] = '\0';
	}
	
private:
	char *_data;
	//size:��Ч�ַ��ĸ���
	size_t _size;
	//capacity:���Ա���������Ч�ַ����� , '\0'����
	size_t _capacity;
};

void printStringFor(const String &str)
{
	//��Χfor:��Ҫ�õ�begin(),end(),�˴�Ϊconst�������Ի����const begin
	for (const char& ch : str)
	{
		cout << ch << " ";
	}cout << endl;
}

void printStringIt(const String& str)
{
	//String::iterator it = str.begin();//�ᱨ����Ϊ���Ͳ�һ��
	String::const_iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it << " ";
		it++;
	}cout << endl;
}

void test()
{
	String str; cout << str.c_str() << "-" << str.sz_str() << "-"<< str.ca_str() << endl;
	str.push_back('1'); cout << str.c_str() << "-" << str.sz_str() << "-" << str.ca_str() << endl;
	str.push_back('2'); cout << str.c_str() << "-" << str.sz_str() << "-" << str.ca_str() << endl;
	str.push_back('3'); cout << str.c_str() << "-" << str.sz_str() << "-" << str.ca_str() << endl;

	str.resize(3); cout << str.c_str() << "-" << str.sz_str() << "-" << str.ca_str() << endl;
	str.resize(10,'a'); cout << str.c_str() << "-" << str.sz_str() << "-" << str.ca_str() << endl;
	str.resize(20,'b'); cout << str.c_str() << "-" << str.sz_str() << "-" << str.ca_str() << endl;
}

//void test()
//{
//	String str = "1234567890";
//	printStringFor(str);
//	printStringIt(str);
//}

//void test()
//{
//	/*String str("123");
//	String str2(str);
//	String str3 = "456";
//	String str4;
//	str4 = str;
//	cout << str.c_str() << endl;
//	cout << str2.c_str() << endl;
//	cout << str3.c_str() << endl;
//	cout << str4.c_str() << endl;*/
//
//	/* ���ֱ�����ʽ ���Ҷ����޸�����,���˾�̬��*/
//
//	/*��ʽһ��forѭ��*/
//	String str("123456789");
//	for (size_t i = 0; i < str.size(); ++i)
//	{
//		cout << str[i] << " ";// �ȼ��� str.operator[](i)
//	}
//	cout << endl;
//	str[4] = 'a';
//	cout << str.c_str() << endl;
//
//	/*��ʽ������Χfor*/
//	for (const auto& ch : str)
//	{
//		cout << ch << " ";
//	}cout << endl;
//
//	/*��ʽ��������������*/
//	String::iterator it = str.begin();
//	while (it != str.end())
//	{
//		cout << *it << " ";
//		it++;
//		*it = 'b';
//	}cout << endl;
//	
//	//��̬������������ֻ�ɶ�����д
//	String::const_iterator it1 = str.begin();
//	while (it1 != str.end())
//	{
//		cout << *it1 << " ";
//		it1++;
//		//*it1 = 'c';//�ᱨ��
//	}cout << endl;
//
//}

int main()
{
	test();
	
	system("pause");
	return 0;
}