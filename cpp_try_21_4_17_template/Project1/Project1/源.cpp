#include<iostream>
using namespace std;
#include<array>
#include"try.h"

////template<class T,float num>//"double" ���͵�ʵ���� "float" ���͵�ģ���ββ�����
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
//	//array<T,size_t>: size_t --> ������ģ�����
//	//������ģ�����ֻ�����������ͣ����ܸ����������Զ�����������
//	array<int, 10> arr;//��ǰ�ľ�̬������ֻ�ܱ���10�����ݣ��ռ�����ջ�����룬�������ռ�̫�󣬻�Ӱ���ڴ棬�Ƚ�Σ��
//
//	//A<int, 2.3> a;//������ģ�����ֻ�����������ͣ����ܸ����������Զ�����������
//	A<int, 2> a;
//
//	B<int, 'a'> b;
//}

/* ģ����ػ�
   ǰ�᣺����һ��ͨ�õ�ģ��,�Һ�������Ҫһ��*/
//template<class T>
//bool isEqual(T a, T b)
//{
//	return a == b;
//}
//
////template<>
////bool isEqual<char*>(char *a, char *b)
////{
////	//strcmp(a, b) -- a,b���ʱ�ú����᷵��0
////	return strcmp(a, b) == 0;
////}
//
////��������������ͣ�ֱ��д��ͨ����
//bool isEqual(char *a, char *b)//ֱ��ͨ����ͨ����ʵ����Ҫʵ�ֵĹ���
//{
//	//strcmp(a, b) -- a,b���ʱ�ú����᷵��0
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
//	ret = isEqual(ptr,ptr2);//�Ƚϵ��ǵ�ַ��ģ���ػ��󣬸���䷵��Ϊ��
//	cout << ret << endl;
//	ret = isEqual(*ptr, *ptr2);//�Ƚϵ��ǵ�ַָ�������
//	cout << ret << endl;
//}

/* ��ģ����ػ�  Ӧ�ó�����������ȡ����������
   ǰ�᣺����һ��ͨ�õ�ģ�� */
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
////�ػ�: ȫ�ػ�:���е����Ͷ��Ǿ�������
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
////ƫ�ػ���1��ֻ�ػ���������
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
////ƫ�ػ���2����ģ���������һ��������
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
//	D<int, int> d(1, 1);//ͨ��ģ���ʵ����
//	D<char, double> d2('a', 3.1);//ȫ�ػ�ģ��ʵ����  3.1 -- double���ͣ���float����
//	D<double, int> d3(5, 5.5);//ƫ�ػ�ģ��ʵ����, T1 ���洦�ţ�û��������ҵ�ԭ��
//	D<int*, int*> d4(2, 2);//ƫ�ػ�ģ��ʵ����
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