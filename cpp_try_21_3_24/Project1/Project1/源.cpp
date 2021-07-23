#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
#include<assert.h>

#include<typeinfo>

/* 实现 string 类*/

/*经典写法*/
//class String
//{
//public:
//	/*String()
//		:_data(new char[1]) 
//	{
//		_data[0] = '\0';
//	}*/
//
//	//全缺省的构造函数
//	String(const char* str = "")
//		:_data(new char[strlen(str) + 1])// +1 是为 '\0'留位置
//	{
//		cout << "String" << endl;
//		strcpy(_data, str);
//	}
//
//	//浅拷贝
//	/*String(const String& str)
//		:_data(str._data)
//	{
//
//	}*/
//
//	//深拷贝
//	String(const String& str)
//		:_data(new char[strlen(str._data) + 1])
//	{
//		cout << "深拷贝" << endl;
//		//深拷贝,重开空间保存数据
//		strcpy(_data, str._data);
//	}
//
//	//类的成员函数后面加 const，表明这个函数不会对这个类对
//	//象的数据成员（准确地说是非静态数据成员）作任何改变。
//	const char *c_str() const
//	{
//		return _data;
//	}
//
//	String& operator=(const String& str)
//	{
//		cout << "operator=" << endl;
//		if (this != &str)//此时的 & 不是引用，而是地址，即指针，与 this 对应
//		{
//			//释放原有的空间，然后申请一个str的空间
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
//	String str2(str);//深拷贝
//	String str3 = str2;//深拷贝
//	String str4;
//	str4.operator=("hjsfhjk");//赋值运算符重载，其先是创建 hjsfhjk 对象，然后再赋值给str4
//	cout << str.c_str() << endl;
//	cout << str2.c_str() << endl;
//	cout << str3.c_str() << endl;
//	cout << str4.c_str() << endl;
//}
//
////void test()
////{
////	String str("123");
////	//浅拷贝：只拷贝String对象中的内容
////	//String copy(str);//浅拷贝
////	String str2("456");
////	str2 = str;//浅拷贝，内存泄漏
////}
//
////void test()
////{
////	string str;
////	cout << str.c_str() << endl;
////	String str1("123");
////	cout << str1.c_str() << endl;
////}

/*现代写法*/
//class String
//{
//public:
//
//	//全缺省的构造函数
//	String(const char* str = "")
//		:_data(new char[strlen(str) + 1])// +1 是为 '\0'留位置
//	{
//		cout << "String" << endl;
//		strcpy(_data, str);
//	}
//
//	//浅拷贝
//	/*String(const String& str)
//	:_data(str._data)
//	{
//
//	}*/
//
//	//深拷贝  --  拷贝构造的现代写法
//	String(const String& str)
//		:_data(nullptr)//使_data变为空指针
//	{
//		cout << "swap - 拷贝" << endl;
//		String tmp(str._data);//tmp 为临时对象，调用完后，自动释放 -- 复用构造函数的逻辑
//		swap(tmp._data, _data);//相当于this指向与tmp指向发生了变换 -- 完成实际的拷贝
//	}
//
//	//类的成员函数后面加 const，表明这个函数不会对这个类对
//	//象的数据成员（准确地说是非静态数据成员）作任何改变。
//	const char *c_str() const 
//	{
//		return _data;
//	}
//
//	//String& operator=(const String& str)
//	//{
//	//	cout << "operator=" << endl;
//	//	if (this != &str)//此时的 & 不是引用，而是地址，即指针，与 this 对应
//	//	{
//	//		//释放原有的空间，然后申请一个str的空间
//	//		delete[] _data;
//	//		String tmp(str._data);
//	//		swap(tmp._data, _data);
//	//	}
//	//	return *this;
//	//}
//	/*赋值运算符的现代写法
//	释放原有空间，申请新的空间，拷贝内容*/
//	String& operator=(const String& str)
//	{
//		cout << "operator=" << endl;
//		//swap(str._data, _data);//这样会交换 str._data 和 this->_data 的值
//		String tmp(str._data);
//		swap(tmp._data, _data);//如此是将 str._data 赋值给 this->_data
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
//	String str2(str);//深拷贝
//	String str3 = str2;//深拷贝
//	String str4;
//	str4.operator=(str);//赋值运算符重载，其先是创建 hjsfhjk 对象，然后再赋值给str4
//	cout << str.c_str() << endl;
//	cout << str2.c_str() << endl;
//	cout << str3.c_str() << endl;
//	cout << str4.c_str() << endl;
//}

