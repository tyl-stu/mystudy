#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<assert.h>
#include<algorithm>
#include<vector>
#include<list>
#include<string>
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

//istream& operator>>(istream& in, const size_t& a)
//{
//	in >> a;
//	return in;
//}
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
				//������ЧԪ�� ��size���ص�ֵ -- ������Զ������ͣ�ǳ���� -- ����ȡ
				//memcpy(tmp, _start, sizeof(T)*size());

				//���������������������������
				for (size_t i = 0; i < sz; ++i)
				{
					//���õ�ǰ���ݵĸ�ֵ�������������
					tmp[i] = _start[i];
				}

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

	void resize(size_t n, const T& val = T())//val �������հ�λ��
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
void printVector(Vector<T>& vec, const T& val) //�ɶ���д
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
void printVectorFor(Vector<T>& vec, const T& val)//�ɶ���д
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
void printOperator(Vector<T>& vec, const T& val)
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

class String
{
public:
	String(const char* str = " ")
		:_ptr(new char[strlen(str) + 1])
	{
		strcpy(_ptr, str);
	}
	String(const String& str)
		:_ptr(nullptr) //��ʼ��ֵ
	{
		String tmp(str._ptr);
		swap(_ptr, tmp._ptr);
	}
	String& operator=(String str)
	{
		swap(str._ptr, _ptr);
		return *this;
	}
	~String()
	{
		if (_ptr) // �ᵼ�¶����ͷţ��Ӷ����򱨴�
		{
 			delete[] _ptr;
			_ptr = nullptr;
		}
	}
private:
	char *_ptr;
};

void test()
{
	//Vector<String> v;
	//v.pushBack("123");
	//v.pushBack("123");
	//v.pushBack("123");//���˴��ᱨ�������������������,��Ϊ����ֶ����ͷ�
	//v.pushBack("123");
	//v.pushBack("123");

	//String str1 = "123";
	//String str2 = "456";
	//String str3 = "789";
	//String str4 = "101";
	//String str5 = "234";
	//Vector<String> v;
	//v.pushBack(str1);
	//v.pushBack(str2);
	//v.pushBack(str3);//���˴��ᱨ�������������������
	//v.pushBack(str4);
	//v.pushBack(str5);

	string str1 = "123";
	string str2 = "456";
	string str3 = "789";
	string str4 = "101";
	string str5 = "234";
	Vector<string> v;
	v.pushBack(str1); cout << v.capacity() << endl;
	v.pushBack(str2); cout << v.capacity() << endl;
	v.pushBack(str3);//���˴��ᱨ�������������������
	cout << v.capacity() << endl;
	v.pushBack(str4); cout << v.capacity() << endl;
	v.pushBack(str5); cout << v.capacity() << endl;
	printVectorFor(v);
	cout << v.capacity() << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}