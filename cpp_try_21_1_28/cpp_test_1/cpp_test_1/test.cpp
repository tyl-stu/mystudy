#include<iostream>
using namespace std;

//�����ռ䣺 namespace + �����ռ����� {����������}
namespace N1  //�����ռ����Ƕ��
{
	int a=20;
	void fun1()
	{
		printf("N1:fun1()\n");
	}

	//Ƕ��
	namespace N2
	{
		int a=30;
		void fun1()
		{
			printf("N1:N2:fun1()\n");
		}
	}
}

// �ֶζ���
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
	//�����ռ������ʽ��1�������ռ�::��Ա
	//δͨ��ʹ��using�����չ�������ռ�֮ǰ����Ҫ��������������ܷ��ʵ���Ա
	N1::N2::fun1();
	printf("a = %d\n", a);
	cin >> a ;
	cout << a << "hahhahh" << endl;
	printf("a = %d\n", a);
	printf("N1::a = %d\n", N1::a);
	printf("N1::N2::a = %d\n", N1::N2::a);

	//2��using �����ռ�::��Ա
	using N1::a;
	printf("a = %d\n", a);

	//3��using namespace �����ռ� �п��ܻᷢ���ض���
	//�����ռ��µ����г�Աȫ����¶��ȫ���������У����ȫ�����еĳ�Ա��������
	using namespace N1;
	printf("N1::a = %d\n", a);

	system("pause");
	return 0;
}