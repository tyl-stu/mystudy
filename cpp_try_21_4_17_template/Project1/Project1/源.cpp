#include<iostream>
using namespace std;
#include<array>
#include"try.h"

////template<class T,float num>//"double" 类型的实参与 "float" 类型的模板形参不兼容
//template<class T, int num>
//struct A
//{
//
//};
//
//template<class T, char ch>
//struct B
//{
//
//};
//
//void test()
//{
//	//array<T,size_t>: size_t --> 非类型模板参数
//	//非类型模板参数只能是整数类型，不能给浮点数或自定义类型数据
//	array<int, 10> arr;//当前的静态数组中只能保存10个数据，空间是在栈上申请，如果申请空间太大，会影响内存，比较危险
//
//	//A<int, 2.3> a;//非类型模板参数只能是整数类型，不能给浮点数或自定义类型数据
//	A<int, 2> a;
//
//	B<int, 'a'> b;
//}

/* 模板的特化
   前提：已有一个通用的模板,且函数名称要一致*/
//template<class T>
//bool isEqual(T a, T b)
//{
//	return a == b;
//}
//
////template<>
////bool isEqual<char*>(char *a, char *b)
////{
////	//strcmp(a, b) -- a,b相等时该函数会返回0
////	return strcmp(a, b) == 0;
////}
//
////建议对于特殊类型，直接写普通函数
//bool isEqual(char *a, char *b)//直接通过普通函数实现想要实现的功能
//{
//	//strcmp(a, b) -- a,b相等时该函数会返回0
//	return strcmp(a, b) == 0;
//}
//
//void test()
//{
//	bool ret = isEqual(1, 2);
//	cout << ret << endl;
//	ret = isEqual(2.1, 2.1);
//	cout << ret << endl;
//	ret = isEqual("123","123");
//	cout << ret << endl;
//	char *ptr = "123";
//	char ptr2[] = "123";
//	ret = isEqual(ptr,ptr2);//比较的是地址，模板特化后，该语句返回为真
//	cout << ret << endl;
//	ret = isEqual(*ptr, *ptr2);//比较的是地址指向的内容
//	cout << ret << endl;
//}

/* 类模板的特化  应用场景：类型萃取！！！！！
   前提：已有一个通用的模板 */
//template<class T1,class T2>
//struct D
//{
//public:
//	D(const T1& d1, const T2& d2)
//		:_d1(d1)
//		, _d2(d2)
//	{
//		cout << "D(d1,d2)   " << _d1 << "   " << _d2 << endl;
//	}
//	T1 _d1;
//	T2 _d2;
//};
//
////特化: 全特化:所有的类型都是具体类型
//template<>
//struct D<char,double>
//{
//public:
//	D(const char& d1, const double& d2)
//		:_d1(d1)
//		, _d2(d2)
//	{
//		cout << "D(d1,d2)   " << _d1 << "   " << _d2 << endl;
//	}
//	char _d1;
//	double _d2;
//};
//
////偏特化：1、只特化部分类型
//template<class T1>
//struct D<double, T1>
//{
//public:
//	D(const double& d2, const T1& d1)
//		:_d1(d1)
//		, _d2(d2)
//	{
//		cout << "D(d1,d2)   " << _d1 << "   " << _d2 << endl;
//	}
//	T1 _d1;
//	double _d2;
//};
//
////偏特化：2、给模板参数做进一步的限制
//template<class T1,class T2>
//struct D < T1*, T2* >
//{
//public:
//	D(const T1& d1, const T2& d2)
//		:_d1(d1)
//		, _d2(d2)
//	{
//		cout << "D(T1*,T2*)   " << _d1 << "   " << _d2 << endl;
//	}
//	T1 _d1;
//	T2 _d2;
//};
//
//void test()
//{
//	D<int, int> d(1, 1);//通用模板的实例化
//	D<char, double> d2('a', 3.1);//全特化模板实例化  3.1 -- double类型，非float类型
//	D<double, int> d3(5, 5.5);//偏特化模板实例化, T1 可随处放，没有先左后右的原则
//	D<int*, int*> d4(2, 2);//偏特化模板实例化
//}

void test()
{
	cout << ADD(1.1, 2.4) << endl;
	cout << ADD2(1, 2) << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}