#include<iostream>
using namespace std;
#include<vector>

//template <class T>
//void printIterator(const vector<T>& vec);//正向打印
//
//template <class T>
//void printReverIterator(const vector<T>& vec);//反向打印
//
//template < class T >
//void printFor(const vector<T>& vec);//范围for
//
//template < class T >
//void printFor2(const vector<T>& vec);//范围for
//
//class A
//{};

//void test()
//{
//	/*创建vector*/
//	//用模板实现类，默认构造
//	vector<int> v1; //存储int型数据的序列库，默认给的0
//	vector<char> v2;//默认给的 '\0'
//	vector<A> v3;//存储自定义类型
//
//	vector<A> v4(10);//创建的vector中包含10个A的对象，其的默认值为A的默认值
//	A a;//a为非匿名的对象
//	//vector(n,自定义类型的默认构造())
//	vector<A> v5(20, A());
//	vector<A> v6(20, a);
//
//	//vector(n,内置类型的类0值)
//	//数字：0
//	//字符：\0
//	//指针：nullptr
//	vector<int> v7(10);//默认给了10个0
//	vector<char> v8(10);//默认给了10个'\0'
//	printIterator(v7);
//	printIterator(v8);//因为其元素默认为'\0'，所以打印出来后，没有什么显示 
//
//	//迭代器的初始化
//	char arr[] = "12345678";
//	vector<char> v10(arr, arr + sizeof(arr) / sizeof(arr[0])-1);
//	printIterator(v10);
//	printReverIterator(v10);
//	printFor(v10);
//
//	for(size_t i = 0; i < v10.size(); ++i)
//	{
//		v10.operator[](i) = 'c';//[] 的完整形式
//		v10[i] = 'x';
//	}
//	printFor2(v10);
//
//	//[]越界：debug版本会有assert错误，release版本不会检查错误
//	//v10[100] = 'c';
//	//at越界：上述两种方式都会抛异常
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
void printIterator(const vector<T>& vec)//可打印vector的元素，只读形式
{
	//vector<T>::iterator it = vec.begin();//该语句会报错，因为函数参数列表中调用的是const，所以此处应该使用const_iterator，即const迭代器
	vector<T>::const_iterator it = vec.begin();
	while (it != vec.end())
	{
		cout << *it << " ";
		it++;
	}cout << endl;
}

