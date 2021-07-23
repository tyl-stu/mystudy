#include<iostream>
using namespace std;
#include<vector>

//template <class T>
//void printIterator(const vector<T>& vec);//�����ӡ
//
//template <class T>
//void printReverIterator(const vector<T>& vec);//�����ӡ
//
//template < class T >
//void printFor(const vector<T>& vec);//��Χfor
//
//template < class T >
//void printFor2(const vector<T>& vec);//��Χfor
//
//class A
//{};

//void test()
//{
//	/*����vector*/
//	//��ģ��ʵ���࣬Ĭ�Ϲ���
//	vector<int> v1; //�洢int�����ݵ����п⣬Ĭ�ϸ���0
//	vector<char> v2;//Ĭ�ϸ��� '\0'
//	vector<A> v3;//�洢�Զ�������
//
//	vector<A> v4(10);//������vector�а���10��A�Ķ������Ĭ��ֵΪA��Ĭ��ֵ
//	A a;//aΪ�������Ķ���
//	//vector(n,�Զ������͵�Ĭ�Ϲ���())
//	vector<A> v5(20, A());
//	vector<A> v6(20, a);
//
//	//vector(n,�������͵���0ֵ)
//	//���֣�0
//	//�ַ���\0
//	//ָ�룺nullptr
//	vector<int> v7(10);//Ĭ�ϸ���10��0
//	vector<char> v8(10);//Ĭ�ϸ���10��'\0'
//	printIterator(v7);
//	printIterator(v8);//��Ϊ��Ԫ��Ĭ��Ϊ'\0'�����Դ�ӡ������û��ʲô��ʾ 
//
//	//�������ĳ�ʼ��
//	char arr[] = "12345678";
//	vector<char> v10(arr, arr + sizeof(arr) / sizeof(arr[0])-1);
//	printIterator(v10);
//	printReverIterator(v10);
//	printFor(v10);
//
//	for(size_t i = 0; i < v10.size(); ++i)
//	{
//		v10.operator[](i) = 'c';//[] ��������ʽ
//		v10[i] = 'x';
//	}
//	printFor2(v10);
//
//	//[]Խ�磺debug�汾����assert����release�汾���������
//	//v10[100] = 'c';
//	//atԽ�磺�������ַ�ʽ�������쳣
//	//v10.at(100);
//
//	/*vector<char>::iterator it = v10.begin();
//	while (it != v10.end())
//	{
//		cout << *it << " ";
//		*it = 'a';
//		it++;	
//	}
//	cout << endl;
//	it = v10.begin();
//	while (it != v10.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;*/
//}
 
template <class T>
void printIterator(const vector<T>& vec)//�ɴ�ӡvector��Ԫ�أ�ֻ����ʽ
{
	//vector<T>::iterator it = vec.begin();//�����ᱨ����Ϊ���������б��е��õ���const�����Դ˴�Ӧ��ʹ��const_iterator����const������
	vector<T>::const_iterator it = vec.begin();
	while (it != vec.end())
	{
		cout << *it << " ";
		it++;
	}cout << endl;
}

template <class T>
void printReverIterator(const vector<T>& vec)//�ɴ�ӡvector��Ԫ�أ�ֻ����ʽ
{
	//vector<T>::reverse_iterator it = vec.begin();//�����ᱨ����Ϊ���������б��е��õ���const�����Դ˴�Ӧ��ʹ��const_iterator����const������
	vector<T>::const_reverse_iterator it = vec.rbegin();
	while (it != vec.rend())
	{
		cout << *it << " ";
		it++;
	}cout << endl;
}

template < class T >
void printFor(const vector<T>& vec)
{
	for (const auto& e : vec)
	{
		cout << e << " ";

	}cout << endl;
}

template <class T>
void printFor2(const vector<T>&vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}cout << endl;
}

struct A  // 4 +4 +4���ֽڶ��룩+4=16byte
{
	int _a;
	int _b;
	char _c;
	char* _ptr;
};

struct A2
{
public:
	/*A2(int a, int b, char c)
		:_a(a),
		_b(b),
		_c(c),
		_ptr(nullptr)
	{
		cout << "ok!" << endl;
	}*/

	A2(int a, int b, char c)
		:_a(a),
		_b(b),
		_c(c)
	{
		cout << "ok!" << endl;
	}
	
	/*void printA()
	{
		cout << _a << " " << _b << " " << _c << " " << _ptr << endl;

	}*/
private:
	friend ostream& operator<<(ostream& out, const A2& a);
	int _a;
	int _b;
	char _c;
	//char* _ptr;
};
ostream& operator<<(ostream& out, const A2& a)
{
	out << a._a << " " << a._b << " " << a._c ;
	return out;
}
template<class T>
void printFor(vector<T>& vec)
{
	for (T& e : vec)
	{
		cout << e <<" ";
	}cout << endl;
	
}

void test()
{
	vector<A2> v;//�����ù���Ȼ��ֱ����ʾ
	v.push_back(A2(1, 2, '3'));
	printFor(v);
}

//void printA(A2 x)
//{
//	cout << x._a << " " << x._b << " " << x._c << " " << x._ptr << endl;
//	
//}


