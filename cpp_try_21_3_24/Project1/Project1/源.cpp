#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
#include<assert.h>

#include<typeinfo>

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
		//cout << "begin" << endl;
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
		//cout << "string" << endl;
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
		//cout << "String" << endl;
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
		//cout << "operator=" << endl;
		Swap(str);
		return *this;
	}

	const char *c_str() const  //���ض������Ч����
	{
		return _data;
	}

	const size_t ca_str() const  //���ض���������Ч�ַ�����
	{
		return _capacity;
	}

	const size_t sz_str() const  //���ض������Ч�ַ�����
	{
		return _size;
	}

	~String()
	{
		//cout << "~String" << endl;
		if (_data)
		{
			delete[] _data;
			_data = nullptr;
			_size = _capacity = 0;
		}
	}

	char& operator[](size_t pos)
	{
		//cout << "operator[]" << endl;
		assert(pos < _size);//assert(exc)����exc������ʱ���ᱨ��
		return _data[pos];
	}

	const char& operator[](size_t pos) const
	{
		//cout << "const operator[]" << endl;
		assert(pos < _size);
		return _data[pos];
	}

	//size_t size() const  //�����溯���ظ�
	//{
	//	return _size;
	//}

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

	//���ٿռ�
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

	//�����ַ�����size
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

	//β�����
	void append(const char* str)
	{
		//�������
		int len = strlen(str);
		if ((_size + len) > _capacity)//Ҫ��ӵ��ַ����ĳ���j
		{
			reserve(_size + len);
		}
		//β�� - �ַ���
	//	memcpy(_data + _size, str, sizeof(char)*len);//o(1)�Ĳ��� -- �Ƚϸ�Ч
		strcpy(_data + _size, str);//�����ݵ�ԭβ�������»���  o(n)�Ĳ���
		//���³�Ա
		_size += len;
		_data[_size] = '\0';//ʹ������ȷ����
	}

	//String operator+=()  �������к���ʵ�ַ�  -- β���Ӧ����
	String& operator+=(const String& str)
	{
		cout << "+= str" << endl;
		append(str._data);
		return *this;
	}
	String& operator+=(const char* str)
	{
		cout << "+= char*" << endl;
		append(str);
		return *this;
	}
	String& operator+=(const char ch)
	{
		//append(&ch); //�÷�����
		push_back(ch);//�÷������
		return *this;
	}

	void insert(size_t pos, const char& ch)
	{
		//���λ����Ч��
		assert(pos <= _size);

		//�������
		if (_size == _capacity)
		{
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		
		//�ƶ�Ԫ�أ�[pos,size]  �Ӻ���ǰ��  no probelm
		size_t end = _size + 1;//���� '\0' ,���ַ����������ַ������Դ˴�����Ҫ���ж�����ַ�������ݽ��н�����������ʹ�������һ���ַ�Ϊ '\0'��
		while (end > pos)//end ���һλΪ pos + 1,���� _data[pos+1]=_data[pos]
		{
			_data[end] = _data[end - 1];
			--end;
		}
		//int end = _size;
		////�����bug����Ϊend����Ϊsize_t,�� 0 ������ͷ��ʱ����Խ��,
		////Ϊ��������⣬���Խ�end���͸�Ϊint,���������б��� pos ����������Ҳ��Ϊint
		//while (end >= pos)
		//{
		//	_data[end + 1] = _data[end];
		//	--end;
		//}

		//����:pos
		_data[pos] = ch;

		//����
		++_size;
	}
	void insert(size_t pos, const char* ptr)
	{
		//���λ����Ч��
		assert(pos <= _size);
		int len = strlen(ptr);
		//�������
		if ((_size + len) >= _capacity)
		{
			reserve(_size + len);
		}

		//�ƶ�Ԫ�أ�[pos,size]  �Ӻ���ǰ��  no probelm
		size_t end = _size + len;//���� '\0' ,���ַ����������ַ������Դ˴�����Ҫ���ж�����ַ�������ݽ��н�����������ʹ�������һ���ַ�Ϊ '\0'��
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!������ĵط�
		while (end > (pos + len - 1))//end���һλ�� pos + len ,����ѭ��������_data[pos + len]=_data[pos]
		{
			_data[end] = _data[end - len];
			--end;
		}

		//����:pos  �˴�����ʹ��strcpy,��Ϊ�ú����Ὣ '\0' Ҳ��������ȥ���Ӷ�������ԭ���� pos ֮�������
		memcpy(_data+pos, ptr, sizeof(char)*len);
		//strcpy(_data +pos,ptr); //�ú������ս������

		//����
		_size += len;
		_data[_size] = '\0';//�������п��ޣ���Ϊ������ѭ������ʵ���˸����Ĺ���
	}

	void erase(size_t pos, size_t len)
	{
		assert(pos <= _size);
		size_t begin = pos;
		if ((_size - begin) < len)//���д���Ա���bug
		{
			_data[begin] = '\0';	
			_size = pos;
		}
		else
		{
			//��ǰ����ƶ�
			while (begin < (pos + len))
			{
				_data[begin] = _data[begin + len];
				++begin;
			}
			
			_size -= len;
			_data[_size] = '\0';
		}
		
	}

	size_t find(const char &ch, size_t pos = 0)//��ȱʡ�Ǵ��������Ҳ��ҵ�λ��Ĭ�ϴ�0��ʼ�����Ըú����Ĳ����б�Ϊsize_t find(const char &ch, size_t pos = 0)
	{
		cout << "find(ch)" << endl;
		for (size_t i = 0; i < _size; i++)
		{
			if (_data[i] == ch)
				return i;
		}
		return npos;
	}
	size_t find(const char* str, size_t pos = 0)//��ȱʡ�Ǵ��������Ҳ��ҵ�λ��Ĭ�ϴ�0��ʼ�����Ըú����Ĳ����б�Ϊsize_t find(const char &ch, size_t pos = 0)
	{
		cout << "find(*str)" << endl;
		//char * strstr(const char *dest,const char *src);
		//strstr()����ֵ��δ�ҵ�������NULL;�ҵ����ص�һ�γ��ֵ�λ�õ��׵�ַ
		int len = strlen(str);
		if ((pos + len) <= _size)
		{
			char *ptr = strstr(_data + pos, str);
			if (ptr)
			{
				return ptr - _data;
			}
			return npos;
		}
		return npos;
	}

	/*����Ϊ���Ա�����������Ϊ���������������������������������*/
	ostream& operator<<(ostream& out) const
	{
		for (const char& ch : *this)//��Χfor ʹ������begin()����������Ҫ�����������const���Ƿ�const
		{
			out << ch;
		}
		cout << endl;
		return out;
	}

private:
	char *_data;
	//size:��Ч�ַ��ĸ���
	size_t _size;
	//capacity:���Ա���������Ч�ַ����� , '\0'����
	size_t _capacity;

	static const size_t npos;
};

