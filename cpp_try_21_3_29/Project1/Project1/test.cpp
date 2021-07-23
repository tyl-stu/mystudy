#include<iostream>
using namespace std;
#include<assert.h>
#include<algorithm>
#include<vector>
#include<list>
/*vector 的实现 -- 类似于顺序表*/

struct  A
{
public:
	A(int a = 1)
		:_a(a)
	{
		cout << "A(int)" << endl;
	}
private:
	friend ostream& operator<<(ostream& out, const A& a);
	int _a;
};

istream& operator>>(istream& in, const size_t& a)
{
	in >> a;
	return in;
}
ostream& operator<<(ostream& out, const A& a)
{
	out << a._a;
	return out;
}

template<class T>
class Vector
{
public:
	//迭代器类型：T*
	typedef T* iterator;
	typedef const T* const_iterator;

	Vector()//无参构造
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{

	}

	Vector(size_t n, const T& val = T()) //赋n个val的构造函数
		:_start(new T[n])
		, _finish(_start + n)
		, _endOfStorage(_start + n) //初始化的顺序最好与变量声明的顺序保持一致
	{
		for (size_t i = 0; i < n; ++i)
		{
			_start[i] = val;
		}
	}

	template<class InputIterator>
	Vector(InputIterator first, InputIterator last) //迭代器构造
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{
		while (first != last)
		{
			pushBack(*first);
			++first;
		}
	}

	void reserve(size_t n)
	{
		if (n > capacity())
		{
			//保存有效元素的个数
			size_t sz = size();
			//申请空间
			T* tmp = new T[n];
			//拷贝内容
			if (_start)//判断当前是否为空
			{
				//拷贝有效元素 即size返回的值
				memcpy(tmp, _start, sizeof(T)*size());
				//释放原有空间
				delete[] _start;
			}
			//更新
			_start = tmp;
			//_finish = _start + size();//该语句有问题，因为_start发生了变化，调用size()就会产生问题
			_finish = _start + sz;//更新了size
			_endOfStorage = _start + n;//相当于更新了capacity
			
		}
	}

	void pushBack(const T& val)
	{
		//检查容量
		if (_finish == _endOfStorage)
		{
			size_t newC = _endOfStorage == nullptr ? 1 : 2 * capacity();
			reserve(newC);
		}

		//插入
		*_finish = val;

		//更新size
		++_finish;
	}

	size_t size() const
	{
		return _finish - _start;
	}

	size_t capacity() const
	{
		return _endOfStorage - _start;
	}

	iterator begin()
	{
		return _start;
	}

	iterator end()
	{
		return _finish;
	}

	const_iterator begin() const
	{
		return _start;
	}

	const_iterator end() const
	{
		return _finish;
	}

	T& operator[](size_t pos)
	{
		assert(pos < size());//判断位置是否有效
		return _start[pos];
	}

	const T& operator[](size_t pos) const
	{
		assert(pos < size());
		return _start[pos];
	}

	void resize(size_t n, const T& val = T())
	{
		//默认认为 size <= capacity
		//n > capacity
		if (n > capacity())
		{
			reserve(n);//先增容
		}
		//size < n <capacity
		if (n > size())
		{
			//[size,n]:填充val
			while (_finish != _start + n)
			{
				*_finish = val;
				++_finish;
			}
		}
		//n <= size,直接修改size，即修改finish指针,不需要填充
		_finish = _start + n;
	}

	void insert(iterator pos, const T& val)//pos不是一个整数，而是指针
	{
		/*将pos作为整数进行运算*/
		////检查位置 
		//assert(pos < size());
		////检查容量
		//assert(size() <= capacity());
		////移动元素：从后向前
		//if (size() == capacity())
		//	reserve(capacity() + 1);
		//size_t i = size() - pos;
		//while (i)
		//{
		//	_start[pos + i] = _start[i];
		//	--i;
		//}
		////插入
		//_start[pos] = val;
		////更新
		
		/*pos 是指针*/
		//检查位置 [_start,_finish]
		assert(pos >= _start && pos <= _finish);
		//检查容量
		if (_finish == _endOfStorage)//容量已满，需增容
		{
			cout << "need reserve" << endl;
			//增容会导致迭代器失效，因为增容后pos还指向原空间
			//记录偏移量，保存pos和start的偏移量
			//！！！！！！！！！！！没有这pos的语句，则程序会报错崩溃
			size_t offset = pos - _start;

			size_t newC = _endOfStorage == nullptr ? 1 : 2 * capacity();
			reserve(newC);

			//更新Pos，使其指向新空间
			pos = _start + offset;
		}
		//移动元素：从后向前.finish:最后一个有效元素的结尾
		iterator end = _finish;
		while (end != pos)
		{
			*end = *(end - 1);
			--end; 
		}
		//插入
		*pos = val;
		//更新
		++_finish;
	}

