#include<iostream>
using namespace std;
#include<array>

template<class T>
bool isEqual(T& a, T& b)
{
	return a == b;
}
template<>
bool isEqual<char*>(char*  &a, char* &b)
{
	return 0 == strcmp(a, b);
}

bool isEqual(char* a, char* b)
{
	return 0 == strcmp(a, b);
}

void test()
{
	int a = 1;
	int b = 1;
	int *pa = &a;
	int *pa2 = &b;
	bool ret = isEqual(a, b); cout << ret << endl;
	ret = isEqual(pa, pa2); cout << ret << endl;//�ȵ���ָ�룬����ָ������

	char *ptr1 = "1234";
	char *ptr2 = "1234";
	ret = isEqual(ptr1, ptr2); cout << ret << endl;
	char ptr3[] = "1234";
	char ptr4[] = "1234";
	ret = isEqual(ptr3, ptr4); cout << ret << endl;//�ȵ���ָ�룬����ָ������
}

//void test()
//{
//	array < int, 20 > a;
//
//}

int main()
{
	test();
	system("pause");
	return 0;
}