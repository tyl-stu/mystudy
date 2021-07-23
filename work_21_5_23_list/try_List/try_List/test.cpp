#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>

namespace bite
{
	// List的节点类
	template<class T>
	struct ListNode
	{
		ListNode(const T& val = T())
		{
			_val = val;
			_pPre = nullptr;
			_pNext = nullptr;
		}
		ListNode<T>* _pPre;
		ListNode<T>* _pNext;
		T _val;
	};

	//List的迭代器类
	template<class T, class Ref, class Ptr>
	class ListIterator
	{
		typedef ListNode<T>* PNode;
		typedef ListIterator<T, Ref, Ptr> Self;
		
	public:
		ListIterator(PNode pNode = nullptr)
		{
			_pNode = pNode;
		}
		ListIterator(const Self& l)
		{
			_pNode = l._pNode;
		}

		//T& operator*()
		Ref operator*()
		{
			return _pNode->_val;
		}
		//T* operator->()
		Ptr operator->()
		{
			return &_pNode->_val;
		}

		Self& operator++() // 前置++
		{
			_pNode = _pNode->_pNext;
			return *this;
		}
		Self& operator++(int) //后置++
		{
			Self now(_pNode);
			_pNode = _pNode->_pNext;
			return now;
		}
		Self& operator--() //前置 -- 
		{
			_pNode = _pNode->_pPre;
			return *this;
		}
		Self& operator--(int) //后置--
		{
			Self now(_pNode);
			_pNode = _pNode->_pPre;
			return now;
		}

		bool operator!=(const Self& l)
		{
			return _pNode != l._pNode;
		}
		bool operator==(const Self& l)
		{
			return _pNode == l._pNode;
		}

	//private:
		PNode _pNode;
	};

	//list类
	template<class T>
	class list
	{
	public:
		typedef ListNode<T> Node;
		typedef Node* PNode;
	
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;