	//void erase(iterator pos)
	//{
	//	//检查范围
	//	assert(pos >= _start && pos < _finish);
	//	//元素移动:从前向后移动
	//	iterator start = pos + 1;
	//	while (start != _finish)
	//	{
	//		//第一次 pos+1 -> pos
	//		//最后一次 finish-1 -> finish-2
	//		*(start - 1) = *start;
	//		++start;
	//	}
	//	//更新
	//	--_finish;
	//}

	//返回值：指向被删除元素的下一个位置
	iterator erase(iterator pos)
	{
		//检查范围
		assert(pos >= _start && pos < _finish);
		//元素移动:从前向后移动
		iterator start = pos + 1;
		while (start != _finish)
		{
			//第一次 pos+1 -> pos
			//最后一次 finish-1 -> finish-2
			*(start - 1) = *start;
			++start;
		}
		//更新
		--_finish;
		return pos;
	}

	//尾删
	void poopBack()
	{
		if (size()>0)
			erase(end() - 1);//会更新_finish
	}

	//析构函数
	~Vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}
	}

private:
	//start:第一个元素的首地址
	iterator _start;
	//finish:最后一个有效元素的结尾
	iterator _finish;
	//endOfStorage:空间的结尾
	iterator _endOfStorage;
};

template<class T>
void printVector(Vector<T>& vec,const T& val) //可读可写
{
	cout << "iterator" << endl;
	Vector<T>::iterator it = vec.begin();
	while (it != vec.end())
	{
		cout << *it << " ";
		//*it = T();//调用对应的无参构造
		*it = val;//修改值
		++it;
	}cout << endl;
}

template<class T>
void printVector(const Vector<T>& vec) // 只读操作，不允许修改
{
	cout << "const_iterator" << endl;
	Vector<T>::const_iterator it = vec.begin();
	while (it != vec.end())
	{
		cout << *it << " ";
		++it;
	}cout << endl;
}

template<class T>
void printVectorFor(Vector<T>& vec,const T& val)//可读可写
{
	cout << "vector for" << endl;
	for (T& e : vec)  //不能加const，否则就不可修改
	{
		cout << e << " ";
		e = val;
	}cout << endl;
}

template<class T>
void printVectorFor(const Vector<T>& vec) //只读
{
	cout << "const for" << endl;
	for (const auto& e : vec)
	{
		cout << e << " ";
	}cout << endl;
}

template <class T>
void printOperator(Vector<T>& vec , const T& val)
{
	cout << "print operator" << endl;
	for (size_t i = 0; i < vec.size(); ++i)
	{
		cout << vec.operator[](i) << " ";
		vec[i] = val;
	}cout << endl;
}

template <class T>
void printOperator(const Vector<T>& vec)
{
	cout << "const operator" << endl;
	for (size_t i = 0; i < vec.size(); ++i)
	{
		cout << vec.operator[](i) << " ";
	}cout << endl;
}

void test()
{
	Vector<string> v;
	v.pushBack("123");
	v.pushBack("123");
	v.pushBack("123");//到此处会报错，错误出现于析构部分
	v.pushBack("123");
	v.pushBack("123");
}

//void test()
//{
//	Vector<int> v;
//	v.pushBack(1);
//	v.pushBack(2);
//	v.pushBack(3);
//	v.pushBack(4);
//	v.pushBack(5);
//	printVectorFor(v);//1 2 3 4 5
//	cout << v.size() << " " << v.capacity() << endl;//5 8
//
//	//利用算法中提供的find进行查找
//	Vector<int>::iterator it = find(v.begin(), v.end(), 30);
//	if (it != v.end())
//	{
//		cout << *it << endl;
//	}
//	else
//	{
//		cout << " not find" << endl;
//	}
//}