const size_t String::npos = -1;

istream& operator>>(istream& in, String& str)
{
	char ch;
	str = "";
	//��Ϊ cin �޷�����ո��س������Ը��� getchar()
	while (ch = getchar())
	{
		if (ch == ' ' || ch == '\n' || ch == '\t')
			break;
		str += ch;
	}
	return in;
}

ostream& operator<<(ostream& out,const String& str)
{
	for (const auto& ch : str)//��Χfor  ���˷�const�ĵ�����
	{
		out << ch;
	}
	cout << endl;
	return out;
}

bool operator>(const String& str1, const String&str2)
{
	int ret = strcmp(str1.c_str(), str2.c_str());
	if (ret > 0)
		return true;
	else
		return false;
}

/* String operator+= ������ʵ�ַ��� */
//String& String::operator+=(const String& str)
//{
//	int len = str._size;
//	//�������
//	if ((_size + len) > _capacity)
//	{
//		reserve(_size + len);
//	}
//	//β�� - String����
//	memcpy(_data + _size, str._data, sizeof(char)*len);
//	_size += len;
//	_data[_size] = '\0';
//	return *this;
//}
//String& String::operator+=(const char* str)
//{
//	int len = strlen(str);
//	if ((_size + len) > _capacity)
//	{
//		reserve(_size + len);
//	}
//	strcpy(_data + _size, str);
//	_size += len;
//	_data[_size] = '\0';
//	return *this;
//}
//String& String::operator+=(const char ch)
//{
//	int len = 1;
//	if ((_size + len) > _capacity)
//	{
//		reserve(_size + len);
//	}
//	//memcpy(_data + _size, &ch, sizeof(char) * len);
//	strcpy(_data + _size, &ch);
//	_size += 1;
//	_data[_size] = '\0';
//	return *this;
//}

/* String operator+  ��ʵ�� ��������Ķ������ݲ��ܱ䣩*/
String operator+(const String& str1,const String& str2)  //�ǳ�Ա����
{
	cout << "+ str" << endl;
	/*String tmp;
	tmp.append(str1.c_str());
	tmp.append(str2.c_str());
	return tmp;*/
	String copy(str1);
	copy += str2;
	return copy;
}
String operator+(const String& str1, const char* str2)  //�ǳ�Ա����
{
	cout << "+ char*" << endl;
	/*String tmp;
	tmp.append(str1.c_str());
	tmp.append(str2);
	return tmp;*/
	String tmp;
	tmp += str1;
	tmp += str2;
	return tmp;
}
String operator+(const char ch ,const String& str1)  //�ǳ�Ա����
{
	/*String tmp;
	tmp.push_back(ch);
	tmp.append(str1.c_str());
	return tmp;*/
	String copy(str1);
	copy += ch;
	return copy;
}

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

	String str1 = "1234";
	String str2 = "9876";
	
	/*ostream() ����Ϊ ���Ա����*/
	//tmp << cout;
	//str2 << (str1 << cout);//��������������� 1234 9876

	/*ostream() ����Ϊ���⺯��  ��˻��������const__begin()������,��Ϊ���غ����������Ϊconst����*/
	cout << str1 << str2;

	cin >> str1;
	cout << str1 << endl;

	cout << (str1 > str2);
}

