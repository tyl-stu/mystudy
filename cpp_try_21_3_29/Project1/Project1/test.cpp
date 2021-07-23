#include<iostream>
using namespace std;
#include<assert.h>
#include<algorithm>
#include<vector>
#include<list>
/*vector ��ʵ�� -- ������˳���*/

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
	//���������ͣ�T*
	typedef T* iterator;
	typedef const T* const_iterator;

	Vector()//�޲ι���
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{

	}

	Vector(size_t n, const T& val = T()) //��n��val�Ĺ��캯��
		:_start(new T[n])
		, _finish(_start + n)
		, _endOfStorage(_start + n) //��ʼ����˳����������������˳�򱣳�һ��
	{
		for (size_t i = 0; i < n; ++i)
		{
			_start[i] = val;
		}
	}

	template<class InputIterator>
	Vector(InputIterator first, InputIterator last) //����������
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
			//������ЧԪ�صĸ���
			size_t sz = size();
			//����ռ�
			T* tmp = new T[n];
			//��������
			if (_start)//�жϵ�ǰ�Ƿ�Ϊ��
			{
				//������ЧԪ�� ��size���ص�ֵ
				memcpy(tmp, _start, sizeof(T)*size());
				//�ͷ�ԭ�пռ�
				delete[] _start;
			}
			//����
			_start = tmp;
			//_finish = _start + size();//����������⣬��Ϊ_start�����˱仯������size()�ͻ��������
			_finish = _start + sz;//������size
			_endOfStorage = _start + n;//�൱�ڸ�����capacity
			
		}
	}

	void pushBack(const T& val)
	{
		//�������
		if (_finish == _endOfStorage)
		{
			size_t newC = _endOfStorage == nullptr ? 1 : 2 * capacity();
			reserve(newC);
		}

		//����
		*_finish = val;

		//����size
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
		assert(pos < size());//�ж�λ���Ƿ���Ч
		return _start[pos];
	}

	const T& operator[](size_t pos) const
	{
		assert(pos < size());
		return _start[pos];
	}

	void resize(size_t n, const T& val = T())
	{
		//Ĭ����Ϊ size <= capacity
		//n > capacity
		if (n > capacity())
		{
			reserve(n);//������
		}
		//size < n <capacity
		if (n > size())
		{
			//[size,n]:���val
			while (_finish != _start + n)
			{
				*_finish = val;
				++_finish;
			}
		}
		//n <= size,ֱ���޸�size�����޸�finishָ��,����Ҫ���
		_finish = _start + n;
	}

	void insert(iterator pos, const T& val)//pos����һ������������ָ��
	{
		/*��pos��Ϊ������������*/
		////���λ�� 
		//assert(pos < size());
		////�������
		//assert(size() <= capacity());
		////�ƶ�Ԫ�أ��Ӻ���ǰ
		//if (size() == capacity())
		//	reserve(capacity() + 1);
		//size_t i = size() - pos;
		//while (i)
		//{
		//	_start[pos + i] = _start[i];
		//	--i;
		//}
		////����
		//_start[pos] = val;
		////����
		
		/*pos ��ָ��*/
		//���λ�� [_start,_finish]
		assert(pos >= _start && pos <= _finish);
		//�������
		if (_finish == _endOfStorage)//����������������
		{
			cout << "need reserve" << endl;
			//���ݻᵼ�µ�����ʧЧ����Ϊ���ݺ�pos��ָ��ԭ�ռ�
			//��¼ƫ����������pos��start��ƫ����
			//����������������������û����pos����䣬�����ᱨ�����
			size_t offset = pos - _start;

			size_t newC = _endOfStorage == nullptr ? 1 : 2 * capacity();
			reserve(newC);

			//����Pos��ʹ��ָ���¿ռ�
			pos = _start + offset;
		}
		//�ƶ�Ԫ�أ��Ӻ���ǰ.finish:���һ����ЧԪ�صĽ�β
		iterator end = _finish;
		while (end != pos)
		{
			*end = *(end - 1);
			--end; 
		}
		//����
		*pos = val;
		//����
		++_finish;
	}

	//void erase(iterator pos)
	//{
	//	//��鷶Χ
	//	assert(pos >= _start && pos < _finish);
	//	//Ԫ���ƶ�:��ǰ����ƶ�
	//	iterator start = pos + 1;
	//	while (start != _finish)
	//	{
	//		//��һ�� pos+1 -> pos
	//		//���һ�� finish-1 -> finish-2
	//		*(start - 1) = *start;
	//		++start;
	//	}
	//	//����
	//	--_finish;
	//}

	//����ֵ��ָ��ɾ��Ԫ�ص���һ��λ��
	iterator erase(iterator pos)
	{
		//��鷶Χ
		assert(pos >= _start && pos < _finish);
		//Ԫ���ƶ�:��ǰ����ƶ�
		iterator start = pos + 1;
		while (start != _finish)
		{
			//��һ�� pos+1 -> pos
			//���һ�� finish-1 -> finish-2
			*(start - 1) = *start;
			++start;
		}
		//����
		--_finish;
		return pos;
	}

	//βɾ
	void poopBack()
	{
		if (size()>0)
			erase(end() - 1);//�����_finish
	}

	//��������
	~Vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}
	}