/*写时拷贝*/
class String
{
public:
	//String的迭代器
	//迭代器操作：类似于指针
	//解引用：*iterator --> 获取内
	//移动：++iterator,--iterator,移动到相邻元素的位置
	//String迭代器实现：字符指针
	typedef char *iterator;//可读可写
	typedef const char *const_iterator;//可读不可写
	iterator begin()
	{
		//cout << "begin" << endl;
		//第一个元素的位置
		return _data;
	}
	iterator end()
	{
		//最后一个元素的下一个位置
		return _data + _size;
	}

	const_iterator begin() const
	{
		cout << "const_begin" << endl;
		//第一个元素的位置
		return _data;
	}
	const_iterator end() const
	{
		//最后一个元素的下一个位置
		return _data + _size;
	}

	String(const char *str = "")//构造函数只需传入字符数据，其他参数不用传入
	{
		//cout << "string" << endl;
		_size = strlen(str);
		_data = new char[_size + 1];
		_capacity = _size;
		strcpy(_data, str);//strcpy(a,b)  -- 将b的值拷给a
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

	const char *c_str() const  //返回对象的有效数据
	{
		return _data;
	}

	const size_t ca_str() const  //返回对象的最大有效字符个数
	{
		return _capacity;
	}

	const size_t sz_str() const  //返回对象的有效字符个数
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
		assert(pos < _size);//assert(exc)：当exc不成立时，会报错
		return _data[pos];
	}

	const char& operator[](size_t pos) const
	{
		//cout << "const operator[]" << endl;
		assert(pos < _size);
		return _data[pos];
	}

	//size_t size() const  //与上面函数重复
	//{
	//	return _size;
	//}

	//尾插字符
	void push_back(const char &ch)
	{
		//检查空间
		if (_size == _capacity)
		{
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			//增容 2倍
			reserve(newC);
		}
		_data[_size++] = ch;

		//添加结束字符 '\0'
		_data[_size] = '\0';
	}

	//开辟空间
	void reserve(size_t n)
	{
		if (n > _capacity)
		{
			//申请空间
			char *tmp = new char[n + 1];
			//拷贝
			strcpy(tmp, _data);//把_data的值拷给tmp
			//释放原有空间
			delete[] _data;
			_data = tmp;
			_capacity = n;
		}
		//cout << _capacity << endl;
	}

	//更改字符个数size
	void resize(size_t n, const char& ch = '\0')
	{
		//n > _capacity : 需要增容
		if (n > _capacity)
		{
			reserve(n);
		}
		// _size < n <= _capacity
		//填充字符 ch
		//void * memset（void * ptr，int value，size_t num）; -- 将ptr指向的内存块的前num个字节设置为指定值
		if (n > _size)
			memset(_data + _size, ch, (n - _size)*sizeof(char));

		//直接修改size
		_size = n;

		_data[_size] = '\0';
	}

	//尾插对象
	void append(const char* str)
	{
		//检查容量
		int len = strlen(str);
		if ((_size + len) > _capacity)//要添加的字符串的长度j
		{
			reserve(_size + len);
		}
		//尾插 - 字符串
	//	memcpy(_data + _size, str, sizeof(char)*len);//o(1)的操作 -- 比较高效
		strcpy(_data + _size, str);//从数据的原尾部插入新护具  o(n)的操作
		//更新成员
		_size += len;
		_data[_size] = '\0';//使数据正确结束
	}