		///////////////////////////////////////////////////////////////
		// List的构造
		list()
			:_pHead(new Node())
		{
			//实现循环结构
			_pHead->_pNext = _pHead->_pPre = _pHead;
		}
		list(int n, const T& value = T())
			:_pHead(new Node())
		{
			_pHead->_pNext = _pHead->_pPre = _pHead;
			for (int i = 0; i < n; i++)
			{
				push_back(value);
			}
		}
		template <class Iterator>
		list(Iterator first, Iterator last)
			:_pHead(new Node())
		{
			_pHead->_pNext = _pHead->_pPre = _pHead;
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		list(const list<T>& l)
			:_pHead(new Node())
		{
			_pHead->_pNext = _pHead->_pPre = _pHead;
			Node* cur = l._pHead->_pNext;
			while (cur != l._pHead)
			{
				/*Node* newNode = new Node(cur->_val);
				Node* prev = _pHead->_pPre;

				prev->_pNext = newNode;
				newNode->_pPre = prev;

				newNode->_pNext = _pHead;
				_pHead->_pPre = newNode;
				*/
				push_back(cur->_val);
				cur = cur->_pNext;
			}
		}

		list<T>& operator=(const list<T> l)
		{
			_pHead->_pNext = _pHead->_pPre = _pHead;
			for (auto& e : l)
			{
				push_back(e);
			}
		}

		~list()
		{
			if (_pHead)
			{
				Node* node = _pHead->_pNext;
				while (node != _pHead)
				{
					Node* next = node->_pNext;
					delete node;
					node = next;
				}
				delete _pHead;
				_pHead = nullptr;
			}
		}

		/////////////////////////////////////////////////////////////////
		// List Iterator
		iterator begin()
		{
			iterator it(_pHead->_pNext);
			return it;
		}
		iterator end()
		{
			return iterator(_pHead);
		}
		const_iterator begin() const
		{
			/*const_iterator cit(_pHead->_pNext);
			return cit;*/
			return const_iterator(_pHead->_pNext);
		}
		const_iterator end() const
		{
			return const_iterator(_pHead);
		}

		/////////////////////////////////////////////////////////////////
		// List Capacity
		size_t size()const
		{
			size_t sz = 0;
			Node* cur = _pHead->_pNext;
			while (cur != _pHead)
			{
				sz++;
				cur = cur->_pNext;
			}
			return sz;
		}
		bool empty()const
		{
			return _pHead->_pNext == _pHead;
		}

		//////////////////////////////////////////////////////////////
		// List Access
		T& front()
		{
			/*Node* node = _pHead->_pNext;
			return node->_val;*/
			/*iterator it = begin();
			return *it;*/
			return *begin();
		}
		const T& front()const
		{
			return *begin();
		}
		T& back()
		{
			/*Node* node = _pHead->_pPre;
			return node->_val;*/
			/*iterator it = end();
			--it;
			return *it;*/
			return *(--end());
		}
		const T& back()const
		{
			return *(--end());
		}

		//////////////////////////////////////////////////////////////
		//// List Modify
		void push_back(const T& val)
		{ 
			insert(end(), val);
			/*Node* newNode = new Node(val);
			Node* prev = _pHead->_pPre;

			prev->_pNext = newNode;
			newNode->_pPre = prev;

			newNode->_pNext = _pHead;
			_pHead->_pPre = newNode;*/

		}
		void pop_back()
		{ 
			erase(--end()); 
			/*Node* cur = _pHead->_pPre;
			Node* prev = cur->_pPre;

			prev->_pNext = _pHead;
			_pHead->_pPre = prev;
			delete cur;*/
		}
		void push_front(const T& val){ insert(begin(), val); }
		void pop_front(){ erase(begin()); }

		//// 在pos位置前插入值为val的节点
		iterator insert(iterator pos, const T& val)
		{
			Node* cur = pos._pNode;
			Node* prev = cur->_pPre;
			Node* newNode = new Node(val);

			prev->_pNext = newNode;
			newNode->_pPre = prev;

			newNode->_pNext = cur;
			cur->_pPre = newNode;
			return iterator(newNode);
		}

		//// 删除pos位置的节点，返回该节点的下一个位置
		iterator erase(iterator pos)
		{
			Node* cur = pos._pNode;
			Node* prev = cur->_pPre;
			Node* next = cur->_pNext;

			prev->_pNext = next;
			next->_pPre = prev;
			delete cur;
			return iterator(next);
		}
		void clear()
		{
			if (_pHead)
			{
				Node* node = _pHead->_pNext;
				while (node != _pHead)
				{
					Node* next = node->_pNext;
					delete node;
					node = next;
				}
				delete _pHead;
				_pHead = nullptr;
			}
			CreateHead();
		}
		void swap(list<T>& l)
		{
			list<T> t1(*this);
			list<T> t2(l);
			clear();
			l.clear();
			for (auto& n1 : t2)
				push_back(n1);
			for (auto& n2 : t1)
				l.push_back(n2);
		}

	private:
		void CreateHead() //创建头节点
		{
			_pHead = new Node();
			_pHead->_pPre = _pHead;
			_pHead->_pNext = _pHead;
		}
		PNode _pHead; // 头节点

	};

};

template<class T>
void printList(const bite::list<T>& lst)
{
	bite::list<T>::const_iterator it = lst.begin();
	while (it != lst.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

void test()
{
	cout << "try lst :" << endl;
	bite::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	printList(lst);//1 2 3
	lst.push_front(9);
	lst.push_front(8);
	lst.push_front(7);
	printList(lst);//7 8 9 1 2 3
	lst.pop_front();
	lst.pop_front();
	printList(lst);//9 1 2 3
	lst.pop_back();
	lst.pop_back();
	printList(lst);//9 1

	cout << endl << "try lst2 : " << endl;
	bite::list<char> lst2;
	cout << lst2.size() << " empty: " << lst2.empty() << endl;

	cout << endl << "try lst3 : " << endl;
	bite::list<int> lst3(3, 6);
	printList(lst3);
	cout << lst3.size() << " empty: " << lst3.empty() << endl;

	cout << endl << "try lst4 : " << endl;
	string s = "12345";
	bite::list<char> lst4(s.begin(), s.end());
	printList(lst4);
	cout << lst4.size() << " empty: " << lst4.empty() 
		<< " front: " << lst4.front() << " back: " <<lst4.back() << endl;
	lst4.pop_back();
	lst4.pop_back();
	printList(lst4);
	cout << lst4.size() << " empty: " << lst4.empty()
		<< " front: " << lst4.front() << " back: " << lst4.back() << endl;
	lst4.clear();
	cout << "lst4.clear() : ";
	printList(lst4);

	cout << endl << "try lst5 & lst6 : " << endl;
	bite::list<int> lst5(lst3);
	printList(lst5);
	bite::list<int> lst6 = lst5;
	printList(lst6);

	cout << endl << "try lst & lst6 : " << endl;
	lst6.swap(lst);
	cout << "lst6.swap(lst): " << endl;
	cout << "lst: ";
	printList(lst);
	cout << "lst6: ";
	printList(lst6);
}

int main()
{
	test();
	system("pause");
	return 0;
}