private:
	//start:��һ��Ԫ�ص��׵�ַ
	iterator _start;
	//finish:���һ����ЧԪ�صĽ�β
	iterator _finish;
	//endOfStorage:�ռ�Ľ�β
	iterator _endOfStorage;
};

template<class T>
void printVector(Vector<T>& vec,const T& val) //�ɶ���д
{
	cout << "iterator" << endl;
	Vector<T>::iterator it = vec.begin();
	while (it != vec.end())
	{
		cout << *it << " ";
		//*it = T();//���ö�Ӧ���޲ι���
		*it = val;//�޸�ֵ
		++it;
	}cout << endl;
}

template<class T>
void printVector(const Vector<T>& vec) // ֻ���������������޸�
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
void printVectorFor(Vector<T>& vec,const T& val)//�ɶ���д
{
	cout << "vector for" << endl;
	for (T& e : vec)  //���ܼ�const������Ͳ����޸�
	{
		cout << e << " ";
		e = val;
	}cout << endl;
}

template<class T>
void printVectorFor(const Vector<T>& vec) //ֻ��
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
	v.pushBack("123");//���˴��ᱨ�������������������
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
//	//�����㷨���ṩ��find���в���
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
//			it = v.erase(it);//�˴������_finish
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
//	it = v.begin();//��ֹ������ʧЧ����Ϊit�ظ�λ��
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
//	//Vector<A> v;//1��A(int)
//	//v.pushBack(A(1));
//	//v.pushBack(A(2));
//	//v.pushBack(A(3));
//	//v.pushBack(A(4));
//	//v.pushBack(A(5));//5��A(int) + 5���м�A(int)
//	//printVector(v, A(10));//1 2 3 4 5 //5��A(int)+5���м�A(int)
//	//printVector(v);//10 10 10 10 10
//
//	//printVectorFor(v, A(20));//1��A(int)
//	//printVectorFor(v);
//
//	Vector<A> v2;
//	v2.pushBack(A(3));
//	v2.pushBack(A(30));
//	printVector<A>(v2, A(10));//��ʽ��ӡ
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
//	printVector(v, 'a'); //���÷�const��ӡ
//	printVector(v);//����const��ӡ
//	
//}

//void test()
//{
//	Vector<int> v1(5); //5��0
//	Vector<char> v2(5);//5��'\0'
//	Vector<int*> v3(5);//5��ָ���ֵ
//
//	Vector<A> v4(5);   //5��Ĭ�ϵĽṹ�� ������5�ι��캯��
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