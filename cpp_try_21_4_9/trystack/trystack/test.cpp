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
//		cout << st.top() << " ";//��ʾջ��Ԫ��
//		st.pop();
//	}
//	cout << endl;
//	cout << st.size() << endl;
//
//	string a = "10";
//	cout << stoi(a) << endl;
//}

/* ģ��ʵ��ջ stack */
/* һ��ʵ�֣���װ vector */
//template <class T>
//class Stack
//{
//	//һ��ʵ�֣���װ vector
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
/* ��һ��ʵ�֣���װ list */
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
//		cout << s.top() << " ";//��ʾջ��Ԫ��
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
//		cout << st.top() << " ";//��ʾջ��Ԫ��
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
//		cout << st2.top() << " ";//��ʾջ��Ԫ��
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

/* ģ��ʵ��ջ queue */
/* һ��ʵ�֣���װ list */
/* ��Ϊvectorû��push_front �� pop_front �����Ծ��޷���vetorʵ��queue */
template<class T>
class Queue
{
public:
	//ͷ��β��Կ�
	void push(const T& val)
	{
		//_q.push_back(val);
		_q.push_front(val);
	}
	void pop()
	{
		//_q.pop_front();//�����ͷ�����βɾ
		_q.pop_back();//�����β�����ͷɾ
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