#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
#include<assert.h>

/*  实现string类的接口，并完成测试，要求利用深拷贝和深赋值实现  */
//class String
//{
//public:
//	String(const char* str = "")
//		:_str(new char[strlen(str) + 1])
//	{
//		cout << "String 全缺省的构函" << endl;
//		strcpy(_str, str);
//	}
//	String(const String &s)//深拷贝
//		:_str(nullptr)
//	{
//		cout << "深拷贝" << endl;
//		String t(s._str);
//		swap(t._str, _str);
//	}
//	String& operator=(const String &s)
//	{
//		cout << "operator= " << endl;
//		String t(s._str);
//		swap(t._str, _str);
//		return *this;
//	}
//	const char *c_str() const
//	{
//		return _str;
//	}
//	~String()
//	{
//		cout << "~String" << endl;
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//private:
//	char *_str;
//};
//void test()
//{
//	String s("123456");
//	cout << s.c_str() << endl;
//	String s2 = s;
//	cout << s2.c_str() << endl;
//	String s3;
//	s3 = s;
//	cout << s3.c_str() << endl;
//	String s4(s);
//	cout << s4.c_str() << endl;
//}

/* 模拟实现string类，并完成测试 */
namespace bit
{
	class String
	{
		friend ostream& operator<<(ostream& _cout, const bit::String& s);
		friend istream& operator>>(istream& _cin, bit::String& s);
	public:
		typedef char* iterator;
	public:
		String(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		String(const String& s)
			:_str(nullptr),
			_size(0),
			_capacity(0)
		{
			//深拷贝
			String t(s);
			this->Swap(t);
		//	strcpy(_str, s._str);
		}
		String& operator=(const String &s)
		{
			String t(s);
			this->Swap(t);
			return *this;
		}
		~String()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_size = _capacity = 0;
			}
		}