//void test()
//{
//
//	String str1 = "1234";
//	String str2 = "9876";
//	String tmp;
//	tmp = str1 + str2;
//	cout << tmp.c_str() << "  " << tmp.sz_str() << "  " << tmp.ca_str() << endl;
//
//	tmp = tmp + "xx"; //������ String operator+(const String& str1, const char* str2)
//	//tmp += "xx";  //������ String& operator+=(const char* str)  �ú���
//	cout << tmp.c_str() << "  " << tmp.sz_str() << "  " << tmp.ca_str() << endl;
//
//	tmp = 'y' + tmp;
//	cout << tmp.c_str() << "  " << tmp.sz_str() << "  " << tmp.ca_str() << endl;
//
//	tmp.insert(8, 'z');
//	tmp.insert(8, 'f');
//	cout << tmp.c_str() << "  " << tmp.sz_str() << "  " << tmp.ca_str() << endl;
//
//	cout << "fzx λ�ã�" << tmp.find("fzx", 10) << endl;
//	cout << "fzx λ�ã�" << tmp.find("fzx", 2) << endl;
//	cout << "8 λ�ã�" << tmp.find("8", 0) << endl;
//	cout << "8 λ�ã�" << tmp.find('8', 0) << endl;
//}

//void test()
//{
//	/*String str; cout << str.c_str() << "-" << str.sz_str() << "-" << str.ca_str() << endl;
//	str.push_back('1'); cout << str.c_str() << "-" << str.sz_str() << "-" << str.ca_str() << endl;
//	str.push_back('2'); cout << str.c_str() << "-" << str.sz_str() << "-" << str.ca_str() << endl;
//	str.push_back('3'); cout << str.c_str() << "-" << str.sz_str() << "-" << str.ca_str() << endl;
//
//	str.resize(3); cout << str.c_str() << "-" << str.sz_str() << "-" << str.ca_str() << endl;
//	str.resize(10, 'a'); cout << str.c_str() << "-" << str.sz_str() << "-" << str.ca_str() << endl;
//	str.resize(20, 'b'); cout << str.c_str() << "-" << str.sz_str() << "-" << str.ca_str() << endl;
//
//	str.append("tonghh");
//	cout << str.c_str() << "-" << str.sz_str() << "-" << str.ca_str() << endl;
//
//	str += "__wahh";
//	cout << str.c_str() << "-" << str.sz_str() << "-" << str.ca_str() << endl;
//
//	str += 'w';
//	str += '_';
//	str += 'w';
//	cout << str.c_str() << "-" << str.sz_str() << "-" << str.ca_str() << endl;
//*/
//
//	String str1 = "1234";
//	String str2 = "9876";
//	String tmp;
//	tmp = str1 + str2;
//	cout << tmp.c_str() << "  " << tmp.sz_str() << "  " << tmp.ca_str() << endl;
//
//	tmp = tmp + "xx"; //������ String operator+(const String& str1, const char* str2)
//	//tmp += "xx";  //������ String& operator+=(const char* str)  �ú���
//	cout << tmp.c_str() << "  " << tmp.sz_str() << "  " << tmp.ca_str() << endl;
//
//	tmp = 'y' + tmp;
//	cout << tmp.c_str() << "  " << tmp.sz_str() << "  " << tmp.ca_str() << endl;
//
//	tmp.insert(8, 'z');
//	tmp.insert(8, 'f');
//	cout << tmp.c_str() << "  " << tmp.sz_str() << "  " << tmp.ca_str() << endl;
//
//	tmp.insert(0, 'f');
//	cout << tmp.c_str() << "  " << tmp.sz_str() << "  " << tmp.ca_str() << endl;
//
//	tmp.insert(4, "321");
//	cout << tmp.c_str() << "  " << tmp.sz_str() << "  " << tmp.ca_str() << endl;
//
//	tmp.insert(0, "asdfgh");
//	cout << tmp.c_str() << "  " << tmp.sz_str() << "  " << tmp.ca_str() << endl;
//
//	tmp.erase(20, 5);
//	cout << tmp.c_str() << "  " << tmp.sz_str() << "  " << tmp.ca_str() << endl;
//
//	tmp.erase(10, 5);
//	cout << tmp.c_str() << "  " << tmp.sz_str() << "  " << tmp.ca_str() << endl;
//
//	tmp.erase(10,10);
//	cout << tmp.c_str() << "  " << tmp.sz_str() << "  " << tmp.ca_str() << endl;
//
//	tmp.erase(0, 20);
//	cout << tmp.c_str() << "  " << tmp.sz_str() << "  " << tmp.ca_str() << endl;
//
//
//	//tmp.insert(25, 'j');//��������assert()
//	//cout << tmp.c_str() << "  " << tmp.sz_str() << "  " << tmp.ca_str() << endl;
//
//}

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
	//test();
	string a = "this is a test";
	size_t pos1 = a.find("this ");
	size_t pos2 = a.find(" test");
	cout << pos1 << endl << pos2 << endl;
	string sub1 = a.substr(pos1 + 5, pos2 - pos1 - 5);
	cout << sub1 << endl;
	cout << sub1.length();

	system("pause");
	return 0;
}