//void test()
//{
//	vector<char> v1;
//	vector<char*> v2;
//	vector<int> v3;
//	vector<A> v4;
//
//	cout << v1.max_size() << endl;//4294967295  char - 1byte ,Ѱַ��Χ4G ,�������4G��
//	cout << v2.max_size() << endl;//1073741823  char* - ָ�룬4byte ,�����1G��
//	cout << v3.max_size() << endl;//1073741823  int - 4byte,�����1G��
//	cout << v4.max_size() << endl;//268435455   A - 16byte,�����1G/4��
//
//	//void resize (size_type n, value_type val = value_type());
//	printFor(v1);
//	v1.resize(10);
//	printFor(v1);
//	v1.resize(15, 'a');//�����޸����е�ֵ����δ��ֵ�ĵط������丳��ֵ�������б��е�ֵ��
//	//v1.resize(n,T()) n�����������Ӱ������
//	v1.resize(100, 'b');
//	printFor(v1);
//	//printFor(v4);//���ܴ�ӡ���������������
//	v4.resize(10);
//
//	cout<< v1.size() << " " << v1.capacity() << endl;
//	v1.reserve(50);//reserve() -- ֻ���ݣ���Ӱ������size
//	cout << v1.size() << " " << v1.capacity() << endl;
//	v1.reserve(200);
//	cout << v1.size() << " " << v1.capacity() << endl;
//}

/*����*/
//void test()
//{
//	vector<int> v;
//	//PJ��vector���ݹ���Լ1.5��
//	size_t cap = v.capacity();
//	cout << cap << endl;
//	for (int i = 0; i < 200; i++)
//	{
//		v.push_back(i);
//		if (cap != v.capacity())
//		{
//			cap = v.capacity();
//			cout << cap << endl;
//		}
//	}
//	
//}

/*void shrink_to_fit(); ��С����*/
//void test()
//{
//	//shrink_to_fit() - ������capacity��С��size
//	vector<int> v;
//	cout << v.size() << " " << v.capacity() << endl;//0 0
//
//	v.resize(10);//����size
//	v.reserve(30);//����capacity
//	cout << v.size() << " " << v.capacity() << endl;//10 30
//
//	v.shrink_to_fit();
//	cout << v.size() << " " << v.capacity() << endl;//10 10
//
//	v.reserve(1000);
//	cout << v.size() << " " << v.capacity() << endl;//10 1000
//	v.shrink_to_fit();
//	cout << v.size() << " " << v.capacity() << endl;//10 10
//}

/*  �ı����ݣ������ǲ���
template <class InputIterator>
  void assign (InputIterator first, InputIterator last);	
void assign (size_type n, const value_type& val);*/
//void test()
//{
//	vector<int> v(3, 2);//3��2
//	printFor(v);//2 2 2
//	//��ֵ
//	v.assign(5, 1);
//	printFor(v);//1 1 1 1 1
//
//	vector<int> v2(3, 6);//3��6
//	v.assign(v2.begin(), v2.end());
//	printFor(v2);//6 6 6
//
//	int arr[] = { 1, 2, 3, 4 };
//	v2.assign(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	printFor(v2);//1 2 3 4
//
//	v2.pop_back();//βɾ
//	printFor(v2);//1 2 3
//	v2.pop_back();
//	printFor(v2);//1 2 
//
//	/*iterator insert (iterator position, const value_type& val);
//    void insert (iterator position, size_type n, const value_type& val);
//	template <class InputIterator>
//    void insert (iterator position, InputIterator first, InputIterator last);*/
//	v2.insert(v2.begin(), 0);//�൱��ͷ��
//	printFor(v2);//0 1 2
//	v2.insert(v2.end(), 1);//�൱��β��
//	printFor(v2);//0 1 2 1
//	v2.insert(v2.begin() + 2, 55);
//	printFor(v2);//0 1 55 2 1 
//	v2.insert(v2.end() - 2, 66);
//	printFor(v2);//0 1 55 66 2 1
//	v2.insert(v2.end() - 3, v.begin(), v.end());
//	printFor(v2);//��v��Ԫ�ز�����v2�У�0 1 55 6 6 6 66 2 1
//	v2.insert(v2.end(), 5, -1);
//	printFor(v2);//��v2ĩβ����5��-1��0 1 55 6 6 6 66 2 1 -1 -1 -1 -1 -1
//
//	/*iterator erase (iterator position);ɾ������λ�õ�
//	iterator erase (iterator first, iterator last);ɾ��ĳ�������*/
//	v2.erase(v2.begin());
//	printFor(v2);//1 55 6 6 6 66 2 1 -1 -1 -1 -1 -1
//	v2.erase(++v2.begin(), v2.end() - 5);
//	printFor(v2);//1 -1 -1 -1 -1 -1
//
//	/*Construct and insert element�����ȹ����ٲ���
//	template <class... Args>
//	iterator emplace (const_iterator position, Args&&... args);*/
//
//	v.emplace(v.begin(), 0);//����λ����0
//	printFor(v);//0 6 6 6
//
//}

