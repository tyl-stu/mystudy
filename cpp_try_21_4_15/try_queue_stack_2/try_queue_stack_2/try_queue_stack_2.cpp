#include<iostream>
using namespace std;
#include<queue>
#include<functional>
#include<vector>
#include<deque>
#include<list>

/* �Զ����������������������е�ʹ�� */
//class A
//{
//public:
//	A(int a = 1)
//		:_a(a)
//	{
//
//	}
//	bool operator<(const A& a) const
//	{
//		return _a < a._a; // ���
//	}
//	int _a;
//};
//
//void test()
//{
//	//���ȼ����д���Զ������ͣ���Ҫ�Զ�������֧�ֱȽϵĲ���
//	priority_queue<A> pq;
//	pq.push(A(1));
//	pq.push(A(10));
//	pq.push(A(5));
//	pq.push(A(20));
//	pq.push(A(4));
//	while (!pq.empty())
//	{
//		cout << pq.top()._a << " ";
//		pq.pop();
//	}cout << endl;
//}

//void test()
//{
//	//�������Ƚ��ȳ���ջ���Ƚ����
//	//Ĭ�ϴ��ʵ�֣��ѵ������ֵ
//	priority_queue<int> pq;
//	pq.push(110);
//	pq.push(70);
//	pq.push(100);
//	pq.push(50);
//	pq.push(0);
//	cout << pq.size() << endl;
//	cout << "�����ʾ��";
//	while (!pq.empty())
//	{
//		cout << pq.top() << " ";
//		pq.pop();
//	}cout << endl;//�ݼ���ʾ 
//	cout << pq.size() << endl;
//
//	//С�ѽṹ�����ѵ�Ϊ��Сֵ
//	priority_queue<int, vector<int>, greater<int>> pq2;
//	pq2.push(110);
//	pq2.push(70);
//	pq2.push(100);
//	pq2.push(50);
//	pq2.push(0);
//	cout << pq2.size() << endl;
//	cout << "С����ʾ��";
//	while (!pq2.empty())
//	{
//		cout << pq2.top() << " ";
//		pq2.pop();
//	}cout << endl;//�ݼ���ʾ 
//	cout << pq2.size() << endl;
//}

/* ģ��ʵ�����ȶ��� priority_queue */
//template<class T>
//class PriorityQueue
//{
//public:
//	//�ѣ�
//	//���µ��������
//	void shiftDown()
//	{
//		int parent = 0;
//		int child = 2 * parent + 1;
//		while (child < arr.size())
//		{
//			if (child + 1 < arr.size())
//			{
//				if (arr[child] < arr[child + 1]) //�ҳ����½ϴ���ӽڵ�,����������ӽڵ㽻��
//					child++;
//				/*else  //�ò��ֳ�����п���
//				{
//					swap(arr[child], arr[child + 1]);
//					child++;
//				}*/
//			}
//				
//			if (arr[parent] < arr[child])
//			{
//				swap(arr[parent], arr[child]);//���ӽڵ㽻��
//				parent = child;
//				child = 2 * parent + 1;
//			}
//			else
//				break;
//		}
//	}
//	//���ϵ���
//	void shiftUp(int child)
//	{
//		int parent = (child - 1) / 2;
//		while (child > 0) 
//		{
//			if (arr[parent] < arr[child])
//			{
//				swap(arr[parent], arr[child]);
//				child = parent;
//				parent = (child - 1) / 2;
//			}
//			else
//				break;
//		}
//	}
//
//	void push(const T& val)
//	{
//		//β��
//		//arr[arr.size()] = val;//��Խ��
//		arr.push_back(val);
//		//���ϵ���
//		shiftUp(arr.size() - 1);
//	}
//
//	void pop()
//	{
//		//����,��Ϊ vector û��ͷɾ���������Դ˴��Ƚ�arr��ͷβԪ�ؽ�����Ȼ������βɾ�������ٵ������µ�����Ϊarr��������
//		swap(arr[0], arr[arr.size() - 1]);
//		//βɾ
//		arr.pop_back();
//		//���µ���
//		shiftDown();
//	}
//
//	T& top()
//	{
//		return arr.front();
//	}
//
//	size_t size() const
//	{
//		return arr.size();
//	}
//
//	bool empty() const
//	{
//		return arr.empty();
//	}
//private:
//	vector<int> arr;
//};
//
//void test()
//{
//	//�������Ƚ��ȳ���ջ���Ƚ����
//	//Ĭ�ϴ��ʵ�֣��ѵ������ֵ
//	PriorityQueue<int> pq;
//	pq.push(0);
//	pq.push(10);
//	pq.push(70);
//	pq.push(100);
//	pq.push(150);
//	cout << pq.size() << endl;
//	cout << "�����ʾ��";
//	while (!pq.empty())
//	{
//		cout << pq.top() << " ";
//		pq.pop();
//	}cout << endl;//�ݼ���ʾ 
//	cout << pq.size() << endl;
//}

