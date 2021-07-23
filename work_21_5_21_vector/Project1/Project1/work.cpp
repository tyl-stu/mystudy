#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
#include<assert.h>
#include<vector>

namespace bit
{
	template<class T>
	class vector
	{
	public:
		// Vector的迭代器是一个原生指针
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}

		const_iterator cbegin() const
		{
			return _start;
		}
		const_iterator cend() const
		{
			return _finish;
		}

		// construct and destroy
		vector()
		{
			_start = nullptr;
			_finish = nullptr;
			_endOfStorage = nullptr;
		}
		vector(int n, const T& value = T())
			:_start(new T[n])
			, _finish(_start + n)
			, _endOfStorage( _start + n)
		{
			for (size_t i = 0; i < n; i++)
				_start[i] = value;
		}

		template<class InputIterator>	
		vector(InputIterator first, InputIterator last)
		{
			reserve(last - first);
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		vector(const vector<T>& v)
			:_start(nullptr)
			,_finish(nullptr)
			,_endOfStorage(nullptr)
		{
			this->reserve(v.capacity());
			iterator it = begin();
			const_iterator vit = v.cbegin();
			while (vit != v.cend())
			{
				*it++ = *vit++;
			}
			_finish = it;
		}
		vector<T>& operator= (vector<T> v)
		{
			int n = v.size();
			_start = new T[v.capacity()];
			_finish = _start + n;
			_endOfStorage = _start + n;
			for (size_t i = 0; i < n; i++)
			{
				_start[i] = v[i];
			}
			//swap(v);
			return *this;
		}
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endOfStorage = nullptr;
			}
		}

		// capacity
		size_t size() const
		{
			return _finish - _start;
		}
		size_t capacity() const
		{
			return _endOfStorage - _start;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					for (size_t i = 0; i < sz; ++i)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz;
				_endOfStorage = _start + n;
			}
		}
		void resize(size_t n, const T& value = T())//value 用于填充空白位置
		{
			if (n > capacity())
			{
				reserve(n);
			}
			if (n > size())
			{
				//[size,n] 填充value
				while (_finish != _start + n)
				{
					*_finish = value;
					_finish++;
				}
			}
			// n < size
			_finish = _start + n;
		}
		///////////////access///////////////////////////////

		T& operator[](size_t pos)
		{
			assert(pos < size());//判断位置是否有效
			return _start[pos];
		}
		const T& operator[](size_t pos)const
		{
			assert(pos < size());
			return _start[pos];
		}

		///////////////modify/////////////////////////////
		void push_back(const T& x)
		{	
			insert(end(), x);
			////检查容量
			//if (_finish == _endOfStorage)
			//{
			//	size_t newC = _endOfStorage == nullptr ? 1 : 2 * capacity();
			//	reserve(newC);
			//}
			////插入
			//*_finish = x;

			////更新size
			//++_finish;
		}
		
		void pop_back()
		{
			if (size() > 0)
				erase(end() - 1);
		}
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endOfStorage, v._endOfStorage);
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(_start <= pos && pos <= _finish);
			if (_finish == _endOfStorage)
			{
				size_t len = pos - _start;
				size_t newC = capacity() == 0 ? 1 : capacity() * 2;
				reserve(newC);
				pos = _start + len;
			}
			iterator end = _finish;
			while (end != pos)
			{
				*end = *(end - 1);
				end--;
			}
			*pos = x;
			++_finish;
			return pos;
		}
		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			iterator start = pos + 1;
			while (start != _finish)
			{
				//第一次 pos+1 -> pos
				//最后一次 finish-1 -> finish-2
				*(start - 1) = *start;
				++start;
			}
			--_finish;
			return pos;
		}

	private:
		iterator _start; // 指向数据块的开始
		iterator _finish; // 指向有效数据的尾
		iterator _endOfStorage; // 指向存储容量的尾
	};
}

template<class T>
void printVectorFor(bit::vector<T>& vec) //只读
{
	//cout << "const for" << endl;
	for (auto& e : vec)
	{
		cout << e << " ";
	}cout << endl;
}

void test()
{
	bit::vector<int> v1( 3,6 );
	for (const int &n : v1)
		cout << n << " ";
	cout << endl;

	string s1 = "hhhhh";
	bit::vector<string> v2;
	v2.push_back(s1);
	printVectorFor(v2);

	bit::vector<string> v3(v2);
	printVectorFor(v3);

	string s2 = "hello";
	bit::vector<string> v4;
	v4.push_back(s2);
	printVectorFor(v4);

	bit::vector<char> v5(s2.begin(), s2.begin() + s2.size());
	printVectorFor(v5);

	bit::vector<char> v6;
	v6.operator=(v5);
	printVectorFor(v6);
}
int main()
{
	test();
	system("pause");
	return 0;
}