/*emplace , swap , clear*/
//void test()
//{
//	/*std::vector::emplace
//template <class... Args>
//iterator emplace (const_iterator position, Args&&... args);
//Construct and insert element*/
//	vector<A2> v;
//	A2 a1(1, 1, '2');
//	v.insert(v.begin(), a1);
//	v.emplace(v.begin(), a1);
//
//	v.emplace(v.end(), 2, 2, 2);//�ִ������µĹ��캯������insert������
//	//v.insert(v.end(), 3, 3, 3);//����䱨��
//
//	vector<A2> v2;
//	cout << v.size() << " " << v.capacity() << endl;//3 3
//	cout << v2.size() << " " << v2.capacity() << endl;// 0 0
//	v2.swap(v);//�������ݲ��Ǹ�������
//	cout << v.size() << " " << v.capacity() << endl;//0 0
//	cout << v2.size() << " " << v2.capacity() << endl;// 3 3
//	v.clear();
//	cout << v.size() << " " << v.capacity() << endl;//0 0
//	cout << v2.size() << " " << v2.capacity() << endl;//3 3
//}

//void test()
//{
//	/* */
//	/*resize��reserve���ܶ���ʹ������ʧЧ*/
//	vector<int> v(3, 0);
//	cout << v.size() << " " << v.capacity() << endl;//3 3
//	vector<int>::iterator it = v.begin();
//	cout << *it << endl;//0
//	v.resize(30, 1);//�����޸����е�ֵ����δ��ֵ�ĵط������丳ֵ�������б��е�ֵ��
//	//cout << *it << endl;//������ʧЧ�������������ã���Ϊ���������Ѿ������仯��ԭ�ռ��Ѿ����ͷţ���itָ��ԭ�ռ䣬�Ӷ�������ʧЧ���Ҳ����ض���it������ᱨ��
//	//�������»�ȡ
//	it = v.begin();
//	cout << *it << endl;//0
//	it = v.erase(it);//ɾ��beginλ�õ�ֵ���Զ���begin�ָ���it�������ַ������ʺ���end
//	cout << *it << endl;//0
//	it = v.erase(it);
//	cout << *it << endl;//0
//	it = v.erase(it);
//	cout << *it << endl;//1
//	it = v.erase(--v.end());//end��û��ֵ,�ᱨ��
//	cout << *it << endl;
//
//	//vector<int>::iterator it2 = v.begin();
//	//cout << *it2 << endl;//0
//	//printFor(v);
//	//cout << v.size() << " " << v.capacity() << endl;// 30 30
//
//	//v.reserve(40);
//	//cout << v.size() << " " << v.capacity() << endl;// 30 40
//	////cout << *it2 << endl;//������ʧЧ�������������ã���Ϊ���������Ѿ������仯��ԭ�ռ��Ѿ����ͷţ���itָ��ԭ�ռ䣬�Ӷ�������ʧЧ
//	//it2 = v.begin();//���»�ȡ
//	//cout << *it2 << endl;//0
//}
// 

//void test()
//{
//	vector<int> v;
//	v.push_back(1);//β��
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	printFor(v);//1 2 3 4
//
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//			it = v.erase(it);//��PJ�汾�ᷢ����λ����Ϊɾ��һ�λ�������һλ,�˴���Ҫ���»�ȡ��������ͬʱ��������������Ҫit++,����������Ҫit++
//		else
//			it++;
//		printFor(v);//1 3 4 -- 1 3
//	}
//}

//#include<string>
//void test()
//{
//	string str("123");
//	auto& it = str.begin();
//	cout << *it << endl;
//	str.reserve(100);
//	//cout << *it << endl;//������ʧЧ��itָ���λ��ʧЧ���������¸�ֵ
//	it = str.begin();
//	cout << *it << endl;
//}

/*136. ֻ����һ�ε�����
����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬
����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
�磺����: [2,2,1]
	���: 1*/
//class Solution {
//public:
//	int singleNumber(vector<int>& nums) {
//		int value = 0;
//		for (const auto&e : nums)
//		{
//			value ^= e;
//		}
//		return value;
//	}
//};

/*118. �������
����һ���Ǹ����� numRows������������ǵ�ǰ numRows �С�
�磺����: 5
���:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
//class Solution {
//public:
//	vector<vector<int>> generate(int numRows) {
//		//��������
//		vector<vector<int>> mat(numRows);
//		//��������
//		for (int i = 0; i < numRows; ++i)
//		{
//			mat[i].resize(i + 1);//ÿ�ж���i+1��
//		}
//		for (int i = 0; i < numRows; ++i)//����
//		{
//			//��һ�к����һ�ж�Ϊ1
//			mat[i][0] = mat[i][i] = 1;
//			for (int j = 1; j < i; j++)//������j<i ��Ϊ����һ�����м��ֵ��j��1��ʼ ��Ϊ��ʹ�䲻���㵽���һλ��ֻ�ǵ����ʼ�����һλ
//			{
//				mat[i][j] = mat[i - 1][j] + mat[i - 1][j - 1];
//			}
//		}
//		return mat;
//	}
//};



int main()
{
	test();
	system("pause");
	return 0;
}