/* ���� deque ��������������vector,list ģ��ʵ�� stack*/
/* empty,size,back,push_back,pop_back */
//template<class T,class Container = deque<T>>
//class Stack
//{
//	//empty,size,back,push_back,pop_back
//public:
//	void push(const T& val)
//	{
//		_c.push_back(val);
//	}
//	void pop()
//	{
//		_c.pop_back();
//	}
//	T& top()
//	{
//		return _c.back();
//	}
//	size_t size() const
//	{
//		return _c.size();
//	}
//	bool empty() const
//	{
//		return _c.empty();
//	}
//private:
//	Container _c;
//};
//
//void test()
//{
//	//Stack<int> st; // Ĭ����deque
//	//Stack<int, vector<int>> st; // �Լ�����������vector
//	Stack<int, list<int>> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(5);
//	st.push(4);
//	st.push(5);
//
//	cout << st.size() << endl;
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
//	}cout << endl;
//	cout << st.size() << endl;
//}

/* ���� deque ��������������list ģ��ʵ�� queue*/
/* ������ vector ʵ�֣���Ϊ��û�� pop_front �� push_front */
/* empty,size,front,back,push_back,pop_front */
//template<class T,class Container = deque<T>>
//class Queue
//{
//public:
//	void push(const T& val)
//	{
//		_c.push_back(val);
//	}
//	void pop()
//	{
//		_c.pop_front();
//	}
//	T& back()
//	{
//		return _c.back();
//	}
//	T& front()
//	{
//		return _c.front();
//	}
//	size_t size() const
//	{
//		return _c.size();
//	}
//	bool empty() const
//	{
//		return _c.empty();
//	}
//private:
//	Container _c;
//};
//
//void test()
//{
//	//Queue<int> q;
//	//Queue<int, vector<int>> q;//�ᱨ����Ϊvecto ��pop_front
//	Queue<int, list<int>> q;
//	q.push(1);
//	q.push(2);
//	q.push(5);
//	q.push(4);
//	q.push(3);
//	cout << q.size() << endl;
//	while (!q.empty())
//	{
//		cout << q.front() << endl;
//		q.pop();
//	}cout << endl;
//	cout << q.size() << endl;
//}

/* ���� vector ��������������deque ģ��ʵ�� priority_queue */
/* ������ list ʵ�֣���Ϊ��֧��������� */
/* empty,size,back,push_back,pop_back */
//�º����ࣺ����"()"����� 
template<class T>
struct Greater  //ʵ�ִ��
{
	bool operator()(const T& x,const T& y) const
	{
		return x > y;
	}
};

template<class T>
struct Less  //ʵ��С��
{
	bool operator()(const T& x, const T& y) const
	{
		return x < y;
	}
};

//template<class T,class Container = vector<T>,class Compare = Greater<T>>
template<class T, class Container, class Compare>
class PriorityQueue
{
public:
	//�ѣ�
	//���µ��������
	void shiftDown()
	{
		int parent = 0;
		int child = 2 * parent + 1;
		while (child < arr.size())
		{
			//if (child + 1 < arr.size() && arr[child] < arr[child + 1])
			if (child + 1 < arr.size() && cmp(arr[child], arr[child + 1]))
				child++;
				
			//if (arr[parent] < arr[child])
			if (cmp(arr[parent], arr[child]))
			{
				swap(arr[parent], arr[child]);//���ӽڵ㽻��
				parent = child;
				child = 2 * parent + 1;
			}
			else
				break;
		}
	}
	//���ϵ���
	void shiftUp(int child)
	{
		int parent = (child - 1) / 2;
		while (child > 0) 
		{
			//if (arr[parent] < arr[child])
			if (cmp(arr[parent], arr[child]))
			{
				swap(arr[parent], arr[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
				break;
		}
	}

	void push(const T& val)
	{
		//β��
		//arr[arr.size()] = val;//��Խ��
		arr.push_back(val);
		//���ϵ���
		shiftUp(arr.size() - 1);
	}

	void pop()
	{
		//����,��Ϊ vector û��ͷɾ���������Դ˴��Ƚ�arr��ͷβԪ�ؽ�����Ȼ������βɾ�������ٵ������µ�����Ϊarr��������
		swap(arr[0], arr[arr.size() - 1]);
		//βɾ
		arr.pop_back();
		//���µ���
		shiftDown();
	}

	T& top()
	{
		return arr.front();
	}

	size_t size() const
	{
		return arr.size();
	}

	bool empty() const
	{
		return arr.empty();
	}
private:
	Container arr;
	Compare cmp;
};

void test()
{
	//�������Ƚ��ȳ���ջ���Ƚ����
	//Ĭ�ϴ��ʵ�֣��ѵ������ֵ
	//PriorityQueue<int,vector<int>,Less<int>> pq;
	PriorityQueue<int, vector<int>, Greater<int>> pq;
	pq.push(10);
	pq.push(2);
	pq.push(13);
	pq.push(9);
	//pq.push(150);
	cout << pq.size() << endl;
	cout << "�����ʾ��";
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}cout << endl;//�ݼ���ʾ 
	cout << pq.size() << endl;
}

 
int main()
{
	test();
	system("pause");
	return 0;
}