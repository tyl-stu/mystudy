#include<iostream>
using namespace std;
#include<deque>
#include<vector>
#include<list>
#include<functional>

/* stack和queue 模拟实现 */
//namespace bit
//{
//	template<class T, class Con = deque<T>>
//	class stack
//	{
//	public:
//		stack(){};
//
//		void push(const T& x)
//		{
//			_c.push_back(x);
//		}
//
//		void pop()
//		{
//			_c.pop_back();
//		}
//
//		T& top()
//		{
//			return _c.back();
//		}
//
//		const T& top()const
//		{
//			return _c.back();
//		}
//
//		size_t size()const
//		{
//			return _c.size();
//		}
//
//		bool empty()const
//		{
//			return _c.empty();
//		}
//
//	private:
//		Con _c;
//	};
//
//	template<class T, class Con = deque<T>>
//	class queue
//	{
//	public:
//
//		queue(){};
//
//		void push(const T& x)
//		{
//			_c.push_back(x);
//		}
//
//		void pop()
//		{
//			_c.pop_front();
//		}
//
//		T& back()
//		{
//			return _c.back();
//		}
//
//		const T& back()const
//		{
//			return _c.back();
//		}
//
//		T& front()
//		{
//			return _c.front();
//		}
//
//		const T& front()const
//		{
//			return _c.front();
//		}
//
//		size_t size()const
//		{
//			return _c.size();
//		}
//
//		bool empty()const
//		{
//			return _c.empty();
//		}
//
//	private:
//		Con _c;
//	};
//};
//
//void test()
//{
//	//bit::stack<int> st;
//	bit::stack<int, vector<int>> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//	cout << st.size() << endl;
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
//	}cout << endl;
//	cout << st.size() << endl;
//
//	//bit::queue<int> q;
//	//bit::queue<int, vector<int>> q;//会报错，因为没有pop_front()
//	bit::queue<int, list<int>> q;
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

/* priority_queue 模拟实现 */
namespace bit
{
	template<class T>
	struct greater // 实现大堆
	{
		bool operator()(const T& x, const T& y) const
		{
			return x > y;
		}
	};
	
	template<class T>
	struct less  //实现小堆
	{
		bool operator()(const T& x, const T& y) const
		{
			return x < y;
		}
	};

	template <class T, class Container = vector<T>, class Compare = less<T> >
	class priority_queue
	{
	public:
		priority_queue(){};

		//向下调整
		void shiftDown()
		{
			int parent = 0;
			int child = 2 * parent + 1;
			while (child < c.size())
			{
				if ((child + 1) < c.size() && comp(c[child], c[child + 1]))
					child++;
				if (comp(c[parent], c[child]))
				{
					swap(c[parent], c[child]);
					parent = child;
					child = parent * 2 + 1;
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
				if (comp(c[parent], c[child]))
				{
					swap(c[parent], c[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
					break;
			}
		}

		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
			:c(first,last)
		{
			shiftDown();
		}

		bool empty() const
		{
			return c.empty();
		}

		size_t size() const
		{
			return c.size();
		}

		const T& top() const
		{
			return c.front();
		}

		void push(const T& x)
		{
			c.push_back(x);
			shiftUp(c.size() - 1);
		}

		void pop()
		{
			swap(c[0], c[c.size() - 1]);
			c.pop_back(); 
			shiftDown();
		}

	private:
		Container c;
		Compare comp;
	};
};

void test()
{
	bit::priority_queue<int, vector<int>, bit::less<int>> p1;
	//bit::priority_queue<int> p1;
	p1.push(10);
	p1.push(2);
	p1.push(13);
	p1.push(9);
	cout << p1.size() << endl;
	while (!p1.empty())
	{
		cout << p1.top() << " ";
		p1.pop();
	}cout << endl;
	cout << p1.size() << endl;

	bit::priority_queue<int, vector<int>, bit::greater<int>> p2;
	//bit::priority_queue<int> p2;
	p2.push(10);
	p2.push(2);
	p2.push(13);
	p2.push(9);
	cout << p2.size() << endl;
	while (!p2.empty())
	{
		cout << p2.top() << " ";
		p2.pop();
	}cout << endl;
	cout << p2.size() << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}