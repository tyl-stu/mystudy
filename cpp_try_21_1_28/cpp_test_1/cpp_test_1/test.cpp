#include<iostream>
using namespace std;

//命名空间： namespace + 命名空间名称 {变量，函数}
namespace N1  //命名空间可以嵌套
{
	int a=20;
	void fun1()
	{
		printf("N1:fun1()\n");
	}

	//嵌套
	namespace N2
	{
		int a=30;
		void fun1()
		{
			printf("N1:N2:fun1()\n");
		}
	}
}

// 分段定义
namespace N1
{
	int b;
	void fun2()
	{
		printf("N1:fun2()\n");
	}
	
}
int a = 10;

int main()
{
	//命名空间访问形式：1、命名空间::成员
	//未通过使用using引入或展开命名空间之前，需要加完整作用域才能访问到成员
	N1::N2::fun1();
	printf("a = %d\n", a);
	cin >> a ;
	cout << a << "hahhahh" << endl;
	printf("a = %d\n", a);
	printf("N1::a = %d\n", N1::a);
	printf("N1::N2::a = %d\n", N1::N2::a);

	//2、using 命名空间::成员
	using N1::a;
	printf("a = %d\n", a);

	//3、using namespace 命名空间 有可能会发生重定义
	//命名空间下的所有成员全部暴露在全局作用域中，会和全局域中的成员发生混淆
	using namespace N1;
	printf("N1::a = %d\n", a);

	system("pause");
	return 0;
}