	//String operator+=()  调用已有函数实现法  -- 尾插对应内容
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
		//append(&ch); //该法可以
		push_back(ch);//该法亦可以
		return *this;
	}

	void insert(size_t pos, const char& ch)
	{
		//检查位置有效性
		assert(pos <= _size);

		//检查容量
		if (_size == _capacity)
		{
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		
		//移动元素：[pos,size]  从后向前移  no probelm
		size_t end = _size + 1;//包含 '\0' ,即字符串结束的字符，所以此处不需要进行对添加字符后的数据进行结束操作（即使数据最后一个字符为 '\0'）
		while (end > pos)//end 最后一位为 pos + 1,则有 _data[pos+1]=_data[pos]
		{
			_data[end] = _data[end - 1];
			--end;
		}
		//int end = _size;
		////这个有bug，因为end类型为size_t,从 0 处进行头插时，会越界,
		////为解决该问题，可以将end类型改为int,并将参数列表中 pos 的数据类型也改为int
		//while (end >= pos)
		//{
		//	_data[end + 1] = _data[end];
		//	--end;
		//}

		//插入:pos
		_data[pos] = ch;

		//更新
		++_size;
	}
	void insert(size_t pos, const char* ptr)
	{
		//检查位置有效性
		assert(pos <= _size);
		int len = strlen(ptr);
		//检查容量
		if ((_size + len) >= _capacity)
		{
			reserve(_size + len);
		}

		//移动元素：[pos,size]  从后向前移  no probelm
		size_t end = _size + len;//包含 '\0' ,即字符串结束的字符，所以此处不需要进行对添加字符后的数据进行结束操作（即使数据最后一个字符为 '\0'）
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!出问题的地方
		while (end > (pos + len - 1))//end最后一位是 pos + len ,带入循环，则有_data[pos + len]=_data[pos]
		{
			_data[end] = _data[end - len];
			--end;
		}

		//插入:pos  此处不能使用strcpy,因为该函数会将 '\0' 也给拷贝进去，从而不会有原数据 pos 之后的内容
		memcpy(_data+pos, ptr, sizeof(char)*len);
		//strcpy(_data +pos,ptr); //该函数最终结果有误

		//更新
		_size += len;
		_data[_size] = '\0';//该语句可有可无，因为在上述循环中已实现了该语句的功能
	}

	void erase(size_t pos, size_t len)
	{
		assert(pos <= _size);
		size_t begin = pos;
		if ((_size - begin) < len)//如此写可以避免bug
		{
			_data[begin] = '\0';	
			_size = pos;
		}
		else
		{
			//从前向后移动
			while (begin < (pos + len))
			{
				_data[begin] = _data[begin + len];
				++begin;
			}
			
			_size -= len;
			_data[_size] = '\0';
		}
		
	}

	size_t find(const char &ch, size_t pos = 0)//半缺省是从右往左，且查找的位置默认从0开始，所以该函数的参数列表即为size_t find(const char &ch, size_t pos = 0)
	{
		cout << "find(ch)" << endl;
		for (size_t i = 0; i < _size; i++)
		{
			if (_data[i] == ch)
				return i;
		}
		return npos;
	}
	size_t find(const char* str, size_t pos = 0)//半缺省是从右往左，且查找的位置默认从0开始，所以该函数的参数列表即为size_t find(const char &ch, size_t pos = 0)
	{
		cout << "find(*str)" << endl;
		//char * strstr(const char *dest,const char *src);
		//strstr()返回值：未找到，返回NULL;找到返回第一次出现的位置的首地址
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

	/*若此为类成员函数，则输出为从右往左输出，与正常从左往右输出相悖*/
	ostream& operator<<(ostream& out) const
	{
		for (const char& ch : *this)//范围for 使用哪种begin()迭代器，主要看输入对象是const还是非const
		{
			out << ch;
		}
		cout << endl;
		return out;
	}

private:
	char *_data;
	//size:有效字符的个数
	size_t _size;
	//capacity:可以保存的最大有效字符个数 , '\0'不算
	size_t _capacity;

	static const size_t npos;
};

const size_t String::npos = -1;

istream& operator>>(istream& in, String& str)
{
	char ch;
	str = "";
	//因为 cin 无法输入空格或回车，所以改用 getchar()
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
	for (const auto& ch : str)//范围for  用了非const的迭代器
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

/* String operator+= 的正常实现方法 */
//String& String::operator+=(const String& str)
//{
//	int len = str._size;
//	//检查容量
//	if ((_size + len) > _capacity)
//	{
//		reserve(_size + len);
//	}
//	//尾插 - String对象
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

/* String operator+  的实现 （所传入的对象内容不能变）*/
String operator+(const String& str1,const String& str2)  //非成员函数
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
String operator+(const String& str1, const char* str2)  //非成员函数
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
String operator+(const char ch ,const String& str1)  //非成员函数
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
	//范围for:需要用到begin(),end(),此处为const对象，所以会调用const begin
	for (const char& ch : str)
	{
		cout << ch << " ";
	}cout << endl;
}
void printStringIt(const String& str)
{
	//String::iterator it = str.begin();//会报错，因为类型不一致
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
	
	/*ostream() 重载为 类成员函数*/
	//tmp << cout;
	//str2 << (str1 << cout);//从右向左输出，即 1234 9876

	/*ostream() 重载为类外函数  如此会调用类中const__begin()迭代器,因为重载函数中输入的为const对象*/
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
//	tmp = tmp + "xx"; //调用了 String operator+(const String& str1, const char* str2)
//	//tmp += "xx";  //调用了 String& operator+=(const char* str)  该函数
//	cout << tmp.c_str() << "  " << tmp.sz_str() << "  " << tmp.ca_str() << endl;
//
//	tmp = 'y' + tmp;
//	cout << tmp.c_str() << "  " << tmp.sz_str() << "  " << tmp.ca_str() << endl;
//
//	tmp.insert(8, 'z');
//	tmp.insert(8, 'f');
//	cout << tmp.c_str() << "  " << tmp.sz_str() << "  " << tmp.ca_str() << endl;
//
//	cout << "fzx 位置：" << tmp.find("fzx", 10) << endl;
//	cout << "fzx 位置：" << tmp.find("fzx", 2) << endl;
//	cout << "8 位置：" << tmp.find("8", 0) << endl;
//	cout << "8 位置：" << tmp.find('8', 0) << endl;
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
//	tmp = tmp + "xx"; //调用了 String operator+(const String& str1, const char* str2)
//	//tmp += "xx";  //调用了 String& operator+=(const char* str)  该函数
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
//	//tmp.insert(25, 'j');//触发断言assert()
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
//	/* 三种遍历方式 ，且都可修改内容,除了静态的*/
//
//	/*方式一：for循环*/
//	String str("123456789");
//	for (size_t i = 0; i < str.size(); ++i)
//	{
//		cout << str[i] << " ";// 等价于 str.operator[](i)
//	}
//	cout << endl;
//	str[4] = 'a';
//	cout << str.c_str() << endl;
//
//	/*方式二：范围for*/
//	for (const auto& ch : str)
//	{
//		cout << ch << " ";
//	}cout << endl;
//
//	/*方式三：迭代器遍历*/
//	String::iterator it = str.begin();
//	while (it != str.end())
//	{
//		cout << *it << " ";
//		it++;
//		*it = 'b';
//	}cout << endl;
//	
//	//静态迭代器遍历，只可读不可写
//	String::const_iterator it1 = str.begin();
//	while (it1 != str.end())
//	{
//		cout << *it1 << " ";
//		it1++;
//		//*it1 = 'c';//会报错
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