template <class T>
void printReverIterator(const vector<T>& vec)//可打印vector的元素，只读形式
{
	//vector<T>::reverse_iterator it = vec.begin();//该语句会报错，因为函数参数列表中调用的是const，所以此处应该使用const_iterator，即const迭代器
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

struct A  // 4 +4 +4（字节对齐）+4=16byte
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
	vector<A2> v;//不能用构造然后直接显示
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
//	cout << v1.max_size() << endl;//4294967295  char - 1byte ,寻址范围4G ,则最多有4G个
//	cout << v2.max_size() << endl;//1073741823  char* - 指针，4byte ,最多有1G个
//	cout << v3.max_size() << endl;//1073741823  int - 4byte,最多有1G个
//	cout << v4.max_size() << endl;//268435455   A - 16byte,最多有1G/4个
//
//	//void resize (size_type n, value_type val = value_type());
//	printFor(v1);
//	v1.resize(10);
//	printFor(v1);
//	v1.resize(15, 'a');//不会修改已有的值，在未有值的地方，给其赋初值（参数列表中的值）
//	//v1.resize(n,T()) n大于容量则会影响容量
//	v1.resize(100, 'b');
//	printFor(v1);
//	//printFor(v4);//不能打印，除非重载运算符
//	v4.resize(10);
//
//	cout<< v1.size() << " " << v1.capacity() << endl;
//	v1.reserve(50);//reserve() -- 只增容，不影响数量size
//	cout << v1.size() << " " << v1.capacity() << endl;
//	v1.reserve(200);
//	cout << v1.size() << " " << v1.capacity() << endl;
//}

/*增容*/
//void test()
//{
//	vector<int> v;
//	//PJ中vector增容规则：约1.5倍
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

/*void shrink_to_fit(); 减小容量*/
//void test()
//{
//	//shrink_to_fit() - 将容量capacity缩小至size
//	vector<int> v;
//	cout << v.size() << " " << v.capacity() << endl;//0 0
//
//	v.resize(10);//更改size
//	v.reserve(30);//更改capacity
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

/*  改变内容，并不是插入
template <class InputIterator>
  void assign (InputIterator first, InputIterator last);	
void assign (size_type n, const value_type& val);*/
//void test()
//{
//	vector<int> v(3, 2);//3个2
//	printFor(v);//2 2 2
//	//赋值
//	v.assign(5, 1);
//	printFor(v);//1 1 1 1 1
//
//	vector<int> v2(3, 6);//3个6
//	v.assign(v2.begin(), v2.end());
//	printFor(v2);//6 6 6
//
//	int arr[] = { 1, 2, 3, 4 };
//	v2.assign(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	printFor(v2);//1 2 3 4
//
//	v2.pop_back();//尾删
//	printFor(v2);//1 2 3
//	v2.pop_back();
//	printFor(v2);//1 2 
//
//	/*iterator insert (iterator position, const value_type& val);
//    void insert (iterator position, size_type n, const value_type& val);
//	template <class InputIterator>
//    void insert (iterator position, InputIterator first, InputIterator last);*/
//	v2.insert(v2.begin(), 0);//相当于头插
//	printFor(v2);//0 1 2
//	v2.insert(v2.end(), 1);//相当于尾插
//	printFor(v2);//0 1 2 1
//	v2.insert(v2.begin() + 2, 55);
//	printFor(v2);//0 1 55 2 1 
//	v2.insert(v2.end() - 2, 66);
//	printFor(v2);//0 1 55 66 2 1
//	v2.insert(v2.end() - 3, v.begin(), v.end());
//	printFor(v2);//将v中元素插入至v2中，0 1 55 6 6 6 66 2 1
//	v2.insert(v2.end(), 5, -1);
//	printFor(v2);//给v2末尾插入5个-1，0 1 55 6 6 6 66 2 1 -1 -1 -1 -1 -1
//
//	/*iterator erase (iterator position);删除具体位置的
//	iterator erase (iterator first, iterator last);删除某个区间的*/
//	v2.erase(v2.begin());
//	printFor(v2);//1 55 6 6 6 66 2 1 -1 -1 -1 -1 -1
//	v2.erase(++v2.begin(), v2.end() - 5);
//	printFor(v2);//1 -1 -1 -1 -1 -1
//
//	/*Construct and insert element可以先构造再插入
//	template <class... Args>
//	iterator emplace (const_iterator position, Args&&... args);*/
//
//	v.emplace(v.begin(), 0);//在首位插入0
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
//	v.emplace(v.end(), 2, 2, 2);//又传入了新的构造函数，但insert不可以
//	//v.insert(v.end(), 3, 3, 3);//该语句报错
//
//	vector<A2> v2;
//	cout << v.size() << " " << v.capacity() << endl;//3 3
//	cout << v2.size() << " " << v2.capacity() << endl;// 0 0
//	v2.swap(v);//交换内容不是复制内容
//	cout << v.size() << " " << v.capacity() << endl;//0 0
//	cout << v2.size() << " " << v2.capacity() << endl;// 3 3
//	v.clear();
//	cout << v.size() << " " << v.capacity() << endl;//0 0
//	cout << v2.size() << " " << v2.capacity() << endl;//3 3
//}

//void test()
//{
//	/* */
//	/*resize、reserve可能都会使迭代器失效*/
//	vector<int> v(3, 0);
//	cout << v.size() << " " << v.capacity() << endl;//3 3
//	vector<int>::iterator it = v.begin();
//	cout << *it << endl;//0
//	v.resize(30, 1);//不会修改已有的值，在未有值的地方，给其赋值（参数列表中的值）
//	//cout << *it << endl;//迭代器失效，不能做解引用，因为现在容量已经发生变化，原空间已经被释放，而it指向原空间，从而迭代器失效，且不能重定义it，否则会报错
//	//除非重新获取
//	it = v.begin();
//	cout << *it << endl;//0
//	it = v.erase(it);//删除begin位置的值后自动将begin又赋给it，但该种方法不适合于end
//	cout << *it << endl;//0
//	it = v.erase(it);
//	cout << *it << endl;//0
//	it = v.erase(it);
//	cout << *it << endl;//1
//	it = v.erase(--v.end());//end处没有值,会报错
//	cout << *it << endl;
//
//	//vector<int>::iterator it2 = v.begin();
//	//cout << *it2 << endl;//0
//	//printFor(v);
//	//cout << v.size() << " " << v.capacity() << endl;// 30 30
//
//	//v.reserve(40);
//	//cout << v.size() << " " << v.capacity() << endl;// 30 40
//	////cout << *it2 << endl;//迭代器失效，不能做解引用，因为现在容量已经发生变化，原空间已经被释放，而it指向原空间，从而迭代器失效
//	//it2 = v.begin();//重新获取
//	//cout << *it2 << endl;//0
//}
// 

//void test()
//{
//	vector<int> v;
//	v.push_back(1);//尾插
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	printFor(v);//1 2 3 4
//
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//			it = v.erase(it);//在PJ版本会发生错位，因为删除一次会往后走一位,此处需要重新获取迭代器，同时若满足条件不需要it++,不满足则需要it++
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
//	//cout << *it << endl;//迭代器失效，it指向的位置失效，除非重新赋值
//	it = str.begin();
//	cout << *it << endl;
//}

/*136. 只出现一次的数字
给定一个非空整数数组，除了某个元素只出现一次以外，
其余每个元素均出现两次。找出那个只出现了一次的元素。
如：输入: [2,2,1]
	输出: 1*/
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

/*118. 杨辉三角
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
如：输入: 5
输出:
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
//		//创建行数
//		vector<vector<int>> mat(numRows);
//		//创建列数
//		for (int i = 0; i < numRows; ++i)
//		{
//			mat[i].resize(i + 1);//每行都有i+1列
//		}
//		for (int i = 0; i < numRows; ++i)//行数
//		{
//			//第一列和最后一列都为1
//			mat[i][0] = mat[i][i] = 1;
//			for (int j = 1; j < i; j++)//列数，j<i 是为了算一行中中间的值；j从1开始 是为了使其不会算到最后一位，只是调用最开始或最后一位
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