#include<iostream>
using namespace std;

//class A
//{
//public:
//	A(int a , int b = 10)
//	{
//		cout << a + b << endl;
//	}
//};
//
//void test()
//{
//	A a1(50);
//	A a2(0, 0);
//
//}

//void test()
//{
//	int *p1 = (int *)operator new(sizeof(int));
//	int *p2 = (int *)malloc(sizeof(int));
//	int *p3 = (int *)operator new[](sizeof(int));
//
//	cout << *p1 << endl << *p2 << endl << *p3 << endl;
//	operator delete(p1);
//	free(p2);
//	operator delete[](p3);
//}

//struct ListNode
//{
//public:
//	void *operator new(size_t n)
//	{
//		cout << "operator new" << endl;
//		//�����ڴ�صķ�ʽ
//		allocator<ListNode> alloc;
//		cout << "memory pool allocate" << endl;
//		return alloc.allocate(1);
//		/*cout << "memory pool allocate" << endl;*/
//	}
//
//	void operator delete(void *ptr)
//	{
//		cout << "operator delete" << endl;
//		allocator<ListNode> alloc;
//		alloc.deallocate((ListNode*)ptr, 1);
//		cout << "memory pool deallocate" << endl;
//	}
//
//	ListNode(int data = 1)
//		:_data(data)//��ʼ���б�
//	{
//		cout << "ListNode(int)" << endl;
//	}
//	~ListNode()
//	{
//		cout << "~ListNode" << endl;
//	}
//
//private:
//	int _data = 0;
//	ListNode * _next = nullptr;
//};
//void test()
//{
//	ListNode* node = new ListNode;//�ȵ� operator new���ٵ����캯��
//	delete node;//�ȵ��������ٵ� operator delete
//}

//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{
//		cout << "A(int)" << "  _a = " << _a << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//void test()
//{
//	A *pa = (A*)malloc(sizeof(A));
//	//��ʼ�����еĿռ�
//	// new ��λ���ʽ��new (ָ��) ����(�����б�(��ѡ))  --> ��ʽ���ù��캯��
//	new (pa) A(10);//�����A��Ĺ��캯��û�в���ʱ���˴�����Ҫ����
//	pa->~A();//�ȵ������������ͷţ���Ȼ���ܻ��пռ�й¶
//	free(pa);
//}

//void test()
//{
//	void* p = new char[0xfffffffful]; //x32ƽ̨���벻��4G�ڴ棬��x64���� 
//	char *p2 = (char *)malloc(0xfffffffful);
//	cout << "new:" << p << endl;
//	cout << "malloc:" << p2 << endl;
//}

//template <typename T>
//void Swap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//void test()
//{
//	int a = 1, b = 2;
//	char d = 'm', e = 'n';
//	double f = 1.2, g = 2.5;
//	Swap(a, b); cout << a << "   " << b << endl;
//	Swap(d, e); cout << d << "   " << e << endl;
//	Swap(f, g); cout << f << "   " << g << endl;
//	cout << "    " << endl;
//}

template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}
void test()
{
	int a = 10;
	double b = 20.0;
	char c = 'a';
	// ��ʽʵ����

	cout << Add<int>(a, c);
}


int main()
{
	test();
	system("pause");
	return 0;
}