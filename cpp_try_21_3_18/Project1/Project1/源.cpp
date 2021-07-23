#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
#include<assert.h>

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
		cout << "begin" << endl;
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
	
private:
	char *_data;
	//size:有效字符的个数
	size_t _size;
	//capacity:可以保存的最大有效字符个数 , '\0'不算
	size_t _capacity;
};

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
	test();
	
	system("pause");
	return 0;
}