//void test()
//{
//	Vector<int> v;
//	v.pushBack(1);
//	v.pushBack(2);
//	v.pushBack(3);
//	v.pushBack(4);
//	v.pushBack(5);
//	printVectorFor(v);//1 2 3 4 5
//	cout << v.size() << " " << v.capacity() << endl;//5 8
//
//	Vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//		{
//			it = v.erase(it);//此处会更新_finish
//		}
//		else
//		{
//			++it;
//		}	
//	}
//	printVectorFor(v);
//	cout << v.size() << " " << v.capacity() << endl;//3 8
//
//	v.poopBack();
//	printVectorFor(v);//1 3
//	cout << v.size() << " " << v.capacity() << endl;//2 8
//}

//void test()
//{
//	Vector<int> v;
//	v.insert(v.begin(), 1);
//	printVectorFor(v);
//	v.insert(v.end(), 2);
//	printVectorFor(v);
//	Vector<int>::iterator it = v.begin();
//	v.insert(it, 66);
//	printVectorFor(v);
//	cout << v.size() << " " << v.capacity() << endl;
//
//	it = v.begin();//防止迭代器失效，需为it重赋位置
//	v.erase(it);
//	printVectorFor(v);
//	cout << v.size() << " " << v.capacity() << endl;
//}

//void test()
//{
//	Vector<int> v;
//	v.pushBack(1);
//	v.pushBack(2);
//	v.pushBack(3);
//	v.pushBack(4);
//	cout << v.size() << " " << v.capacity() << endl;// 4 4
//	printVectorFor(v);//1 2 3 4
//
//	v.resize(2, 100);// n < size
//	cout << v.size() << " " << v.capacity() << endl;//2 4
//	printVectorFor(v);// 1 2
//
//	v.resize(4, 5);// size < n < capacity
//	cout << v.size() << " " << v.capacity() << endl;//4 4
//	printVectorFor(v);//1 2 5 5
//
//	v.resize(10, 10);// n > capacity
//	cout << v.size() << " " << v.capacity() << endl;//10 10
//	printVectorFor(v);//1 2 5 5 10 10 10 10 10 10
//
//	v.insert(v.begin(), 666);
//	cout << v.size() << " " << v.capacity() << endl;//10 10
//	printVectorFor(v);//1 2 5 5 10 10 10 10 10 10
//
//}

//void test()
//{
//	//Vector<A> v;//1个A(int)
//	//v.pushBack(A(1));
//	//v.pushBack(A(2));
//	//v.pushBack(A(3));
//	//v.pushBack(A(4));
//	//v.pushBack(A(5));//5个A(int) + 5个中间A(int)
//	//printVector(v, A(10));//1 2 3 4 5 //5个A(int)+5个中间A(int)
//	//printVector(v);//10 10 10 10 10
//
//	//printVectorFor(v, A(20));//1个A(int)
//	//printVectorFor(v);
//
//	Vector<A> v2;
//	v2.pushBack(A(3));
//	v2.pushBack(A(30));
//	printVector<A>(v2, A(10));//显式打印
//	printVectorFor(v2);
//
//	printOperator(v2, A(300));
//	printOperator(v2);
//}

//void test()
//{
//	string str = "123456";
//	Vector<char> v(str.begin(), str.end());
//	list<char> lst(str.begin(), str.end());
//	Vector<char> v2(lst.begin(), lst.end()); //this is right!
//	printVector(v, 'a'); //调用非const打印
//	printVector(v);//调用const打印
//	
//}

//void test()
//{
//	Vector<int> v1(5); //5个0
//	Vector<char> v2(5);//5个'\0'
//	Vector<int*> v3(5);//5个指针空值
//
//	Vector<A> v4(5);   //5个默认的结构体 调用了5次构造函数
//
//	cout << v1.size() << endl;//5
//	cout << v2.size() << endl;//5
//	cout << v3.size() << endl;//5
//	cout << v4.size() << endl;//5
//	cout << v1.capacity() << endl;//5
//	cout << v2.capacity() << endl;//5
//	cout << v3.capacity() << endl;//5
//	cout << v4.capacity() << endl;//5
//}

//void test()
//{
//	Vector<int> v1;
//	Vector<char> v2;
//	Vector<int*> v3;
//
//	cout << v1.size() << endl;
//	cout << v2.size() << endl;
//	cout << v3.size() << endl;
//	cout << v1.capacity() << endl;
//	cout << v2.capacity() << endl;
//	cout << v3.capacity() << endl;
//}

int main()
{
	test();
	system("pause");
	return 0;
}