		//////////////////////////////////////////////////////////////
		// iterator
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}

		/////////////////////////////////////////////////////////////
		// modify
		void push_back(char c)
		{
			//检查空间
			if (_size == _capacity)
			{
				size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
				Reserve(newC);
			}
			_str[_size++] = c;
			_str[_size] = '\0';
		}
		String& operator+=(char c)
		{
			this->push_back(c);
			return *this;
		}
		void append(const char* str)
		{
			size_t newC = _capacity == 0 ? 15 : _capacity + strlen(str);
			Reserve(newC);
			//char *str2 = str;
			
			for (int i = 0; i < strlen(str); i++)
			{
				_str[_size++] = str[i];
			}
			_str[_size] = '\0';
		}
		String& operator+=(const char* str)
		{
			this->append(str);
			return *this;
		}
		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}
		void Swap(String& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}
		const char* c_str()const
		{
			return this->_str;
		}

		/////////////////////////////////////////////////////////////
		// capacity
		size_t size()const
		{
			return _size;
		}
		size_t capacity()const
		{
			return _capacity;
		}
		bool empty()const
		{
			if (_size != 0)
				return true;
			return false;
		}
		void resize(size_t n, char c = '\0')
		{
			if (n > _capacity)
			{
				Reserve(n);
			}
			//_size < n < _capacity
			//填充字符 ch
			//void * memset（void * ptr，int value，size_t num）; -- 将ptr指向的内存块的前num个字节设置为指定值
			if (n > _size)
			{
				memset(_str + _size, c, (n - _size)*sizeof(char));
			}
			_size = n;
			_str[_size] = '\0';
		}
		void Reserve(size_t n)
		{
			if (n > _capacity)
			{
				char *str = new char[n + 1];
				strcpy(str, _str);
				delete[] _str;
				_str = str;
				_capacity = n;
			}
		}

		/////////////////////////////////////////////////////////////
		// access
		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}
		const char& operator[](size_t index)const
		{
			assert(index < _size);
			return _str[index];
		}

		/////////////////////////////////////////////////////////////
		//relational operators
		bool operator<(const String& s)
		{
			int ret = strcmp(this->c_str(), s.c_str());
			if (ret < 0)
				return true;
			else
				return false;
		}
		bool operator<=(const String& s)
		{
			int ret = strcmp(this->c_str(), s.c_str());
			if (ret < 0 || ret == 0)
				return true;
			else
				return false;
		}
		bool operator>(const String& s)
		{
			int ret = strcmp(this->c_str(), s.c_str());
			if (ret > 0)
				return true;
			else
				return false;
		}
		bool operator>=(const String& s)
		{
			int ret = strcmp(this->c_str(), s.c_str());
			if (ret > 0 || ret == 0)
				return true;
			else
				return false;
		}
		bool operator==(const String& s)
		{
			int ret = strcmp(this->c_str(), s.c_str());
			if (ret == 0)
				return true;
			else
				return false;
		}
		bool operator!=(const String& s)
		{
			int ret = strcmp(this->c_str(), s.c_str());
			if (ret != 0)
				return true;
			else
				return false;
		}

		// 返回c在String中第一次出现的位置
		size_t find(char c, size_t pos = 0) const
		{
			for (size_t i = 0; i < _size; i++)
			{
				if (_str[i] == c)
				{
					return i;
				}
			}
			return -1;
		}

		// 返回子串s在String中第一次出现的位置
		size_t find(const char* s, size_t pos = 0) const
		{
			//char * strstr(const char *dest,const char *src);
			//strstr()返回值：未找到，返回NULL;找到返回第一次出现的位置的首地址
			int len = strlen(s);
			if ((pos + len) <= _size)
			{
				char *p = strstr(_str + pos, s);
				if (p)
					return p - _str;
				return -1;
			}
			return -1;
		}

		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
		String& insert(size_t pos, char c)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
				Reserve(newC);
			}
			size_t t = _size + 1;
			while (pos < t)
			{
				_str[t] = _str[t - 1];
				t--;
			}
			_str[pos] = c;
			++_size;
			return *this;
		}
		String& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			int len = strlen(str);
			if ((_size + len) >= _capacity)
			{
				Reserve(_size + len);
			}
			size_t t = _size + len;
			while (t > (pos + len - 1))
			{
				_str[t] = _str[t - len];
				t--;
			}
			//插入:pos  此处不能使用strcpy,因为该函数会将 '\0' 也给拷贝进去，从而不会有原数据 pos 之后的内容
			memcpy(_str + pos, str, sizeof(char)*len);
			_size += len;
			return *this;
		}

		// 删除pos位置上的元素，并返回该元素的下一个位置
		String& erase(size_t pos, size_t len)
		{
			assert(pos <= _size);
			size_t begin = pos;
			if ((_size - begin) < len)
			{
				_str[begin] = '\0';
				_size = pos;
			}
			else
			{
				while (begin < (pos + len))
				{
					_str[begin] = _str[begin + len];
					begin++;
				}
				_size -= len;
				_str[_size] = '\0';
			}
			return *this;
		}

	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
};

void test()
{
	bit::String s1 = "123";
	s1.push_back('4');
	char *str = "56789";
	cout << s1.c_str() << endl;
	s1.append(str);
	cout << s1.c_str() << endl;
	char *str2 = "aoe";
	s1 += str2;
	//cout << s1.c_str() << s1.empty() << endl;
	cout << s1.c_str() << "  " << s1.size() << "  " << s1.capacity() << endl;
	/*s1.clear();
	cout << s1.c_str() << s1.empty() << endl;*/
	s1.resize(10);
	cout << s1.c_str() << "  " << s1.size() << "  " << s1.capacity() << endl;
	for (int i = 0; i < s1.size();i++)
	{
		cout << s1[i] << " ";
	}cout << endl;

	bit::String s2 = "123";
	bit::String s3 = "456";
	cout << "s2 > s3 ? " << s2.operator>(s3) << endl;
	cout << "s2 < s3 ? " << s2.operator<(s3) << endl;
	cout << "s2 <= s3 ? " << s2.operator<=(s3) << endl;
	cout << "s2 >= s3 ? " << s2.operator>=(s3) << endl;
	cout << "s2 == s3 ? " << s2.operator==(s3) << endl;
	cout << "s2 != s3 ? " << s2.operator!=(s3) << endl;

	cout << s1.find('5') << "  " << s1.find("789") << endl;

	s1.insert(5,'v');
	cout << s1.c_str() << "  " << s1.find('v') << endl;
	s1.insert(6, "ector");
	cout << s1.c_str() << "  " << s1.find("ector") << endl;

	s1.erase(5, 6); cout << s1.c_str() << "  " << s1.size() << endl;
	s1.erase(s1.size() - 1, 1); cout << s1.c_str() << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}
