#include<iostream>
using namespace std;
#include<queue>
#include<functional>
#include<vector>
#include<deque>
#include<list>

/* 自定义类型数据在优先序列中的使用 */
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
//		return _a < a._a; // 大堆
//	}
//	int _a;
//};
//
//void test()
//{
//	//优先级队列存放自定义类型：需要自定义类型支持比较的操作
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
//	//队列是先进先出，栈是先进后出
//	//默认大堆实现，堆底是最大值
//	priority_queue<int> pq;
//	pq.push(110);
//	pq.push(70);
//	pq.push(100);
//	pq.push(50);
//	pq.push(0);
//	cout << pq.size() << endl;
//	cout << "大堆显示：";
//	while (!pq.empty())
//	{
//		cout << pq.top() << " ";
//		pq.pop();
//	}cout << endl;//递减显示 
//	cout << pq.size() << endl;
//
//	//小堆结构，即堆底为最小值
//	priority_queue<int, vector<int>, greater<int>> pq2;
//	pq2.push(110);
//	pq2.push(70);
//	pq2.push(100);
//	pq2.push(50);
//	pq2.push(0);
//	cout << pq2.size() << endl;
//	cout << "小堆显示：";
//	while (!pq2.empty())
//	{
//		cout << pq2.top() << " ";
//		pq2.pop();
//	}cout << endl;//递减显示 
//	cout << pq2.size() << endl;
//}

/* 模拟实现优先队列 priority_queue */
//template<class T>
//class PriorityQueue
//{
//public:
//	//堆：
//	//向下调整，大堆
//	void shiftDown()
//	{
//		int parent = 0;
//		int child = 2 * parent + 1;
//		while (child < arr.size())
//		{
//			if (child + 1 < arr.size())
//			{
//				if (arr[child] < arr[child + 1]) //找出根下较大的子节点,方便后续父子节点交换
//					child++;
//				/*else  //该部分程序可有可无
//				{
//					swap(arr[child], arr[child + 1]);
//					child++;
//				}*/
//			}
//				
//			if (arr[parent] < arr[child])
//			{
//				swap(arr[parent], arr[child]);//父子节点交换
//				parent = child;
//				child = 2 * parent + 1;
//			}
//			else
//				break;
//		}
//	}
//	//向上调整
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
//		//尾插
//		//arr[arr.size()] = val;//会越界
//		arr.push_back(val);
//		//向上调整
//		shiftUp(arr.size() - 1);
//	}
//
//	void pop()
//	{
//		//交换,因为 vector 没有头删函数，所以此处先将arr中头尾元素交换，然后利用尾删函数，再调用向下调整，为arr重新排序
//		swap(arr[0], arr[arr.size() - 1]);
//		//尾删
//		arr.pop_back();
//		//向下调整
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
//	//队列是先进先出，栈是先进后出
//	//默认大堆实现，堆底是最大值
//	PriorityQueue<int> pq;
//	pq.push(0);
//	pq.push(10);
//	pq.push(70);
//	pq.push(100);
//	pq.push(150);
//	cout << pq.size() << endl;
//	cout << "大堆显示：";
//	while (!pq.empty())
//	{
//		cout << pq.top() << " ";
//		pq.pop();
//	}cout << endl;//递减显示 
//	cout << pq.size() << endl;
//}

/* 利用 deque 及其他容器，如vector,list 模拟实现 stack*/
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
//	//Stack<int> st; // 默认是deque
//	//Stack<int, vector<int>> st; // 自己设置容器是vector
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

/* 利用 deque 及其他容器，如list 模拟实现 queue*/
/* 不能用 vector 实现，因为其没有 pop_front 或 push_front */
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
//	//Queue<int, vector<int>> q;//会报错，因为vecto 无pop_front
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

/* 利用 vector 及其他容器，如deque 模拟实现 priority_queue */
/* 不能用 list 实现，因为不支持随机访问 */
/* empty,size,back,push_back,pop_back */
//仿函数类：重载"()"运算符 
template<class T>
struct Greater  //实现大堆
{
	bool operator()(const T& x,const T& y) const
	{
		return x > y;
	}
};

template<class T>
struct Less  //实现小堆
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
	//堆：
	//向下调整，大堆
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
				swap(arr[parent], arr[child]);//父子节点交换
				parent = child;
				child = 2 * parent + 1;
			}
			else
				break;
		}
	}
	//向上调整
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
		//尾插
		//arr[arr.size()] = val;//会越界
		arr.push_back(val);
		//向上调整
		shiftUp(arr.size() - 1);
	}

	void pop()
	{
		//交换,因为 vector 没有头删函数，所以此处先将arr中头尾元素交换，然后利用尾删函数，再调用向下调整，为arr重新排序
		swap(arr[0], arr[arr.size() - 1]);
		//尾删
		arr.pop_back();
		//向下调整
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
	//队列是先进先出，栈是先进后出
	//默认大堆实现，堆底是最大值
	//PriorityQueue<int,vector<int>,Less<int>> pq;
	PriorityQueue<int, vector<int>, Greater<int>> pq;
	pq.push(10);
	pq.push(2);
	pq.push(13);
	pq.push(9);
	//pq.push(150);
	cout << pq.size() << endl;
	cout << "大堆显示：";
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}cout << endl;//递减显示 
	cout << pq.size() << endl;
}

 
int main()
{
	test();
	system("pause");
	return 0;
}