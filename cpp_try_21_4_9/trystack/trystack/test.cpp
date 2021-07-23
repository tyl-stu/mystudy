#include<iostream>
using namespace std;
#include<stack>
#include<vector>
#include<list>
#include<queue>

//void test()
//{
//	stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//	cout << st.size() << endl;
//	while (!st.empty())
//	{
//		cout << st.top() << " ";//显示栈顶元素
//		st.pop();
//	}
//	cout << endl;
//	cout << st.size() << endl;
//
//	string a = "10";
//	cout << stoi(a) << endl;
//}

/* 模拟实现栈 stack */
/* 一种实现：封装 vector */
//template <class T>
//class Stack
//{
//	//一种实现：封装 vector
//public:
//
//	void push(const T& val)
//	{
//		_st.push_back(val);
//	}
//	void pop()
//	{
//		_st.pop_back();
//	}
//	T& top()
//	{
//		return _st.back();
//	}
//	size_t size() const
//	{
//		return _st.size();
//	}
//	bool empty() const
//	{
//		return _st.empty();
//	}
//private:
//	vector<T> _st;
//};
//
/* 另一种实现：封装 list */
//template<class T>
//class Stack2
//{
//public:
//	void push(const T& val)
//	{
//		//_st.push_back(val);
//		_st.push_front(val);
//	}
//	void pop()
//	{
//		//_st.pop_back();
//		_st.pop_front();
//	}
//	T& top()
//	{
//		//return _st.back();
//		return _st.front();
//	}
//	size_t size() const
//	{
//		return _st.size();
//	}
//	bool empty() const
//	{
//		return _st.empty();
//	}
//private:
//	list<int> _st;
//};
//
//void test()
//{
//	stack<int> s;
//	s.push(1);
//	s.push(2);
//	s.push(3);
//	s.push(4);
//	cout << s.size() << endl;
//	while (!s.empty())
//	{
//		cout << s.top() << " ";//显示栈顶元素
//		s.pop();
//	}
//	cout << endl;
//	cout << s.size() << endl;
//
//	Stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//	cout << st.size() << endl;
//	while (!st.empty())
//	{
//		cout << st.top() << " ";//显示栈顶元素
//		st.pop();
//	}
//	cout << endl;
//	cout << st.size() << endl;
//
//	Stack2<int> st2;
//	st2.push(1);
//	st2.push(2);
//	st2.push(3);
//	st2.push(4);
//	cout << st2.size() << endl;
//	while (!st2.empty())
//	{
//		cout << st2.top() << " ";//显示栈顶元素
//		st2.pop();
//	}
//	cout << endl;
//	cout << st2.size() << endl;
//}

//void test()
//{
//	queue<int> q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//	cout << q.size() << endl;
//	while (!q.empty())
//	{
//		cout << q.front() << " ";
//		q.pop();
//	}cout << endl;
//	cout << q.size() << endl;
//}

/* 模拟实现栈 queue */
/* 一种实现：封装 list */
/* 因为vector没有push_front 或 pop_front ，所以就无法用vetor实现queue */
template<class T>
class Queue
{
public:
	//头插尾插皆可
	void push(const T& val)
	{
		//_q.push_back(val);
		_q.push_front(val);
	}
	void pop()
	{
		//_q.pop_front();//如果是头插就是尾删
		_q.pop_back();//如果是尾插就是头删
	}
	T& front()
	{
		//return _q.front();
		return _q.back();
	}
	bool empty() const
	{
		return _q.empty();
	}
	size_t size() const
	{
		return _q.size();
	}
private:
	list<T> _q;
};
void test()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout << q.size() << endl;
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}cout << endl;
	cout << q.size() << endl;

	Queue<int> q1;
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	cout << q1.size() << endl;
	while (!q1.empty())
	{
		cout << q1.front() << " ";
		q1.pop();
	}cout << endl;
	cout << q1.size() << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}